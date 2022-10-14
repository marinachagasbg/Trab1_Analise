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

void merge(registro *v, int p, int q, int r) {
	registro *w = (registro *) malloc((r-p+1) * sizeof (registro));
	int i = p;
	int j = q+1;
	int k = 0;
	
	while (i <= q && j <= r) {
		contador_comparacoes++;
		
		if (v[i].chave <= v[j].chave) { 
			w[k++] = v[i++];
		} else { 
			w[k++] = v[j++];
		}
	}
	
	while (i <= q) {
		w[k++] = v[i++];
	}
	
	while (j <= r) {
		w[k++] = v[j++];
	}
	
	for (i = p; i <= r; ++i) {
		v[i] = w[i-p];
		contador_troca++;
	}
	
	free(w);
}

void print_arr(registro *arr, int arr_size) {
	for(int i = 0; i < arr_size; i++) {
		printf("%d ", arr[i].chave);
	}
	
	printf("\n");
}

void mergesort(registro* v,int ini, int fim) {
  int meio;
  if (ini < fim) {
    meio = ( ini + fim ) / 2;
    mergesort(v, ini, meio);
    mergesort(v, meio+1, fim);
    merge(v, ini, meio, fim);
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
	
	for (int i = 0, j = 1; i < array_size / 2; i++, j += 2){
		array[i].chave = j;
	}
	
	for (int i = 1, j = 2; i < array_size; i++, j += 2) {
		array[i].chave = j;
	}
	
	return array;
}

int main(int argc, char **argv) {
	if(argv[1] == NULL) { 
		exit(0);
	}
	
	int i = 0, j = 0;
	const int arr_size = atoi(argv[1]);
	analysis_parameters parameters = init_analysis_parameters();
	registro *v = generate_middle_time_array(arr_size);
	
	create_file();
	
	//CASO MEDIO
	clock_t begin = clock();
	mergesort(v, 0, arr_size - 1);
	clock_t end = clock();
	
	float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
	
	parameters.middle_case_time = time_spent;
	parameters.middle_case_swap_quantity = contador_troca;
	parameters.middle_case_comparison_quantity = contador_comparacoes;
	contador_troca = 0;
	contador_comparacoes = 0;
	
	//MELHOR CASO
	begin = clock();
	mergesort(v, 0, arr_size - 1);
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
	mergesort(v, 0, arr_size - 1);
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