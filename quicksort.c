#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "file_aux.h"

typedef struct registro registro;

struct registro {
	int chave;
};

unsigned long long contador_comparacoes = 0;
unsigned long long contador_troca = 0;

void partition(int esq, int dir, int *i, int *j, registro *v) {
  registro x, w;
  *i = esq; *j = dir;
	
  //pivô
  x = v[(*i + *j)/2];
	
  do {
    while (x.chave > v[*i].chave) {
			(*i)++;
			contador_comparacoes++;
		}
		
    contador_comparacoes++;
		
    while (x.chave < v[*j].chave) {
			(*j)--;
			contador_comparacoes++;
		}
		
    contador_comparacoes++; // comparação que saiu do loop
		
    if (*i <= *j) {
      w = v[*i];
      v[*i] = v[*j];
      v[*j] = w;
      contador_troca++;
			
      (*i)++;
      (*j)--;
    }
  } while (*i <= *j);
}


void sort(int esq, int dir, registro *v) {
  int i,j;
  partition(esq, dir, &i, &j, v);
  contador_comparacoes++;
  if (esq < j) { 
		sort(esq, j, v);
	}
	
  contador_comparacoes++;
	
  if (i < dir) { 
		sort(i, dir, v);
	}
}

void quicksort(registro *v, int n) {
  sort(0, n-1, v);
}

registro *generate_middle_time_array(int array_size) {
	registro *array = (registro *)malloc(array_size * sizeof(registro));
	
	srand(time(NULL));
	
	for(int i = 0; i < array_size; i++) {
		array[i].chave = rand() % 1000;
	}
	
	return array;
}

registro *generate_worst_time_array(int array_size) {
	registro *array = (registro *)malloc(array_size * sizeof(registro));
	
	for (int i = 0; i < array_size; i++){
		array[i].chave = array[array_size - i - 1].chave;
	}
	
	return array;
}

int main(int argc, char **argv) {
	if(argv[1] == NULL) {
		fprintf(stderr, "error, argv\n");
		return 0;
	}
	
	analysis_parameters parameters = init_analysis_parameters();
	int i = 0, j = 0;
	const int arr_size = atoi(argv[1]);
	registro *v = generate_middle_time_array(arr_size);
	
	create_file();
	
	// CASO MEDIO
	clock_t begin = clock();
	quicksort(v, arr_size);
	clock_t end = clock();
	
	float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
	
	parameters.middle_case_time = time_spent;
	parameters.middle_case_swap_quantity = contador_troca;
	parameters.middle_case_comparison_quantity = contador_comparacoes;
	
	contador_troca = 0;
	contador_comparacoes = 0;
	
	
	// MELHOR CASO
	
	begin = clock();
	quicksort(v, arr_size);
	end = clock();
	
	
	time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
	
	parameters.best_case_time = time_spent;
	parameters.best_case_swap_quantity = contador_troca;
	parameters.best_case_comparison_quantity = contador_comparacoes;
	
	contador_troca = 0;
	contador_comparacoes = 0;
	free(v);
	
	//PIOR CASO
	v = generate_worst_time_array(arr_size);
	begin = clock();
	quicksort(v, arr_size);
	end = clock();
	
	time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
	
	parameters.worst_case_time = time_spent;
	parameters.worst_case_swap_quantity = contador_troca;
	parameters.worst_case_comparison_quantity = contador_comparacoes;
	
	contador_troca = 0;
	contador_comparacoes = 0;
	
	write_parameters_in_file(parameters);
	close_file();
	
	free(v);
	return 0;
}
