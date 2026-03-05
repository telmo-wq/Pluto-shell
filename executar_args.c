#include "shell.h"
#include <string.h>


int executar_args(char **args){
    char *lista_builtin[] = {
        "cd",
        "env",
        "help",
        "exit"
    };
    int (*builtin_func[])(char **) = {
        &own_cd,
        &own_env,
        &own_help,
        &own_exit
    };
    int i = 0;

    if (args[0] == NULL){
        return -1;
    }
    for (; i < sizeof(lista_builtin) / sizeof(char *); i++){
        if (strcmp(args[0], lista_builtin[i]) == 0){
            return ((*builtin_func[i])(args));
        }
    }
    int c = 0;
    int pipe_existe = 0;
    int pipe_pos = 0;

    while (args[c] != NULL){
        if (strcmp(args[c], "|") == 0){
            pipe_existe = 1;
            break;
        }
        c++;
    }

    if (pipe_existe == 1){
        comando_pipe(pipe_pos, args);
    }else {
        return (novo_processo(args));
    }

}