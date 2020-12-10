
 #include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define MSG_SIZE 80
int main()

{
    int filedes;
    int cnt;
   int x;

    // open fifo file

    if((filedes = open("./fifo", O_WRONLY)) < 0){

        printf("fail to call open()\n");

        exit(1);

    }
    while(1){
   
	scanf("%d",&x);

        if(write(filedes, &x, sizeof(int))==-1){
            printf("fail to call write()\n");
            exit(1);

        }

        sleep(1);

    }

}
