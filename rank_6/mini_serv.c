#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct s_clients
{
    int        id;
    int        client_socket;
    char    *buffer;
    char    *message;
}    t_clients;

char    broadcasted[30000];
char    general_buffer[4096];

int extract_message(char **buf, char **msg)
{
    char    *newbuf;
    int    i;

    *msg = 0;
    if (*buf == 0)
        return (0);
    i = 0;
    while ((*buf)[i])
    {
        if ((*buf)[i] == '\n')
        {
            newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
            if (newbuf == 0)
                return (-1);
            strcpy(newbuf, *buf + i + 1);
            *msg = *buf;
            (*msg)[i + 1] = 0;
            *buf = newbuf;
            return (1);
        }
        i++;
    }
    return (0);
}

char *str_join(char *buf, char *add)
{
    char    *newbuf;
    int        len;

    if (buf == 0)
        len = 0;
    else
        len = strlen(buf);
    newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
    if (newbuf == 0)
    {
        free(buf);
        return (0);
    }
    newbuf[0] = 0;
    if (buf != 0)
        strcat(newbuf, buf);
    free(buf);
    strcat(newbuf, add);
    return (newbuf);
}

int    find_space(t_clients *clients)
{
    for (int i = 0; i < 128; i++)
    {
        if (clients[i].id == -1)
            return (i);
    }
    return (-1);
}

int    find_client(t_clients *clients, int socket)
{
    for (int i = 0; i < 128; i++)
    {
        if (clients[i].client_socket == socket)
            return (i);
    }
    return (-1);
}

void    broadcast_message(t_clients *clients, int index_client, char *message)
{
    for (int i = 0; i < 128; i++)
    {
        if (i != index_client && clients[i].id != -1)
            send(clients[i].client_socket, message, strlen(message), 0);
    }
}

void    print_error(char *error, int server_socket)
{
    write(STDERR_FILENO, error, strlen(error));
    if (server_socket != 0)
        close(server_socket);
    exit(1);
}

void    free_clients(t_clients *clients)
{
    for (int i = 0; i < 128; i++)
    {
        if (clients[i].buffer)
            free(clients[i].buffer);
        clients[i].buffer = NULL;
        if (clients[i].message)
            free(clients[i].message);
        clients[i].buffer = NULL;
        if (clients[i].client_socket != 0)
            close(clients[i].client_socket);
    }
}

int main(int ac, char **av)
{
    int server_socket;
    int    client_socket;
    int    client_index;
    int    max_socket;
    int    bytes_read;
    int    next_id;
    int    flag;
    t_clients    clients[128];
    struct sockaddr_in servaddr;
    fd_set    ready_sockets;
    fd_set    active_sockets;

    next_id = 0;
    server_socket = 0;
    if (ac != 2)
        print_error("Wrong number of arguments\n", server_socket);
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1)
        print_error("Fatal error\n", 0);
    bzero(&servaddr, sizeof(servaddr));
    for (int i = 0; i < 128; i++)
    {
        bzero(&(clients[i]), sizeof(clients[i]));
        clients[i].id = -1;
    }
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(2130706433);
    servaddr.sin_port = htons(atoi(av[1]));
    if ((bind(server_socket, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
        print_error("Fatal error\n", server_socket);
    if (listen(server_socket, 128) != 0)
        print_error("Fatal error\n", server_socket);
    FD_ZERO(&active_sockets);
    FD_SET(server_socket, &active_sockets);
    max_socket = server_socket;
    while (1)
    {
        ready_sockets = active_sockets;
        if (select(max_socket + 1, &ready_sockets, NULL, NULL, NULL) == -1)
        {
            free_clients(clients);
            print_error("Fatal error\n", server_socket);
        }
        for (int socket_id = 0; socket_id <= max_socket; socket_id++)
        {
            if (FD_ISSET(socket_id, &ready_sockets))
            {
                if (socket_id == server_socket)
                {
                    client_index = 0;
                    client_socket = accept(server_socket, NULL, NULL);
                    if (client_socket == -1)
                    {
                        free_clients(clients);
                        print_error("Fatal error\n", server_socket);
                    }
                    FD_SET(client_socket, &active_sockets);
                    if (client_socket > max_socket)
                        max_socket = client_socket;
                    client_index = find_space(clients);
                    clients[client_index].id = next_id;
                    clients[client_index].client_socket = client_socket;
                    next_id++;
                    sprintf(broadcasted, "server: client %d just arrived\n", clients[client_index].id);
                    broadcast_message(clients, client_index, broadcasted);
                }
                else
                {
                    bytes_read = 0;
                    bzero(general_buffer, sizeof(general_buffer));
                    bytes_read = recv(socket_id, general_buffer, 4095, 0);
                    client_index = find_client(clients, socket_id);
                    if (bytes_read <= 0)
                    {
                        bzero(broadcasted, sizeof(broadcasted));
                        sprintf(broadcasted, "server: client %d just left\n", clients[client_index].id);
                        broadcast_message(clients, client_index, broadcasted);
                        if (clients[client_index].buffer)
                            free(clients[client_index].buffer);
                        clients[client_index].buffer = NULL;
                        if (clients[client_index].message)
                            free(clients[client_index].message);
                        clients[client_index].message = NULL;
                        clients[client_index].id = -1;
                        clients[client_index].client_socket = 0;
                        close(socket_id);
                        FD_CLR(socket_id, &active_sockets);
                    }
                    else
                    {
                        general_buffer[bytes_read] = '\0';
                        clients[client_index].buffer = str_join(clients[client_index].buffer, general_buffer);
                        if (!clients[client_index].buffer)
                        {
                            free_clients(clients);
                            print_error("Fatal error\n", server_socket);
                        }
                        while ((flag = extract_message(&(clients[client_index].buffer), &(clients[client_index].message))) != 0)
                        {
                            if (flag == -1)
                            {
                                free_clients(clients);
                                print_error("Fatal error\n", server_socket);
                            }
                            bzero(broadcasted, sizeof(broadcasted));
                            sprintf(broadcasted, "client %d: ", clients[client_index].id);
                            broadcast_message(clients, client_index, broadcasted);
                            broadcast_message(clients, client_index, clients[client_index].message);
                            free(clients[client_index].message);
                            clients[client_index].message = NULL;
                        }
                    }
                }
            }
        }
    }
    return (0);
}

