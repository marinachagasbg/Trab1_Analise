#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include "file_aux.h"

typedef struct registro registro;
unsigned long long int contador_comparacoes = 0;
unsigned long long int contador_troca = 0;

struct registro {
	int chave;
};

void insertionsort (registro* v, int n ) {
  int i, j;
  registro temp;
	
  for (i = 1; i < n; i++) {
    temp = v[i];
    j = i - 1;
		
    while ((j >= 0) && (temp.chave < v[j].chave)) { //uma comparação é feita aqui
      contador_comparacoes++;
      v[j + 1] = v[j];
      contador_troca++;
      j--;
    }
		
    contador_comparacoes++;
    v[j + 1] = temp;
    contador_troca++;
  }
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
	
	for(int i = array_size, j = 0 ;  i > 0, j < array_size; i--, j++) {
		array[j].chave = i-1;
	}
	
	return array;
}

int main(int argc, char **argv) {
	if(argv[1] == NULL) {
		exit(0);
	}
	
	int i = 0, j =0;
	const int arr_size = atoi(argv[1]);
	registro *v = generate_middle_time_array(arr_size);
	
	for (i = 0; i < arr_size; i++) {
		v[i].chave = rand() % 1000;
	}
	
	analysis_parameters parameters = init_analysis_parameters();
	create_file();
	
	//CASO MEDIO
	clock_t begin = clock();
	insertionsort(v, arr_size);
	clock_t end = clock();
	
	float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
	
	parameters.middle_case_time = time_spent;
	parameters.middle_case_swap_quantity = contador_troca;
	parameters.middle_case_comparison_quantity = contador_comparacoes;
	
	contador_troca = 0;
	contador_comparacoes = 0;
	
	
	//MELHOR CASO
	begin = clock();
	insertionsort(v, arr_size);
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
	insertionsort(v, arr_size);
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
