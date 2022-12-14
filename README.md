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
Sendo, `bt` best time, `mt` middle time, `wt` worst time, `bs` best swaps, `ms` middle swaps, `ws` worst swaps, `bc` best comparisons, `mc` middle comparisons, `wc` worst comparisons. <br>
Nos gráficos, as colunas com `+-` referem-se ao `desvio padrão` do conjunto.
# Insertion Sort
O algoritmo Inserion Sort é um algoritmo de ordenação por inserção, que funciona como em um jogo de cartas, quando deseja-se organizá-las de forma ordenada. Ao receber uma nova carta, essa deve ser colocada em sua respectiva posição.
Esse é um algoritmo de fácil implementação, funcionando muito bem para **conjuntos de dados pequenos**.

![](https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif)

### Complexidade:
Esse algoritmo tem como melhor caso, um vetor ordenado, tendo uma complexidade de $O(n)$. Como caso médio, um vetor aleatório, com complexidade $O(n^2)$. Por fim, seu pior caso é um vetor inversamente ordenado, e também tem complexidade $O(n^2)$.

| Melhor Caso | Caso Médio | Pior Caso |
|-------------|------------|-----------|
| $$O(n)$$    | $$O(n^2)$$ | $$O(n^2)$$|
<br>

###   `resultados de tempo:`
|Tamanho|     Melhor Caso    |     Caso Médio     |      Pior Caso      |
|-------|--------------------|--------------------|---------------------|
|1000   |0.000011 +- 0.000004|0.002167 +- 0.000499|0.004182  +- 0.000892|
|2000   |0.000017 +- 0.000008|0.007814 +- 0.002384|0.009874  +- 0.003203|
|3000   |0.000013 +- 0.000003|0.009569 +- 0.003937|0.013471  +- 0.000512|
|4000   |0.000015 +- 0.000003|0.018785 +- 0.004000|0.023489  +- 0.000441|
|5000   |0.000015 +- 0.000003|0.027829 +- 0.002070|0.036772  +- 0.001442|
|6000   |0.000017 +- 0.000002|0.034587 +- 0.004542|0.052905  +- 0.001249|
|7000   |0.000023 +- 0.000006|0.041217 +- 0.004611|0.068538  +- 0.004385|
|8000   |0.000023 +- 0.000006|0.056260 +- 0.004638|0.088156  +- 0.004914|
|9000   |0.000026 +- 0.000007|0.066985 +- 0.006131|0.107166  +- 0.002178|
|10000  |0.000027 +- 0.000005|0.078784 +- 0.004339|0.134806  +- 0.003147|
|20000  |0.000053 +- 0.000010|0.274741 +- 0.003888|0.517515  +- 0.004421|
|30000  |0.000072 +- 0.000003|0.596632 +- 0.005159|1.163152  +- 0.004691|
|40000  |0.000098 +- 0.000004|1.053718 +- 0.014639|2.068533  +- 0.008394|
|50000  |0.000125 +- 0.000004|1.650559 +- 0.015481|3.266188  +- 0.030108|
|60000  |0.000142 +- 0.000008|2.355638 +- 0.019581|4.702376  +- 0.065899|
|70000  |0.000176 +- 0.000021|3.269323 +- 0.080499|6.433713  +- 0.081745|
|80000  |0.000193 +- 0.000010|4.165521 +- 0.035346|8.362144  +- 0.208307|
|90000  |0.000223 +- 0.000015|5.432963 +- 0.142498|10.707689 +- 0.171613|
|100000 |0.000244 +- 0.000013|6.494386 +- 0.058193|13.004524 +- 0.105184|


<div>
  <img src="graficos/insertion-bt.png" />
  <img src="graficos/insertion-mt.png" />
  <img src="graficos/insertion-wt.png" />
</div>
<br>

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

<img src="graficos/insertionsort-comparisons.png" width="376" height="282" />
<br>

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

<img src="graficos/insertionsort-permutations.png" width="376" height="282" />
<br>

