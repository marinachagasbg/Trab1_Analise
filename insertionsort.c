#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include "file_aux.h"

typedef struct registro registro;
unsigned long long int contador_comparacoes = 0;
unsigned long long int contador_troca = 0;

	// int count_overflow_swap = 0;
	// int count_overflow_comparison = 0;
	// const long billion = 1000000000;

struct registro {
	int chave;
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


int main(int argc, char **argv) {
	registro *v;
	int i = 0, j =0;
	if(argv[1] == NULL) {
		exit(0);
	}
	
	const int n = atoi(argv[1]);

	srand(time(NULL));

	v = malloc (sizeof(registro)*n);

	for (i = 0; i < n; i++){
		v[i].chave = rand() % 1000;
	}

	analysis_parameters parameters = init_analysis_parameters();
	create_file();

	//CASO MEDIO

	clock_t begin = clock();
	insertionsort(v, n);
	clock_t end = clock();

	float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;

	parameters.middle_case_time = time_spent;
	parameters.middle_case_swap_quantity = contador_troca;
	parameters.middle_case_comparison_quantity = contador_comparacoes;
	
	contador_troca = 0;
	contador_comparacoes = 0;


	//MELHOR CASO
	begin = clock();
	insertionsort(v, n);
	end = clock();

	time_spent = (float)(end - begin) / CLOCKS_PER_SEC;

	parameters.best_case_time = time_spent;
	parameters.best_case_swap_quantity = contador_troca;
	parameters.best_case_comparison_quantity = contador_comparacoes;
	contador_troca = 0;
	contador_comparacoes = 0;

	//PIOR CASO

	for(i = n, j = 0 ;  i > 0, j < n; i--, j++){
		v[j].chave = i-1;
	}

	
	begin = clock();
	insertionsort(v, n);
	end = clock();

	time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
	parameters.worst_case_time = time_spent;
	parameters.worst_case_swap_quantity = contador_troca;
	parameters.worst_case_comparison_quantity = contador_comparacoes;
	
	write_parameters_in_file(parameters);

	close_file();
	free(v);
	return 0;
}
