#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>


int main(int argc, char *argv[]) {

	/*struct sockaddr_in server;
	int sock;
	char buf[32];
	int n;
*/
	char *service = "12345";
	struct addrinfo hints, *reso, *res;
	int err;
	int sock;
	int fd;
	char buf[65536];
	int n, ret;

	if (argc != 3){
		fprintf(stderr, "Usage : %s hostname filename\n", argv[0]);
		return 1;
	}

	fd = open(argv[2], O_RDONLY);
	//fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd < 0) {
		perror("open");
		return 1;
	}


	memset(&hints, 0, sizeof(hints));
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_family = PF_UNSPEC;
	if ((err = getaddrinfo(argv[1],service, &hints, &reso)) != 0) {
		printf("error %d : %s\n", err, gai_strerror(err));
		return 1;
	}

	for (res = reso; res!=NULL; res= res->ai_next) {
		sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
		if (sock < 0){
			continue;
		}

		if (connect(sock, res->ai_addr, res->ai_addrlen) != 0) {
			close(sock);
			continue;
		}
		break;
	}

	freeaddrinfo(reso);

	if(res == NULL) {
		printf("failed\n");
		return 1;
	}

/*
	while ((n = read(fd, buf, sizeof(buf))) >0 ) {
		ret = write(sock, buf, n);
		if (ret < 1) {
			perror("write");
			break;
		}
	}
*/

	write(sock,"w",1);
/*
	

	while ((n = read(sock,buf, sizeof(buf))) > 0) {
		ret = write(fd, buf, n);
		if(ret < 1){
			perror("wirte");
			break;
		}
	}
*/

	while ((n = read(fd, buf, sizeof(buf))) >0 ) {
		ret = write(sock, buf, n);
		if (ret < 1) {
			perror("write");
			break;
		}
	}
	

	close(sock);

	return 0;
 /*
	// make socket 
	sock = socket(AF_INET, SOCK_STREAM, 0);


	// setup socket to connect server side
	server.sin_family = AF_INET;
	server.sin_port = htons(12345);

	inet_pton(AF_INET, "127.0.0.1", &server.sin_addr.s_addr);


	// do connection
	connect(sock, (struct sockaddr *) &server, sizeof(server));

	memset(buf, 0, sizeof(buf));

	n = read(sock, buf, sizeof(buf));

	printf("%d, %s\n", n, buf);


	close(sock);

	return 0;
*/
}