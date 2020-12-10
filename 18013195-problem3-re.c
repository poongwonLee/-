
 #include <fcntl.h>

#include <sys/stat.h>

#include <unistd.h>

#include <stdio.h>

#include <stdlib.h>



#define MSG_SIZE 80



int main()

{

    char msg[MSG_SIZE];

    int filedes;

    int nread, cnt;
	int x;



    if(mkfifo("./fifo",0666) == -1){

        printf("fail to call fifo()\n");

        exit(1);

    }



    if((filedes = open("./fifo", O_RDWR)) < 0){

        printf("fail to call fifo()\n");

        exit(1);

    }



    while(1){

        if((nread = read(filedes, &x, sizeof(int))) < 0 ){

            printf("fail to call read()\n");

            exit(1);

        }

       printf("%d+%d=%d",x,x,x+x);
    }

    unlink("./fifo");



    return 0;

}
