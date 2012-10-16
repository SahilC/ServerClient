#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int sock;
	struct sockaddr_in addr;
	sock=socket(AF_INET,SOCK_STREAM,0);
	addr.sin_family=AF_INET;
	addr.sin_addr.s_addr=inet_addr("127.0.0.1"); //switch with the address where your server is running
	addr.sin_port=htons(29008);
	connect(sock,(struct sockaddr *)&addr,sizeof(addr));
	char *ch;
	int x=20;
	while(ch!="exit")
	{
		ch=(char*)malloc(20*sizeof(char));
		printf("You say ");
		scanf("%s",ch);
		printf("\n");
		x=strlen(ch);
		write(sock,&x,1);
		write(sock,ch,x);
		free(ch);
		ch=(char*)malloc(x*sizeof(char));
		read(sock,&x,1);
	  	read(sock,ch,x);
		printf("He says:%s\n",ch);
		free(ch);	
	}
	close(sock);
	return 0;
}
