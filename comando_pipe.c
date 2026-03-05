#include "shell.h"

void comando_pipe(int pipe_pos, char **args){
    args[pipe_pos] = NULL;
    char **args2 = &args[pipe_pos + 1];
    int fd[2];

    if(pipe(fd) == -1){
        printf("ERRO na criação do pipe\n");
    }

    pid_t pid1 = fork();

    if(pid1 == 0){
        dup2(fd[0], STDOUT_FILENO);
        close(fd[1]);
        close(fd[0]);

        execvp(args[0], args);
        printf("ERRO no primeiro pipe\n");
        exit(1);
    }

    pid_t pid2 = fork();

    if(pid2 == 0){
        dup2(fd[0], STDIN_FILENO);
        close(fd[1]);
        close(fd[0]);

        execvp(args2[0], args2);
        printf("Erro no segundo pipe\n");
        exit(1);
    }

    close(fd[0]);
    close(fd[1]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

}