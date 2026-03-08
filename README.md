# Pluto Shell
Este é o repositório de um shell simples desenvolvido inteiramente em C

Além do arquivo Makefile escrito para a automação da compilação do código, dentro da pasta source estão contido os seguintes arquivos:

- main.c: Responsável pela execução do código e do modo interativo/bash

- batch.c: Função responsável pela leitura de arquivo do shell no modo batch

- dividir_linha.c: Tratamento de strings do input recebido por meio de tokens

- executar_args.c: Execução de comandos nativos do shell

- ler_linha.c: Lê o input da linha com tratamento de strings e de inputs vazios

- novo_processo.c: Executa uma função não-nativa do shell criando um processo filho do SO

- own_cd.c: Função usada para o comando nativo cd

- own_env.c: Função que retorna o comando nativo env

- own_exit.c: Função que retorna o comando nativo exit

- own_help.c: Função que retorna o comando nativo help

- shell_interativo.c: Função que executa o loop principal do shell

- shell.h: Header da biblioteca shell.h com todas as funções descritas

## Instruções para execução

Antes de tudo é importante ter o makefile instalado

```
sudo apt install build-essential
```

Com o makefile instalado, clone o repositório.

Para compilar:

```
make clean
make
```

Para executar (modo batch)

```
./shell [batchFile].txt
```
Onde [batchFile] corresponde ao nome do arquivo .txt

Para executar (modo interativo)

```
./shell
```

Este shell foi desenvolvido por Telmo Melo (telmo-wq) em um sistema Linux-Mint