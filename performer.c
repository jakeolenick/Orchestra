#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include "sounds/sounds.c"
int socket_id;

int playmusic(char * m);

static void sighandler(int signo){
  if (signo == SIGINT){
    write(socket_id,"exit",strlen("exit"));
    exit(-1);
  }
}

int main(int argc, char **argv){
  
  signal(SIGINT,sighandler);
  char buffer[256];
  int i,b;
  
  socket_id = socket(AF_INET,SOCK_STREAM,0);

  struct sockaddr_in sock;
  sock.sin_family = AF_INET;
  sock.sin_port = htons(5000);
  //printf("sock\n");
  char ipv4[256];
  if (argc == 1){
    //ipv4 = "127.0.0.1";
    char * ip = "127.0.0.1";
    strcpy (ipv4,ip);
  }
  else{
    //ipv4 = argv[1];
    //printf("%s\n", argv[1]);
    strcpy(ipv4, argv[1]);
  }
  //printf("%s\n", ipv4);
  inet_aton(ipv4,&(sock.sin_addr)); //using localhost
  bind(socket_id,(struct sockaddr *)&sock,sizeof(sock));
  //printf("bind\n");
  i = connect(socket_id,(struct sockaddr *)&sock,sizeof(sock)); //connect
  //printf("connect: %d\n", i);
  printf ("\nconnected. please wait for the rest of the performers\n");
  //printf("Strerror: %s\n", strerror(errno));

  //accept the music from conductor
  int x;
  char music[2048];
  x = read(socket_id, music, sizeof(music));
  //printf("%d\n", x);
  
  while(1){
    //int x;
    //char music[2048];
    //x = read(socket_id, music, sizeof(music));
    // printf("%d\n", x);
    //wait for play command
    char command[256];
    read(socket_id, command, sizeof(command));
    if (strcmp(command, "yes") == 0) {
      playmusic(music);
      close(socket_id);
      exit(-1);
    }
    if (strcmp(command, "no") == 0) {
      printf("Exiting...\n");
      close(socket_id);
      exit(-1);
    }
    if (strcmp(command, "exit") == 0) {
      printf("Exiting...\n");
      exit(-1);
    }
  }
  close(socket_id);
  return 0;
}

//we have the music string, now just interpret it here
int playmusic(char * m) {

  ao_device *device;  
  ao_sample_format format;  
  int default_driver;  
  
  /* -- Initialize -- */
  ao_initialize();  
  /* -- Setup for default driver -- */  
  default_driver = ao_default_driver_id();  
  memset(&format, 0, sizeof(format));  
  format.bits = 16;  
  format.channels = 2;  
  format.rate = 44100;  
  format.byte_format = AO_FMT_LITTLE;  
  /* -- Open driver -- */  
  device = ao_open_live(default_driver, &format, NULL /* no options */);  
  if (device == NULL) {  
    fprintf(stderr, "Error opening device.\n");
    return 1;
  }  


  int f = fork();
  if (!f){
    execlp("cat","cat","sounds/chart",NULL);
    exit(0);
  }
  else
    wait(0);

  char c1 = m[0];
  char c2 = '1';
  char c3 = '2';
  char c4 = '3';
  char c5 = '4';
  char part[8] = "";
  if ( c1 == c2 ) {
    printf ("Part: sine1\n");
    strcat(part, "sine1");
  }
  else if ( c1 == c3) {
    printf ("Part: sine2\n");
    strcat(part, "sine2");
  }
  else if ( c1 == c4 ) {
    printf ("Part: square1\n");
    strcat (part, "square1");
  }
  else if (c1 == c5) {
    printf ("Part: square2\n");
    strcat (part, "square2");
  }
  else{
    printf("Valid instrument choices are:\nsine1\nsine2\nsquare1\nsquare2\n");
  }
  int i;
  printf("part is: (%s)\n",part);
  for (i = 2; i < strlen(m); i = i + 2) {
    printf("Note played: %c\n", m[i]);
    playnote(part,m[i],device,format);
  }
  printf("Thanks for playing!\n"); 


  ao_close(device);  
  ao_shutdown(); 
  return 0;
}
