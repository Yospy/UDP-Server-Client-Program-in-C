#include<unistd.h>
#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>


int main(){
       
   int client_fd;
   client_fd = socket(AF_INET, SOCK_DGRAM, 0);

   char send_data[100], recv_data[100];
 
   struct sockaddr_in server_addr;
   int serversize = sizeof(server_addr);
   server_addr.sin_family = AF_INET;
   server_addr.sin_port = htons(50005);
   server_addr.sin_addr.s_addr = inet_addr("192.168.125.181");


   printf("Enter the senders data:");
   scanf("%s", send_data);

   sendto(client_fd,send_data,sizeof(send_data),0,(struct sockaddr*)&server_addr,sizeof (server_addr));


   recvfrom(client_fd, recv_data, sizeof(recv_data),0,(struct sockaddr*)&server_addr,&serversize);


   printf("%s", recv_data);



}
