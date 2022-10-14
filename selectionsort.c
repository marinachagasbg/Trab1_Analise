#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "file_aux.h"

typedef struct registro registro;
long long int contador_comparacoes = 0;
long long int contador_troca = 0;

struct registro {
	int chave;
};

void selectionsort (registro* v, int n) {
  int i, j, menor;
  registro temp;
	
  for (i = 0; i < n - 1; i++) {
    menor = i;
    contador_troca++;
		
    for (j = i + 1 ; j < n; j++) { 
      contador_comparacoes++;
      if ( v[j].chave < v[menor].chave) {
        menor = j;
			}
		}
		
    temp = v[menor];
    contador_troca++;
    v[menor] = v[i];
    v[i] = temp;
  }
}

registro *generate_middle_time_array(int array_size) {
	registro *array = (registro *)malloc(array_size * sizeof(registro));
	
	srand(time(NULL));
	
	for (int i = 0; i< array_size; i += 2){
		array[i].chave = i;
		array[i + 1].chave = array_size - i;
	}
	
	return array;
}

registro *generate_worst_time_array(int array_size) {
	registro *array = (registro *)malloc(array_size * sizeof(registro));
	
	for(int i = array_size, j = 0;  i > 0, j < array_size; i --, j++){
		array[j].chave = i;
	}
	
	return array;
}

int main(int argc, char **argv) {
	if(argv[1] == NULL) {
		return 0;
	}
	
	int i = 0, j = 0;
	analysis_parameters parameters = init_analysis_parameters();
	const int array_size = atoi(argv[1]);
	registro *v = generate_middle_time_array(array_size);
	
	create_file();
	
	// CASO MEDIO
	clock_t begin = clock();
	selectionsort(v, array_size);
	clock_t end = clock();
	
	float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
	parameters.middle_case_time = time_spent;
	parameters.middle_case_swap_quantity = contador_troca;
	parameters.middle_case_comparison_quantity = contador_comparacoes;
	contador_troca = 0;
	contador_comparacoes = 0;
	
	// MELHOR CASO
	begin = clock();
	selectionsort(v, array_size);
	end = clock();
	
	time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
	
	parameters.best_case_time = time_spent;
	parameters.best_case_swap_quantity = contador_troca;
	parameters.best_case_comparison_quantity = contador_comparacoes;
	contador_troca = 0;
	contador_comparacoes = 0;
	
	free(v);
	
	// PIOR CASO
	v = generate_worst_time_array(array_size);
	
	begin = clock();
	selectionsort(v, array_size);
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
