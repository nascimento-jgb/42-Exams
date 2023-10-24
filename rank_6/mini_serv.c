
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <arpa/inet.h>

typedef struct client {
	int	id;
	int	fd;
}	t_client;

t_client	clients[1024];
char		buffer[1000000], message[1000000];
int			id, maxFd, serverSocket;
fd_set		mainSet, readSet, writeSet;

void	fatalError(void)
{
	write(2, "Fatal error\n", 12);
	exit(1);
}

int	initServer(int port)
{
	struct sockaddr_in	serverAddress;

	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	serverAddress.sin_port = port;

	if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0) < 0)
		|| bind(serverSocket, (const struct sockaddr*)&serverAddress, sizeof(serverAddress) < 0)
		|| listen(serverSocket, 128) < 0)
		fatalError();

	return (serverSocket);
}

void	addClient() {
	int i = 0;

	while (clients[i].fd > 0 && i < 1024)
		i++;

	struct sockaddr_in	clientAddress;
	socklen_t	len;

	if ((clients[i].fd = accept(serverSocket, (struct sockaddr*)&clientAddress, len)) < 0)
		fatalError();

	FD_SET(clients[i].fd, &mainSet);
	clients[i].id = id++;
	if (clients[i].fd > maxFd)
		maxFd = clients[i].fd;
	sprintf(message, "server: client %d just arrived\n", clients[i].id);
	broadcastAll(clients[i].id);
}

void	broadcastAll(int idFrom)
{
	for (int i = 0; i < id; i++)
		if (clients[i].id != idFrom && FD_ISSET(clients[i].fd, &writeSet))
			send(clients[i].fd, message, strlen(message), 0);
	bzero(message, sizeof(message));
}

void	sendMessage(int idFrom)
{
	int i = 0, j = 0;
	int len = strlen(buffer);
	char temp[100000] = {0};

	while (i < len)
	{
		temp[j++] = buffer[i];
		if (buffer[i++] == '\n')
		{
			sprintf(message + strlen(message), "client %d: %s", idFrom, temp);
			bzero(temp, sizeof(temp));
			j = 0;
		}
	}
	broadcastAll(idFrom);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (write(2, "Wrong number of arguments\n", 26) && 1);

	maxFd = serverSocket = initServer(atoi(argv[1]));
	FD_ZERO(&mainSet);
	FD_SET(serverSocket, &mainSet);

	while (1)
	{
		readSet = writeSet = mainSet;
		if (select(maxFd + 1, &readSet, &writeSet, NULL, NULL) < 0)
			fatalError();
		if (FD_ISSET(serverSocket, &mainSet))
			addClient();
		for (int i = 0; i < id; i++)
		{
			if (clients[i].fd < serverSocket || !FD_ISSET(clients[i].fd, &readSet))
				continue;

			int readBytes = 1;
			bzero(buffer, sizeof(buffer));
			while (readBytes == 1)
			{
				readBytes = recv(clients[i].fd, buffer + strlen(buffer), 1, 0);
				if (buffer[strelen(buffer) - 1] == '\n')
					break;
			}
			if (readBytes == 0)
			{
				sprintf(message, "server: client %d just left\n", clients[i].id);
				broadcastAll(clients[i].id);
				close(clients[i].fd);
				FD_CLR(clients[i].fd, &mainSet);
				clients[i].id = -1;
				clients[i].fd = -1;
			}
			else if (readBytes)
				sendMessage(clients[i].id);
		}
	}
	return (0);
}
