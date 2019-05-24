#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

//Thanks to Richard Zhan for the assistance w/sockets

int id;

static void sighandler(int signo){
	if (signo == SIGINT){
		if (getpid() != id){
			kill(getpid(),SIGINT);
		}
		exit(-1);
	}
}

int main(int argc, char**argv){
  int * client_list = (int *)malloc(30 * sizeof(int));
  int c = 0;
  id = getpid();
  signal(SIGINT,sighandler);
  int socket_id, socket_client;
  int musicfd1, musicfd2, musicfd3, musicfd4;
  char buffer[256];
  int b;
  socklen_t i;
  int x = 0;
  pid_t childpid;
  char clientAddr[100];
  char name1[100] = "sounds/";
  char name2[100] = "sounds/";
  char name3[100] = "sounds/";
  char name4[100] = "sounds/";
 
  if (argc < 2) {  
    printf("\nusage: ./conductor <name of score>\n");  
    exit(1);    
  } 
  
  char *piece = argv[1];

  strcat (name1, piece);
  strcat (name1, "1");
  musicfd1 = open(name1, O_RDONLY);
  //printf ("%s\n\n", name1);

  if (musicfd1 < 0) {
    printf ("\nthis piece does not exist in our library, please choose another piece\n");
    exit(1);
  }
  
  strcat (name2, piece);
  strcat (name2, "2");
  strcat (name3, piece);
  strcat (name3, "3");
  strcat (name4, piece);
  strcat (name4, "4");

  //printf ("%d\n", musicfd1);
  printf ("Playing: %s\n\n", piece);
  
  socket_id = socket(AF_INET,SOCK_STREAM,0);
  if (socket_id < 0) {
    printf ("error creating socket");
    exit(1);
  }
  //printf ("socket created\n");
	
  struct sockaddr_in listener, cl_listener;
  memset(&listener, 0, sizeof (listener));
  listener.sin_family = AF_INET;
  listener.sin_port = htons(5000); //select a port (htons puts it in little Endian)
  listener.sin_addr.s_addr = INADDR_ANY; //select can use
  
  b = bind(socket_id, (struct sockaddr *)&listener, sizeof(listener));
  
  if (b < 0) {
    printf ("error binding\n");
    exit(1);
  }
  //printf ("bound\n");
  
  listen(socket_id,1); //listens
  //printf("Listening...\n\n");
  

  musicfd2 = open(name2, O_RDONLY);
  musicfd3 = open(name3, O_RDONLY);
  musicfd4 = open(name4, O_RDONLY);
  char music1[2048];
  char music2[2048];
  char music3[2048];
  char music4[2048];
  read(musicfd1, music1, 2048);
  read(musicfd2, music2, 2048);
  read(musicfd3, music3, 2048);
  read(musicfd4, music4, 2048);
  close(musicfd1);
  close(musicfd2);
  close(musicfd3);
  close(musicfd4);
  
  printf("Music Loaded...\n\nWaiting for performers...\n\n");
  //printf("Enter 'start' when all performers have connected\n");
  
  while(1) {
    //socket_client = accept(socket_id, NULL,NULL); //creates a new socket to handle this client
    i = sizeof (cl_listener);
    socket_client = accept (socket_id, (struct sockaddr *)&cl_listener, &i);
    if (socket_client < 0) {
      printf ("error accepting connection");
      exit(1);
    }

    client_list[c] = socket_client;
    //printf("%d %d\n", client_list[c], socket_client);
    c++;
    printf("Accepted: %d\n", c);
    inet_ntop (AF_INET, &(cl_listener.sin_addr), clientAddr, 100);
    
    

    //if ((childpid = fork()) == 0) {
    //  close (socket_id);
    
    //char input[256];
    //printf("> ");
    //fgets(input, sizeof(input), stdin);
    //input[strlen(input) - 1] = 0;
    //if (strcmp("start", input) == 0)
    //  break;
    //NUMBER OF PERFORMERS!!!!!
    if (c == 4) {
      break;
    }
  }
  printf("\nAll performers connected, sending music now...\n");
	for (x = 0; x < c; x++) {
	  if (x == 0) {
	    //printf("%d\n", client_list[x]);
	    write(client_list[x], music1, 256);
	  }
	  else if (x == 1) {
	    //printf("%d\n", client_list[x]);
	    write(client_list[x], music2, 256);
	  }
	  else if (x == 2) {
	    //printf("%d\n", client_list[x]);
	    write(client_list[x], music3, 256);
	  }
	  else if (x == 3) {
	    //printf("%d\n", client_list[x]);
	    write(client_list[x], music4, 256);
	  }
	}
	printf("Music sent, would you like to start? (yes/no)\n");
	while (1) {
		char input[256];
		int x;
		printf("> ");
		fgets(input, sizeof(input), stdin);
		input[strlen(input) - 1] = 0;
		if (strcmp(input, "yes") == 0) {
			for (x = 0; x < c; x++) {
				write(client_list[x], input, 256);
			}
		//need end case here
			exit(0);
		}
		else if (strcmp(input, "no") == 0) {
			printf("Ending the performance now...\n" );
			for (x = 0; x < c; x++) {
				write(client_list[x], input, 256);
			}
			for (x = 0; x < c; x++) {
				close(client_list[x]);
			}
			close(socket_id);
			exit(-1);
		}
		else {
			printf("Command not recognized\n");
		}
	}
	for (x = 0; x < c; x++) {
		close(client_list[x]);
	}
	close(socket_id);


	// 	if (fork() == 0) {
	// 		close(socket_id);
	// 		write(socket_client, music, strlen(music));
	// 		printf("Music sent\n");
	// 		close(socket_client);
	// 		printf("Client died\n");
	// 		exit(-1);
	// 	}
	// 	char input[256];
	// 	int x;
	// 	printf("> ");
	// 	fgets(input, sizeof(input), stdin);
	// 	input[strlen(input) - 1] = 0;
	// 	if (strcmp("play", input) == 0) {
	// 		for (x = 0; x < c; x++) {
	// 			write(socket_client, input, 256);
	// 		}
	// 	}
	// 	else if (strcmp("exit", input) == 0) {
	// 		for (x = 0; x < c; x++) {
	// 			write(socket_client, input, 256);
	// 		}
	// 		exit(-1);
	// 	}
	// 	else {
	// 		printf("Command not recognized\n");
	// 	}
	// }    
	//write(socket_client,"hello",6);
	return 0;
}
