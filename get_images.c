#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "rdjpeg.h"

static int exec_prog(const char **argv)
{
    pid_t my_pid;
    int status, timeout /* unused ifdef WAIT_FOR_COMPLETION */;

    if (0 == (my_pid = fork())) {
            if (-1 == execve(argv[0], (char **)argv , NULL)) {
                    perror("child process execve failed [%m]");
                    exit(-1);
            }
    }

#ifdef WAIT_FOR_COMPLETION
    timeout = 1000;
    while (0 == waitpid(my_pid , &status , WNOHANG)) {
            if ( --timeout < 0 ) {
                    perror("timeout");
                    exit(-1);
            }
            sleep(1);
    }

    printf("%s WEXITSTATUS %d WIFEXITED %d [status %d]\n",
            argv[0], WEXITSTATUS(status), WIFEXITED(status), status);

    if (1 != WIFEXITED(status) || 0 != WEXITSTATUS(status)) {
            perror("%s failed, halt system");
            return -1;
    }

#endif
    return 0;
}

int main()
{
  char buff[255];
  FILE *fval = fopen("val/urls.txt", "r");
  FILE *ftrain = fopen("train/urls.txt", "r");
  if (fval == NULL || ftrain == NULL){
    printf("Error opening file!\n");
    exit(1);
  }

  /*------------------------------------------------*/
  /* récupère toutes les urls                       */
  /*------------------------------------------------*/
  while(fgets(buff, 255, (FILE*)fval)!=NULL){
        printf("%s",buff);
        char *my_argv[64] = {"./read_image" , buff , NULL};
        exec_prog(my_argv);
  }

  fclose(fval);
  fclose(ftrain);

  exit(0);
}
