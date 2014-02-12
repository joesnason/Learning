#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>
#include <syslog.h>

int main(int argc, char *argv[]){

	int socko;
	//struct sockaddr_in addr;
	struct sockaddr_in client;
	socklen_t len;
	int sock;
	struct addrinfo hints, *res;
	int err;
	int fdw, fd;
	int n, ret;
	char mode[5];
	char buf[65536];

	openlog("server", LOG_CONS | LOG_PID, 0);




	if (argc != 2) {
		fprintf(stderr, "Usage : %s outputfilename\n", argv[0]);
		return 1;		
	}

	// for server side write file from client 
	fdw = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fdw < 0 ) {
		perror("open");
		return 1;
	}

	// read file for client to download
	//fd = open("current.png", O_RDONLY);
	//if (fd < 0) {
	//	perror("open");
	//	return 1;
	//}


	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_flags = AI_PASSIVE;
	hints.ai_socktype = SOCK_STREAM;
	err = getaddrinfo(NULL, "12345", &hints, &res);

	if(err != 0) {
		printf("getaddrinfo : %s\n", gai_strerror(err));
		return 1;
	}

	// make socket
	socko = socket(res->ai_family, res->ai_socktype, 0);
	if (socko < 0) {
		perror("socket");
		return 1;
	}


	if (bind(socko, res->ai_addr, res->ai_addrlen) != 0) {
		perror("bind");
		return 1;
	}

	freeaddrinfo(res);

	// listen the connect from client
	listen(socko, 5);


	len = sizeof(client);
	sock = accept(socko, (struct sockaddr *) &client, &len);
	printf("connecting");
	syslog(LOG_INFO, "connect");

	if(sock < 0) {
		perror("accept");
		return 1;
	}


	// get commnad to check client upload or download
	//read(sock,mode,sizeof(mode));
	//printf("%s\n", mode);
	// read file and write socket
	//if (mode[0] == 'r'){
	//	while ((n = read(fd, buf, sizeof(buf))) >0 ) {
	//		ret = write(sock, buf, n);
	//		if (ret < 1) {
	//			perror("write");
	//			break;
	//		}
	//	}
	//} else {
		// for client to upload file
		while ((n = read(sock,buf, sizeof(buf))) > 0) {
			ret = write(fdw, buf, n);
			if(ret < 1){
				perror("wirte");
				break;
			}
		}

	//}

	close(sock);


	//close(socko);

	return 0;
}
