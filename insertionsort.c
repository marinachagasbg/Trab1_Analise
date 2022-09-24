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

void insertionsort (registro* v, int n )
{
  int i,j;
  registro temp;
  for (i = 1; i < n; i++)
  {
    temp = v[i];
    j = i - 1;
    while ( ( j >= 0 ) && ( temp.chave < v[j].chave ) ) //uma comparação é feita aqui
    {
      contador_comparacoes++;
      v[j + 1] = v[j]; // troca
      contador_troca++;
      j--;
    }
    contador_comparacoes++; //última comparação foi feita para sair do loop
    v[j + 1] = temp; //troca: resgata do armazenamento temporário
    contador_troca++;
  }
}


int main()
{
	//registro v[500000];
	registro *v;
	int i = 0, j =0;
	const int n = 50000;

	//srand(time(NULL));
	srand(1);

	v = malloc (sizeof(registro)*n);
	if (v==NULL){
		printf("Nao foi possivel alocar");
	}


//--------------------------------------------------------------------
//		Random vector


	for ( i =0; i< n ;i+=2){
		v[i].chave = i;
		v[i+1].chave = n-i;

	}

	/*
	for (i = 0; i < n/2; i++) {
		//v[i].chave = rand() % n;
		v[i].chave = i;
		//printf("%d ", v[i].chave);
	}
	for (j = n , i = n/2; i < n, j > n/2; j--, i++){
  		v[i].chave = j;
	}*/




//--------------------------------------------------------------------

// caso medio

	printf("Caso medio \n");

	clock_t begin = clock();
	insertionsort(v, n);
	clock_t end = clock();

	printf("\n %lf ", begin);
	printf("\n %lf ", end);

	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n %lf \n", time_spent);

	printf("\n Trocas: %d\n Comparacoes: %d", contador_troca, contador_comparacoes);
    contador_troca = 0;
    contador_comparacoes = 0;



// melhor caso
	printf("\nMelhor Caso");

	begin = clock();
	insertionsort(v, n);
	end = clock();

	//printf("\n %lf ", begin);
	//printf("\n %lf ", end);

	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n %lf \n", time_spent);

	printf("\n Trocas: %d\n Comparacoes: %d", contador_troca, contador_comparacoes);
    contador_troca = 0;
    contador_comparacoes = 0;


// pior caso

	for( i = n, j = 0 ;  i > 0, j < n; i --, j ++){
		v[j].chave = i-1;
	}

//	for (i = 0; i < n; i++)
//		printf("%d ", v[i].chave);

	printf("\nPior Caso");

	begin = clock();
	insertionsort(v, n);
	end = clock();

	//printf("\n %lf ", begin);
	//printf("\n %lf ", end);

	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n %lf \n", time_spent);
    printf("\n Trocas: %d\n Comparacoes: %d", contador_troca, contador_comparacoes);


//--------------------------------------------------------------------
	free(v);
	return 0;
}
