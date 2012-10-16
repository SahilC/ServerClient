#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
	int sock,connct,x;
	char *ch;
	struct sockaddr_in addr;
	sock= socket(AF_INET,SOCK_STREAM,0);
	addr.sin_family=AF_INET;
	addr.sin_addr.s_addr=htonl(INADDR_ANY); //Accept any IP address connection
	addr.sin_port=htons(29008);
	bind(sock,(struct sockaddr *)&addr,sizeof(addr)); //typecasting sockaddr_in to sockaddr	
	listen(sock,1);
	while(1)
	{
		fflush(stdout);
		connct=accept(sock,(struct sockaddr *)NULL,NULL); //second arg specifies accept any IP of any size(3rd arg)
		while(ch!="exit")
		{
			read(connct,&x,1);
			ch=(char*)malloc(x*sizeof(char));
			read(connct,ch,x);
			printf("He says:%s\nYou say ",ch);
			free(ch);
			ch=(char*)malloc(20*sizeof(char));
			scanf("%s",ch);
			printf("\n");
			x=strlen(ch);
			write(connct,&x,1);
			write(connct,ch,x);
			free(ch);
		}
		close(connct);	
	}
	return 0;
}
