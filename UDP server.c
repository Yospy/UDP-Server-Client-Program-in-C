#include<unistd.h>
#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>


int main(){

   int server_fd;
   server_fd = socket(AF_INET, SOCK_DGRAM, 0);
    
   char rec_data[100], send_data[100];    

   struct sockaddr_in server_addr,client_addr;
   int clientsize = sizeof(client_addr);
   server_addr.sin_family = AF_INET;
   server_addr.sin_port = htons(50005);
   server_addr.sin_addr.s_addr = inet_addr("192.168.125.181");

   bind(server_fd,(struct sockaddr *)&server_addr, sizeof(server_addr));

   recvfrom(server_fd, rec_data, sizeof(rec_data), 0, (struct sockaddr*)&client_addr, &clientsize);


   printf("\n%s", rec_data);

   printf("Enter you data:");
   scanf("%s", send_data);

   sendto(server_fd, send_data, sizeof(send_data),0,(struct sockaddr *)&client_addr, clientsize);

   
   
   















}
