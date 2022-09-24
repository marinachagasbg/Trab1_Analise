#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct registro registro;

struct registro {
	int chave;
	//além de outros campos de informação do registro
};

int contador_comparacoes = 0;
int contador_troca = 0;

void merge(registro *v, int p, int q, int r)
{
   int i, j, k;
   registro *w;
   w = (registro *) malloc( (r-p+1) * sizeof (registro));
   i = p;
   j = q+1;
   k = 0;

   while (i <= q && j <= r) {
      // comparação
      contador_comparacoes++;
      if (v[i].chave <= v[j].chave)
	      {w[k++] = v[i++];}
      else
          w[k++] = v[j++];
   }
   while (i <= q)
      {w[k++] = v[i++];}
   while (j <= r)
      {w[k++] = v[j++];}
   for (i = p; i <= r; ++i)
      {v[i] = w[i-p]; //troca
      contador_troca++;}
   free(w);
}


void mergesort(registro* v,int ini, int fim)
{
  int meio;
  if  (ini < fim) {
    meio = ( ini + fim ) / 2;
    mergesort(v, ini, meio );
    mergesort(v, meio+1, fim);
    merge(v, ini, meio, fim );
  }
}

int main()
{
	//registro v[500000];
	registro *v, *q;
	int i = 0, j = 0;
	const int n = 5000000;

	//srand(time(NULL));
	srand(1);

	v = malloc (sizeof(registro)*n);
	if (v==NULL){
		printf("Nao foi possivel alocar");
	}

	q = malloc (sizeof(registro)*n);
	if (q==NULL){
		printf("Nao foi possivel alocar");
	}


//--------------------------------------------------------------------
//		Random vector

	for (i = 0; i < n; i++) {
		v[i].chave = rand() % 100;
		//printf("%d ", v[i].chave);
	}



//--------------------------------------------------------------------

// caso medio

	printf("\nmedio Caso\n");
	clock_t begin = clock();
	mergesort(v, 0, n-1);
	clock_t end = clock();

	printf("\n %lf ", begin);
	printf("\n %lf ", end);

	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n %lf \n", time_spent);

	printf("\n Trocas: %d\n Comparacoes: %d\n", contador_troca, contador_comparacoes);
    contador_troca = 0;
    contador_comparacoes = 0;

	/*
	printf("\n\nVetor ordenado\n");
	for (i = 0; i < 2000; i++)
		printf("%d ", v[i].chave);
	*/

// melhor caso
	printf("\melhor Caso");
	begin = clock();
	mergesort(v, 0, n-1);
	end = clock();

	printf("\n %lf ", begin);
	printf("\n %lf ", end);

	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n %lf \n", time_spent);

	printf("\n Trocas: %d\n Comparacoes: %d\n", contador_troca, contador_comparacoes);
    contador_troca = 0;
    contador_comparacoes = 0;

// pior caso

	for (i = 0; i < n; i++){
		q[i].chave = v[n-i-1].chave;
	}


//	for (i = 0; i < n; i++)
//		printf("%d ", q[i].chave);

	printf("\nPior Caso");

	begin = clock();
	mergesort(q, 0, n-1);
	end = clock();

	printf("\n %lf ", begin);
	printf("\n %lf ", end);

	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n %lf \n", time_spent);

	printf("\n Trocas: %d\n Comparacoes: %d\n", contador_troca, contador_comparacoes);
    contador_troca = 0;
    contador_comparacoes = 0;

//--------------------------------------------------------------------
	free(v);
	return 0;
}