# Selection Sort
Tem como objetivo colocar os menores elementos na nas primeiras posições do vetor, até que a ordenação seja concluída. Para isso, o algoritmo é composto por dois laços, sendo mais externo que controla o índice e o segundo que faz a varredura do vetor.<br>
Esse é um algoritmo **in-place**, simples de ser implementado, sendo bom para **conjuntos de dados pequenos**. Seu problema está em conjuntos grandes de dados, sendo muito ruim nesse caso.<br>
Seu funcionamento pode ser demonstrado abaixo:

![](https://upload.wikimedia.org/wikipedia/commons/9/94/Selection-Sort-Animation.gif)

### Complexidade:
Outro ponto importante desse algorítmo, é que esse não possuí melhor ou pior caso, sendo todos $O(n²)$, já que os dois loops sempre serão executados.
| Melhor Caso | Caso Médio | Pior Caso |
|-------------|------------|-----------|
| $$O(n^2)$$  | $$O(n^2)$$ | $$O(n^2)$$|
<br>

### `resultados de tempo:`
|Tamanho|     Melhor Caso     |     Caso Médio     |      Pior Caso     |
|-------|---------------------|--------------------|--------------------|
|1000   |0.001776 +- 0.000811 |0.001954 +- 0.000906|0.001647 +- 0.000657|
|2000   |0.004957 +- 0.001066 |0.008119 +- 0.002975|0.003765 +- 0.000197|
|3000   |0.008207 +- 0.000362 |0.014469 +- 0.002692|0.008133 +- 0.000172|
|4000   |0.014764 +- 0.001176 |0.023644 +- 0.003483|0.014653 +- 0.000691|
|5000   |0.022579 +- 0.000848 |0.029435 +- 0.003074|0.023242 +- 0.000716|
|6000   |0.032562 +- 0.000898 |0.039787 +- 0.003624|0.032427 +- 0.001116|
|7000   |0.043733 +- 0.001428 |0.051300 +- 0.002369|0.044482 +- 0.000973|
|8000   |0.057052 +- 0.001194 |0.061920 +- 0.004306|0.057157 +- 0.001379|
|9000   |0.071594 +- 0.001208 |0.078010 +- 0.004149|0.070800 +- 0.000911|
|10000  |0.087695 +- 0.001666 |0.094605 +- 0.005228|0.086660 +- 0.001450|
|20000  |0.338148 +- 0.005306 |0.347386 +- 0.008252|0.337202 +- 0.005633|
|30000  |0.746420 +- 0.011233 |0.748919 +- 0.006105|0.751096 +- 0.012940|
|40000  |1.339960 +- 0.046668 |1.358792 +- 0.041556|1.337883 +- 0.049191|
|50000  |2.066474 +- 0.025953 |2.076138 +- 0.016606|2.069322 +- 0.030952|
|60000  |3.069226 +- 0.097612 |3.064959 +- 0.088956|3.089263 +- 0.121558|
|70000  |4.008881 +- 0.213298 |4.029718 +- 0.219824|4.000716 +- 0.238830|
|80000  |4.893991 +- 0.029108 |4.941121 +- 0.059232|4.894962 +- 0.033234|
|90000  |6.233660 +- 0.037623 |6.236459 +- 0.044807|6.220954 +- 0.050262|
|100000 |7.687194 +- 0.053724 |7.692758 +- 0.039498|7.693500 +- 0.042822|

<div>
  <img src="graficos/selection-bt.png" />
  <img src="graficos/selection-mt.png" />
  <img src="graficos/selection-wt.png" />
</div>
<br>

### `resultados de comparações:`
|Tamanho| Melhor Caso | Caso Médio | Pior Caso |
|-------|-------------|------------|-----------|
|1000   |499500       |499500      |499500     |
|2000   |1999000      |1999000     |1999000    |
|3000   |4498500      |4498500     |4498500    |
|4000   |7998000      |7998000     |7998000    |
|5000   |12497500     |12497500    |12497500   |
|6000   |17997000     |17997000    |17997000   |
|7000   |24496500     |24496500    |24496500   |
|8000   |31996000     |31996000    |31996000   |
|9000   |40495500     |40495500    |40495500   |
|10000  |49995000     |49995000    |49995000   |
|20000  |199990000    |199990000   |199990000  |
|30000  |449985000    |449985000   |449985000  |
|40000  |799980000    |799980000   |799980000  |
|50000  |1249975000   |1249975000  |1249975000 |
|60000  |1799970000   |1799970000  |1799970000 |
|70000  |2449965000   |2449965000  |2449965000 |
|80000  |3199960000   |3199960000  |3199960000 |
|90000  |4049955000   |4049955000  |4049955000 |
|100000 |4999950000   |4999950000  |4999950000 |

<img src="graficos/selection-comparisons.png" width="376" height="282" />
<br>


### `resultados de trocas:`
|Tamanho| Melhor Caso | Caso Médio | Pior Caso |
|-------|-------------|------------|-----------|
|1000   |1998         |1998        |1998       |
|2000   |3998         |3998        |3998       |
|3000   |5998         |5998        |5998       |
|4000   |7998         |7998        |7998       |
|5000   |9998         |9998        |9998       |
|6000   |11998        |11998       |11998      |
|7000   |13998        |13998       |13998      |
|8000   |15998        |15998       |15998      |
|9000   |17998        |17998       |17998      |
|10000  |19998        |19998       |19998      |
|20000  |39998        |39998       |39998      |
|30000  |59998        |59998       |59998      |
|40000  |79998        |79998       |79998      |
|50000  |99998        |99998       |99998      |
|60000  |119998       |119998      |119998     |
|70000  |139998       |139998      |139998     |
|80000  |159998       |159998      |159998     |
|90000  |179998       |179998      |179998     |
|100000 |199998       |199998      |199998     |

<img src="graficos/selection-permutations.png" width="376" height="282" />
<br>


# Merge Sort:
O merge sort é um algoritmo de ordeção do tipo `divisão e conquista`, tendo como ideia básica dividir o problema em problemas menores, que são resolvidos e depois, o resultado final se dá pela união das soluções desses subproblemas. <br>
O algoritmo conta com três etapas:<br>
- Dividir, em que é calculado o ponto médio do conjunto. Essa etapa tem tempo constante $(Θ(1))$
- Conquistar, em que os subproblemas são resolvidos individualmente. Essa etapa tem tempo de $2T(n / 2)$, já que o tamanho do subconjunto após a divisão é $n / 2$
- Combinar, unindo todos os subconjuntos ordenados, levando um tempo de $(Θ(n))$

Alguns pontos importantes sobre esse algoritmo é que ele não é **in-place**, necessitando de um vetor auxiliar; utiliza recursão, tendo um gasto extra de memória em cada chamada recursiva.
Seu funcionamento pode ser demonstrado abaixo:

![](https://upload.wikimedia.org/wikipedia/commons/c/cc/Merge-sort-example-300px.gif)

### Complexidade:
A maior vantagem do merge sort é observada em **conjuntos grandes de dados**, sendo ruins para conjuntos pequenos. Um ponto importante é que a complexidade é a mesma para todos os casos, independente da disposição dos elementos no conjunto, sendo $O(nlog_2n)$.

|  Melhor Caso  |  Caso Médio  |  Pior Caso  |
|---------------|--------------|-------------|
| $O(nlog_2n)$  |$O(nlog_2n)$  | $O(nlog_2n)$|
<br>

### `resultados de tempo:` 
|Tamanho|     Melhor Caso    |     Caso Médio     |      Pior Caso     |
|-------|--------------------|--------------------|--------------------|
|1000   |0.000151 +- 0.000039|0.000285 +- 0.000062|0.000159 +- 0.000048|
|2000   |0.000387 +- 0.000055|0.000673 +- 0.000160|0.000354 +- 0.000058|
|3000   |0.000660 +- 0.000096|0.001119 +- 0.000183|0.000642 +- 0.000104|
|4000   |0.000900 +- 0.000171|0.001581 +- 0.000361|0.000844 +- 0.000160|
|5000   |0.001024 +- 0.000275|0.001733 +- 0.000469|0.000972 +- 0.000273|
|6000   |0.001257 +- 0.000416|0.002134 +- 0.000803|0.001089 +- 0.000302|
|7000   |0.001215 +- 0.000493|0.002264 +- 0.000939|0.001111 +- 0.000398|
|8000   |0.001047 +- 0.000504|0.001895 +- 0.001038|0.001028 +- 0.000430|
|9000   |0.001704 +- 0.000581|0.003123 +- 0.001198|0.001673 +- 0.000512|
|10000  |0.001658 +- 0.000591|0.003072 +- 0.002160|0.001591 +- 0.000590|
|20000  |0.002868 +- 0.000870|0.007214 +- 0.002998|0.001854 +- 0.000421|
|30000  |0.003546 +- 0.000939|0.010179 +- 0.001684|0.002671 +- 0.000320|
|40000  |0.004198 +- 0.000648|0.013534 +- 0.003280|0.003364 +- 0.000131|
|50000  |0.004594 +- 0.000363|0.014730 +- 0.003238|0.004152 +- 0.000299|
|60000  |0.005364 +- 0.000307|0.014819 +- 0.003103|0.005276 +- 0.000231|
|70000  |0.006606 +- 0.000685|0.015633 +- 0.002535|0.006073 +- 0.000767|
|80000  |0.007271 +- 0.000387|0.018747 +- 0.002563|0.007088 +- 0.000501|
|90000  |0.008290 +- 0.000472|0.019640 +- 0.003068|0.007718 +- 0.000480|
|100000 |0.009198 +- 0.000426|0.019854 +- 0.039498|0.009400 +- 0.000868|

<div>
  <img src="graficos/merge-bt.png" />
  <img src="graficos/merge-mt.png" />
  <img src="graficos/merge-wt.png" />
</div>
<br>

### `resultados de comparações:`
|Tamanho| Melhor Caso | Caso Médio | Pior Caso |
|-------|-------------|------------|-----------|
|1000   |5044         |8713        |5044       |
|2000   |11088        |19402       |11088      |
|3000   |18076        |30931       |18076      |
|4000   |24176        |42828       |24176      |
|5000   |32004        |55233       |32004      |
|6000   |39152        |67847       |39152      |
|7000   |46180        |80661       |46180      |
|8000   |52352        |93622       |52352      |
|9000   |60796        |106993      |60796      |
|10000  |69008        |120438      |69008      |
|20000  |148016       |260887      |148016     |
|30000  |227728       |408573      |227728     |
|40000  |316032       |561756      |316032     |
|50000  |401952       |718114      |401952     |
|60000  |485456       |877111      |485456     |
|70000  |573728       |1038884     |573728     |
|80000  |672064       |1203509     |672064     |
|90000  |765248       |1369350     |765248     |
|100000 |853904       |1536214     |853904     |

<img src="graficos/merge-comparisons.png" width="376" height="282" />
<br>

### `resultados de trocas:`
|Tamanho| Melhor Caso | Caso Médio | Pior Caso |
|-------|-------------|------------|-----------|
|1000   |9976         |9976        |9976       |
|2000   |21952        |21952       |21952      |
|3000   |34904        |34904       |34904      |
|4000   |47904        |47904       |47904      |
|5000   |61808        |61808       |61808      |
|6000   |75808        |75808       |75808      |
|7000   |89808        |89808       |89808      |
|8000   |103808       |103808      |103808     |
|9000   |118616       |118616      |118616     |
|10000  |133616       |133616      |133616     |
|20000  |287232       |287232      |287232     |
|30000  |447232       |447232      |447232     |
|40000  |614464       |614464      |614464     |
|50000  |784464       |784464      |784464     |
|60000  |954464       |954464      |954464     |
|70000  |1128928      |1128928     |1128928    |
|80000  |1308928      |1308928     |1308928    |
|90000  |1488928      |1488928     |1488928    |
|100000 |1668928      |1668928     |1668928    |

<img src="graficos/merge-permutations.png" width="376" height="282" />
<br>


# Heap Sort
O Heap Sort é um algoritmo de **ordenação por seleção**. Esse, utiliza uma estrutura de dados **heap** para fazer a ordenação dos elementos. Essa heap pode ser representada como uma árvore ou vetor. Quando todos os elementos são adiconados na heap, é possível remover os elementos da raiz, mantendo a propriedade do **heap-max**.

![](https://upload.wikimedia.org/wikipedia/commons/4/4d/Heapsort-example.gif)

### Complexidade:
Esse algoritmo tem a mesma complexidade para os 3 casos, independente da organização do conjunto de dados.

|  Melhor Caso  |  Caso Médio  |  Pior Caso  |
|---------------|--------------|-------------|
| $O(nlog_2n)$  |$O(nlog_2n)$  | $O(nlog_2n)$|
<br>

### `resultados de tempo:`
|Tamanho|     Melhor Caso    |     Caso Médio     |      Pior Caso     |
|-------|--------------------|--------------------|--------------------|
|1000   |0.000900 +- 0.000539|0.000800 +- 0.000600|0.000800 +- 0.000400|
|2000   |0.001800 +- 0.000400|0.002100 +- 0.000539|0.001600 +- 0.000490|
|3000   |0.002300 +- 0.000781|0.002700 +- 0.000640|0.001800 +- 0.000872|
|4000   |0.003500 +- 0.001025|0.004200 +- 0.000748|0.002400 +- 0.001200|
|5000   |0.002800 +- 0.001600|0.003200 +- 0.002040|0.001900 +- 0.000831|
|6000   |0.004100 +- 0.002211|0.005300 +- 0.001792|0.002400 +- 0.000663|
|7000   |0.003900 +- 0.001640|0.006000 +- 0.002191|0.002500 +- 0.000806|
|8000   |0.004500 +- 0.001688|0.007700 +- 0.002610|0.003000 +- 0.000775|
|9000   |0.004700 +- 0.001418|0.008700 +- 0.002326|0.003200 +- 0.000600|
|10000  |0.004200 +- 0.001249|0.006400 +- 0.002615|0.003200 +- 0.000600|
|20000  |0.008400 +- 0.000490|0.008300 +- 0.001792|0.007100 +- 0.000943|
|30000  |0.012900 +- 0.000943|0.013300 +- 0.002369|0.012400 +- 0.001800|
|40000  |0.018000 +- 0.001183|0.022000 +- 0.002646|0.014600 +- 0.001356|
|50000  |0.022800 +- 0.000980|0.026600 +- 0.002871|0.018600 +- 0.001356|
|60000  |0.027600 +- 0.001855|0.030600 +- 0.002871|0.022100 +- 0.001044|
|70000  |0.030700 +- 0.001418|0.036300 +- 0.002865|0.025000 +- 0.000632|
|80000  |0.038200 +- 0.005056|0.039200 +- 0.002713|0.028200 +- 0.002135|
|90000  |0.041500 +- 0.001910|0.045200 +- 0.002522|0.031200 +- 0.000872|
|100000 |0.045300 +- 0.001616|0.048800 +- 0.002315|0.034100 +- 0.000700|

<div>
  <img src="graficos/heap-bt.png" />
  <img src="graficos/heap-mt.png" />
  <img src="graficos/heap-wt.png" />
</div>
<br>

### `resultados de comparações:`
|Tamanho| Melhor Caso | Caso Médio | Pior Caso |
|-------|-------------|------------|-----------|
|1000   |15488        |15488       |14440      |
|2000   |33999        |33999       |31980      |
|3000   |53527        |53527       |50530      |
|4000   |74030        |74030       |69917      |
|5000   |94799        |94799       |89681      |
|6000   |116106       |116106      |110218     |
|7000   |137777       |137777      |130472     |
|8000   |159962       |159962      |151635     |
|9000   |182103       |182103      |173003     |
|10000  |204533       |204533      |194543     |
|20000  |438968       |438968      |420039     |
|30000  |685032       |685032      |657188     |
|40000  |938134       |938134      |900412     |
|50000  |1197151      |1197151     |1149146    |
|60000  |1459824      |1459824     |1399448    |
|70000  |1727081      |1727081     |1655307    |
|80000  |1995750      |1995750     |1916574    |
|90000  |2268362      |2268362     |2177378    |
|100000 |2544060      |2544060     |2445237    |

<img src="graficos/merge-comparisons.png" width="376" height="282" />
<br>

### `resultados de trocas:`
|Tamanho| Melhor Caso | Caso Médio | Pior Caso |
|-------|-------------|------------|-----------|
|1000   |9069         |9069        |8316       |
|2000   |20165        |20165       |18708      |
|3000   |32040        |32040       |29750      |
|4000   |44330        |44330       |41436      |
|5000   |57079        |57079       |53436      |
|6000   |70074        |70074       |65598      |
|7000   |83300        |83300       |78170      |
|8000   |96571        |96571       |90776      |
|9000   |110279       |110279      |103686     |
|10000  |124129       |124129      |116696     |
|20000  |268257       |268257      |254334     |
|30000  |419631       |419631      |399212     |
|40000  |576520       |576520      |547628     |
|50000  |737086       |737086      |698892     |
|60000  |899108       |899108      |854794     |
|70000  |1064263      |1064263     |1012682    |
|80000  |1232863      |1232863     |1174074    |
|90000  |1402873      |1402873     |1334932    |
|100000 |1573896      |1573896     |1497434    |

<img src="graficos/heap-permutations.png" width="376" height="282" />
<br>

# Quick Sort
Esse algoritmo usa a estratégia de **divisão e conquista**. A ideia consiste em utilizar um pivô como base, dividindo o conjunto em dois, contendo os valores maiores e menores que esse pivô. Então esse algoritmo é chamado **recursivamente** para os dois subconjuntos. Basicamente, as etapas são:
- Escolha do pivo
- Particiona o conjunto, colocando os elementos menores que o pivô para a esquerda desse, e os maiores a direita.
- Ordenar os subconjuntos recursivamente.

![](https://upload.wikimedia.org/wikipedia/commons/9/9c/Quicksort-example.gif)

### Complexidade:
O melhor caso e o caso médio possuem a mesma complexidade. O problema está no pior caso, que é um $O(n^2)$. Esse caso ocorre pela escolha de um pivô ruim, fazendo com que os dois subconjuntos tenham uma distribuição muito desigual. Contudo, esse caso é muito difícil de ocorrer, já que seria necessário a escolha de um pivô ruim para cada iteração do algoritmo.

|  Melhor Caso  |  Caso Médio  |  Pior Caso  |
|---------------|--------------|-------------|
| $O(nlog_2n)$  |$O(nlog_2n)$  | $O(n^2)$    |

### `resultados de tempo:`
|Tamanho|     Melhor Caso    |     Caso Médio     |      Pior Caso     |
|-------|--------------------|--------------------|--------------------|
|1000   |0.000114 +- 0.000014|0.000293 +- 0.000022|0.000102 +- 0.000020|
|2000   |0.000284 +- 0.000027|0.000623 +- 0.000053|0.000254 +- 0.000037|
|3000   |0.000402 +- 0.000029|0.000920 +- 0.000071|0.000381 +- 0.000028|
|4000   |0.000510 +- 0.000132|0.001094 +- 0.000258|0.000481 +- 0.000118|
|5000   |0.000728 +- 0.000099|0.001505 +- 0.000065|0.000669 +- 0.000038|
|6000   |0.000789 +- 0.000214|0.001649 +- 0.000340|0.000657 +- 0.000198|
|7000   |0.000700 +- 0.000263|0.002050 +- 0.000159|0.000687 +- 0.000284|
|8000   |0.001037 +- 0.000043|0.002438 +- 0.000165|0.001024 +- 0.000055|
|9000   |0.000860 +- 0.000365|0.002445 +- 0.000533|0.000789 +- 0.000371|
|10000  |0.001234 +- 0.000288|0.002977 +- 0.000184|0.001021 +- 0.000389|
|20000  |0.002091 +- 0.000679|0.005957 +- 0.000607|0.001660 +- 0.000693|
|30000  |0.001611 +- 0.000591|0.006749 +- 0.001599|0.001536 +- 0.000472|
|40000  |0.002325 +- 0.001013|0.008950 +- 0.002348|0.002073 +- 0.000530|
|50000  |0.002850 +- 0.000837|0.009408 +- 0.003729|0.002321 +- 0.000254|
|60000  |0.002782 +- 0.000468|0.010388 +- 0.003577|0.002663 +- 0.000215|
|70000  |0.003299 +- 0.000294|0.011615 +- 0.003138|0.003356 +- 0.000278|
|80000  |0.003607 +- 0.000305|0.012076 +- 0.002733|0.003712 +- 0.000265|
|90000  |0.003980 +- 0.000368|0.012758 +- 0.003758|0.004183 +- 0.000535|
|100000 |0.004676 +- 0.000356|0.013372 +- 0.003469|0.004996 +- 0.000619|

<div>
  <img src="graficos/quick-bt.png" />
  <img src="graficos/quick-mt.png" />
  <img src="graficos/quick-wt.png" />
</div>
<br>

### `resultados de comparações:`
|Tamanho| Melhor Caso | Caso Médio | Pior Caso |
|-------|-------------|------------|-----------|
|1000   |11031        |14650       |11033      |
|2000   |24659        |31967       |24660      |
|3000   |38984        |48081       |38988      |
|4000   |53666        |67661       |53670      |
|5000   |68688        |84908       |68696      |
|6000   |84007        |104183      |84008      |
|7000   |99342        |121524      |99350      |
|8000   |114990       |140045      |114994     |
|9000   |130683       |156927      |130678     |
|10000  |146398       |180557      |146403     |
|20000  |313061       |378282      |313065     |
|30000  |487361       |572508      |487361     |
|40000  |669198       |775618      |669202     |
|50000  |838467       |1012264     |838492     |
|60000  |1030739      |1225990     |1030713    |
|70000  |1239652      |1418765     |1239646    |
|80000  |1423549      |1640369     |1423530    |
|90000  |1597677      |1889278     |1597687    |
|100000 |1775399      |2102998     |1775428    |

<img src="graficos/quick-comparisons.png" width="376" height="282" />
<br>

### `resultados de trocas:`
|Tamanho| Melhor Caso | Caso Médio | Pior Caso |
|-------|-------------|------------|-----------|
|1000   |796          |2687        |1295       |
|2000   |1968         |5968        |2968       |
|3000   |3344         |9600        |4842       |
|4000   |4869         |13339       |6868       |
|5000   |6541         |17336       |9040       |
|6000   |8312         |21345       |11309      |
|7000   |10165        |25590       |13662      |
|8000   |12118        |29889       |16115      |
|9000   |14129        |34336       |18626      |
|10000  |16212        |38584       |21209      |
|20000  |40334        |85788       |50328      |
|30000  |68332        |137025      |83321      |
|40000  |98546        |190443      |118532     |
|50000  |129053       |244746      |154040     |
|60000  |163650       |301744      |193634     |
|70000  |201004       |359560      |235983     |
|80000  |234759       |418462      |274725     |
|90000  |268884       |477126      |313850     |
|100000 |305360       |537596      |355334     |

<img src="graficos/quick-permutations.png" width="376" height="282" />
<br>