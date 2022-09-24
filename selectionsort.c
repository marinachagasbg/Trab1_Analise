#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct registro registro;
int contador_comparacoes = 0;
int contador_troca = 0;

struct registro {
	int chave;
	//além de outros campos de informação do registro
};

void selectionsort (registro* v, int n)
{
  int i, j, menor;
  registro temp;
  for (i = 0; i < n - 1; i++)
  {
    menor = i; //troca
    contador_troca++;

    for (j = i + 1 ; j < n; j++)
      // comparação a seguir
      contador_comparacoes++;
      if ( v[j].chave < v[menor].chave)
        menor = j;

    temp = v[menor]; // troca
    contador_troca++;
    v[menor] = v[i];
    v[i] = temp;
  }
}

int main()
{
	//registro v[500000];
	registro *v;
	int i = 0, j = 0;
	const int n = 100000;

	//srand(time(NULL));
	srand(1);

	v = malloc (sizeof(registro)*n);
	if (v==NULL){
		printf("Nao foi possivel alocar");
	}


//--------------------------------------------------------------------
//		Random vector
	/*
	for (i = 0; i < n; i++) {
		v[i].chave = rand() % 100;
		//printf("%d ", v[i].chave);
	}*/
	for ( i =0; i< n ;i+=2){
		v[i].chave = i;
		v[i+1].chave = n-i;

	}



//--------------------------------------------------------------------

// caso medio

	printf("Caso medio \n");

	clock_t begin = clock();
	selectionsort(v, n);
	clock_t end = clock();

	printf("\n %lf ", begin);
	printf("\n %lf ", end);

	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n %lf \n", time_spent);

	printf("\n Trocas: %d\n Comparacoes: %d", contador_troca, contador_comparacoes);
    contador_troca = 0;
    contador_comparacoes = 0;

	/*
	printf("\n\nVetor ordenado\n");
	for (i = 0; i < 2000; i++)
		printf("%d ", v[i].chave);
	*/

// melhor caso
	printf("\nMelhor Caso");

	begin = clock();
	selectionsort(v, n);
	end = clock();

	printf("\n %lf ", begin);
	printf("\n %lf ", end);

	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n %lf \n", time_spent);

    printf("\n Trocas: %d\n Comparacoes: %d", contador_troca, contador_comparacoes);
    contador_troca = 0;
    contador_comparacoes = 0;

// pior caso

	for( i = n, j = 0 ;  i > 0, j < n; i --, j ++){
		v[j].chave = i;
	}

	printf("\nPior Caso");

	begin = clock();
	selectionsort(v, n);
	end = clock();

	printf("\n %lf ", begin);
	printf("\n %lf ", end);

	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n %lf \n", time_spent);

	printf("\n Trocas: %d\n Comparacoes: %d", contador_troca, contador_comparacoes);
    contador_troca = 0;
    contador_comparacoes = 0;


//--------------------------------------------------------------------
	free(v);
	return 0;
}
