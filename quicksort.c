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

void partition(int Esq, int Dir,
              int *i, int *j, registro *v)
{
  registro x, w;
  *i = Esq; *j = Dir;

  //pivô
  x = v[(*i + *j)/2];

  do
  {
    while (x.chave > v[*i].chave)
	     {(*i)++;
           contador_comparacoes++;
	     }
    contador_comparacoes++; // comparação que saiu do loop
    while (x.chave < v[*j].chave)
        {(*j)--;
          contador_comparacoes++;
        }
    contador_comparacoes++; // comparação que saiu do loop
    if (*i <= *j)
    {
      w = v[*i];
      v[*i] = v[*j];
      v[*j] = w;//troca
      contador_troca++;
      (*i)++;
      (*j)--;
    }
  } while (*i <= *j);
}


void sort(int Esq, int Dir, registro *v)
{
  int i,j;
  partition(Esq, Dir, &i, &j, v);
  contador_comparacoes++;
  if (Esq < j) //comparação
	 sort(Esq, j, v);
  contador_comparacoes++;
  if (i < Dir) //comparação
     sort(i, Dir, v);
}
void quicksort(registro *v, int n)
{
  sort(0, n-1, v);
}

//--------------------------------------------------------------------
//					MAIN

int main()
{
	//registro v[500000];
	registro *v, *q;
	int i = 0, j = 0;
	const int n = 50000000;

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
//				Random vector

	for (i = 0; i < n; i++) {
		v[i].chave = rand() % 100;
	}
	//for (j = n , i = n/2; i < n, j > n/2; j--, i++){
  	//	v[i].chave = j;
	//}
	/*
	for ( i =0; i< n ;i+=2){
		v[i].chave = i;
		v[i+1].chave = n-i;

	}*/


//--------------------------------------------------------------------
//					Casos

// caso medio

	printf("\nCaso medio \n");

	clock_t begin = clock();
	quicksort(v, n);
	clock_t end = clock();

	printf("\n %lf ", begin);
	printf("\n %lf ", end);

	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n %lf \n", time_spent);

	printf("\n Trocas: %d\n Comparacoes: %d\n", contador_troca, contador_comparacoes);
    contador_troca = 0;
    contador_comparacoes = 0;


// melhor caso
	printf("\nMelhor Caso");

	begin = clock();
	quicksort(v, n);
	end = clock();

	//printf("\n %lf ", begin);
	//printf("\n %lf ", end);

	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n %lf \n", time_spent);

	printf("\n Trocas: %d\n Comparacoes: %d\n", contador_troca, contador_comparacoes);
    contador_troca = 0;
    contador_comparacoes = 0;



// pior caso
//copiando chave invertida
	for (i = 0; i < n; i++){
		q[i].chave = v[n-i-1].chave;
	}


//	for (i = 0; i < n; i++)
//		printf("%d ", q[i].chave);

	printf("\nPior Caso");

	begin = clock();
	quicksort(q, n);
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
	free(q);
	return 0;
}
