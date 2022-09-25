# README

## Executando o projeto:

O arquivo principal a ser executado é o `exec.c`.

Os arquivos `compile.sh` e `clean.sh` são usados para compilar os arquivos necessários para execução e limpá-los. Para tornar esses arquivos executáveis, basta usar os comandos:
```
sudo chmod 777 compile.sh
sudo chmod 777 clean.sh
```
Para executá-los:
```
./compile.sh
./clean.sh
```

Uma vez que todas as dependências são compiladas, é possível executar o código `exec`, passando como argumentos o `nome do executável` que se deseja executar e o `tamanho da entrada`. 
Exemplo:
```
./exec.o mergesort.o 10000
```
