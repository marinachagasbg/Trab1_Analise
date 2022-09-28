# Intro
O objetivo desse projeto é realizar a implementação dos algoritmos de ordenação `Insertion Sort`, `Selection Sort`, `Merge Sort`, `Heap Sort` e `Quick Sort`, fazendo a análise de complexidade de tempo, comparações e trocas, considerando o melhor caso, caso médio e pior caso de cada um desses algoritmos.
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
O arquivo gerado segue o seguinte formato:
```
bt:  | mt: | wt: | bs: | ms: | ws: | bc: | mc: | wc: 
```
Sendo, `bt` best time, `mt` middle time, `wt` worst time, `bs` best swaps, `ms` middle swaps, `ws` worst swaps, `bc` best comparisons, `mc` middle comparisons, `wc` worst comparisons.
# Insertion Sort
O algoritmo Inserion Sort é um algoritmo de ordenação por inserção, que funciona como em um jogo de cartas, quando deseja-se organizá-las de forma ordenada. Ao receber uma nova carta, essa deve ser colocada em sua respectiva posição.
Esse é um algoritmo de fácil implementação, funcionando muito bem para conjuntos pequenos de dados.

![](https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif)

### Complexidade:
Esse algoritmo tem como melhor caso, um vetor ordenado, tendo uma complexidade de $O(n)$. Como caso médio, um vetor aleatório, com complexidade $O(n^2)$. Por fim, seu pior caso também tem complexidade $O(n^2)$.

| Melhor Caso | Caso Médio | Pior Caso |
|-------------|------------|-----------|
| $$O(n)$$    | $$O(n^2)$$ | $$O(n^2)$$|

###   `resultados de tempo:`
|Tamanho| Melhor Caso | Caso Médio | Pior Caso |
|-------|-------------|------------|-----------|
|1000   |0.000007     |0.001370    |0.002482   |
|2000   |0.000013     |0.005331    |0.006801   |
|3000   |0.000011     |0.012325    |0.013147   |
|4000   |0.000014     |0.017734    |0.023528   |
|5000   |0.000016     |0.022770    |0.037410   |
|6000   |0.000016     |0.030923    |0.053166   |
|7000   |0.000022     |0.041009    |0.070763   |
|8000   |0.000023     |0.052066    |0.091798   |
|9000   |0.000027     |0.064697    |0.113897   |
|10000  |0.000030     |0.078917    |0.138940   |
|20000  |0.000060     |0.285573    |0.549059   |
|30000  |0.000083     |0.629898    |1.235186   |
|40000  |0.000112     |1.108555    |2.203908   |
|50000  |0.000127     |1.730193    |3.439650   |
|60000  |0.000151     |2.496914    |4.929368   |
|70000  |0.000177     |3.413527    |6.736339   |
|80000  |0.000212     |4.506484    |8.940735   |
|90000  |0.000227     |5.579498    |11.100466  |
|100000 |0.000256     |6.946194    |13.843966  |

<img src="graficos/insertionsort.png" />

### `resultados de comparações:`
|Tamanho| Melhor Caso | Caso Médio | Pior Caso |
|-------|-------------|------------|-----------|
|1000   |999          |253527      |500499     |
|2000   |1999         |998448      |2000999    |
|3000   |2999         |2248876     |4501499    |
|4000   |3999         |3999995     |8001999    |
|5000   |4999         |6248998     |12502499   |
|6000   |5999         |8974766     |18002999   |
|7000   |6999         |12187985    |24503499   |
|8000   |7999         |16010059    |32003999   |
|9000   |8999         |20282588    |40504499   |
|10000  |9999         |25033069    |50004999   |
|20000  |19999        |100076477   |200009999  |
|30000  |29999        |225120875   |450014999  |
|40000  |39999        |399346374   |800019999  |
|50000  |49999        |625374331   |1250024999 |
|60000  |59999        |898906261   |1800029999 |
|70000  |69999        |1222533450  |2450034999 |
|80000  |79999        |1597332826  |3200039999 |
|90000  |89999        |2021889313  |4050044999 |
|100000 |99999        |2497400096  |5000049999 |

<img src="graficos/insertionsort-comparisons.png" />

### `resultados de trocas:`
|Tamanho| Melhor Caso | Caso Médio | Pior Caso |
|-------|-------------|------------|-----------|
|1000   |999          |253527      |500499     |
|2000   |1999         |998448      |2000999    |
|3000   |2999         |2248876     |4501499    |
|4000   |3999         |3999995     |8001999    |
|5000   |4999         |6248998     |12502499   |
|6000   |5999         |8974766     |18002999   |
|7000   |6999         |12187985    |24503499   |
|8000   |7999         |16010059    |32003999   |
|9000   |8999         |20282588    |40504499   |
|10000  |9999         |25033069    |50004999   |
|20000  |19999        |100076477   |200009999  |
|30000  |29999        |225120875   |450014999  |
|40000  |39999        |399346374   |800019999  |
|50000  |49999        |625374331   |1250024999 |
|60000  |59999        |898906261   |1800029999 |
|70000  |69999        |1222533450  |2450034999 |
|80000  |79999        |1597332826  |3200039999 |
|90000  |89999        |2021889313  |4050044999 |
|100000 |99999        |2497400096  |5000049999 |

<img src="graficos/insertionsort-permutations.png" />