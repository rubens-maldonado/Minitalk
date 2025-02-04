# Minitalk

Minitalk é um projeto da 42 Rio que implementa um sistema de comunicação entre processos, usando sinais para transmitir mensagens de forma assíncrona. O projeto utiliza a linguagem C e foi desenvolvido para entender o funcionamento dos sinais no sistema operacional Unix e a comunicação entre processos.

## Objetivo do Projeto

O objetivo do Minitalk é criar um programa que utilize sinais para permitir que um processo envie mensagens para outro processo, usando a comunicação assíncrona via sinais UNIX. O projeto foi desenvolvido para entender como os sinais são tratados e como podemos criar um protocolo simples para comunicação entre dois processos.

## Tecnologias Utilizadas

- **C**: Linguagem de programação utilizada para o desenvolvimento.
- **Unix Signals**: Comunicação entre processos através de sinais.
- **Makefile**: Para automação do processo de compilação.

## Instalação

Para compilar o projeto, você precisará de um compilador C instalado. Para sistemas baseados em Unix, como Linux e macOS, use o comando `make` para compilar.

1. Clone o repositório:
   ```bash
   git clone https://github.com/rubens-maldonado/minitalk.git
   cd minitalk

2. Compile o projeto:
   ```bash
    make

# Como Usar

1. O servidor (receptor) deve ser iniciado primeiro. Ele ficará ouvindo sinais.
    ```bash
    ./server

2. Em seguida, o cliente pode enviar uma mensagem ao servidor. O cliente precisa passar o ID do processo do servidor e a mensagem.
    ```bash
    ./client <server_pid> <mensagem>

3. Exemplo:
   ```bash
   ./client 12345 "Olá, servidor!"

# Exemplo de Execução

1. Inicie o servidor:
    ```bash
    ./server
    PID do servidor: 12345

3. Em outro terminal, execute o cliente:
    ```bash
   ./client 12345 "Mensagem de teste!"

4. O servidor irá exibir a mensagem recebida:
   ```bash
   Mensagem recebida: "Mensagem de teste!"

# Testes

O projeto não inclui testes automatizados. Porém, você pode testar a comunicação entre os processos executando o servidor e o cliente em terminais diferentes e enviando várias mensagens.
