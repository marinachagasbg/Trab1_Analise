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

Uma vez que todas as dependências são compiladas, é possível executar o código `exec`, passando como argumentos o `nome do executável` que se deseja executar. 
Exemplo:
```
./exec.o mergesort.o
```

Durante a execução, o algoritmo passado como argumento será executado 10 vezes, sendo calculada a média dos resultados. Esse processe se repete para diversos tamanhos de vetor diferente, como explicitado em:
```
  int entry_sizes[ENTRY_QUANTITY] = {
    1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000,
    10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 
    90000, 100000
  };
```
No caso, os tamanhos das entradas foram definidas usando uma escala logarítmica.
Por fim, no arquivo `results.bin`, são armazenados os resultados das médias desses resultados, para todos os valores de entrada mostrados acima.
