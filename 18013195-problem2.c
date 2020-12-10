#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void handler(int signo);

int main(int argc, char **argv)
{
  int i = 0;
	sigset(SIGTSTP, handler);
  sigset(SIGINT, (void *)handler);
//signal 함수로  SIGINT대해 shandler 함수를 실행한다
  while(1)
  {
    printf("Waiting for signal to be received! Count:%d\n", i);
    sleep(2);
    i++;
  }//반복문으로 i를 1씩늘리며 출력한다
}

void handler(int signo)
{
  psignal(signo, "Received Signal:");
	//해당하는 시그널 번호를 출력한다
}
