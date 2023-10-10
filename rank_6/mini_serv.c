#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_CLIENTS 64
#define BUFFER_SIZE 1024

//Allowed functions: write, close, select, socket, accept, listen, send, recv, bind,
//strstr, malloc, realloc, free, calloc, bzero, atoi, sprintf, strlen, exit, strcpy, strcat, memset

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(STDERR_FILENO, "Wrong number of arguments\n", 27);
		exit(1);
	}

	int		clientSockets[MAX_CLIENTS];
	int		serverSocket;
	int		maxSocket;
	int		nextId = 0;
	char	buffer[BUFFER_SIZE];
	struct	sockaddr_in	serverAddress = {0};
	fd_set	ioSet, mainSet;

	//Create server socket
	if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		write(STDERR_FILENO, "Fatal error\n", 12);
		exit(1);
	}

	//Setup server docket address
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	serverAddress.sin_port = htons(atoi(argv[1]));

	//Bind
	if (bind(serverSocket, (const struct sockaddr *)&serverAddress, sizeof(serverAddress)) != 0) {
		write(STDERR_FILENO, "Fatal error\n", 12);
		exit(1);
	}

	//Listen
	if (listen(serverSocket, MAX_CLIENTS) < 0) {
		write(STDERR_FILENO, "Fatal error\n", 12);
		exit(1);
	}

	printf("Server running on port %d\n", atoi(argv[1]));

	//Initialize set
	FD_ZERO(&mainSet);
	FD_SET(serverSocket, &mainSet);
	maxSocket = serverSocket;

	while (1)
	{
		//Copy sets and apply select
		ioSet = mainSet;
		if (select(maxSocket + 1, &ioSet, NULL, NULL, NULL) < 0) {
			write(STDERR_FILENO, "Fatal error\n", 12);
			exit(1);
		}

		for (int socketId = 0; socketId <= maxSocket; socketId++)
		{
			if (FD_ISSET(socketId, &ioSet))
			{
				if (socketId == maxSocket) //new connection
				{
					int newClient  = accept(serverSocket, NULL, NULL);
					if (newClient < 0) {
						write(STDERR_FILENO, "Fatal error\n", 12);
						exit(1);
					}

					//include new client and update max socket
					FD_SET(newClient, &mainSet);
					maxSocket = (newClient > maxSocket) ? newClient : maxSocket;

					//Broadcast message and update client sockets array
					sprintf(buffer, "server: client %d just arrived\n", socketId);
					send(newClient, buffer, strlen(buffer), 0);
					clientSockets[nextId++] = newClient;

				} else {
					int bytesRead = recv(socketId, buffer, sizeof(buffer) - 1, 0);

					if (bytesRead <= 0) {
						//disconnect user, clean it and broadcast the message
						sprintf(buffer, "server: client %d just left\n", socketId);

						for (int i = 0; i < nextId; i++)
							if (clientSockets[i] != socketId)
								send(clientSockets[i], buffer, strlen(buffer), 0);

						close(socketId);
						FD_CLR(socketId, &mainSet);
					} else {
						//null terminate and broadcast the message
						buffer[bytesRead] = '\0';
						sprintf(buffer, "server: client %d just left\n", socketId);

						for (int i = 0; i < nextId; i++)
							if (clientSockets[i] != socketId)
								send(clientSockets[i], buffer, strlen(buffer), 0);
					}
				}
			}
		}
	}
	return (0);
}
