#include "shell.h"
#include <unistd.h>


int main(void){
    if (isatty(STDIN_FILENO) == 1){
        shell_interativo();
    }else{
        shell_nao_interativo();
    }

    return (0);


}