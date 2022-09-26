#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "file_aux.h"

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

int main(int argc, char **argv) {
	registro *v, *q;
	int i = 0, j = 0;
	
	if(argv[1] == NULL) { 

		exit(0);
	}

	const int n = atoi(argv[1]);

	//srand(time(NULL));
	srand(1);

	v = malloc (sizeof(registro)*n);
	if (v==NULL){

	}

	q = malloc (sizeof(registro)*n);
	if (q==NULL){

	}

//--------------------------------------------------------------------
//		Random vector

	for (i = 0; i < n; i++) {
		v[i].chave = rand() % 100;

	}



//--------------------------------------------------------------------
	analysis_parameters parameters = init_analysis_parameters();

	create_file();
	
	//CASO MEDIO
	clock_t begin = clock();
	mergesort(v, 0, n-1);
	clock_t end = clock();
	
	float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
	
	parameters.middle_case_time = time_spent;
	parameters.middle_case_swap_quantity = contador_troca;
	parameters.middle_case_comparison_quantity = contador_comparacoes;
	contador_troca = 0;
	contador_comparacoes = 0;
	
	//MELHOR CASO
	begin = clock();
	mergesort(v, 0, n-1);
	end = clock();
	
	time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
	
	parameters.best_case_time = time_spent;
	parameters.best_case_swap_quantity = contador_troca;
	parameters.best_case_comparison_quantity = contador_comparacoes;
	contador_troca = 0;
	contador_comparacoes = 0;
	
	//PIOR CASO	
	for (i = 0; i < n; i++){
		q[i].chave = v[n-i-1].chave;
	}
	
	begin = clock();
	mergesort(q, 0, n-1);
	end = clock();
	
	time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
	
	parameters.worst_case_time = time_spent;
	parameters.worst_case_swap_quantity = contador_troca;
	parameters.worst_case_comparison_quantity = contador_comparacoes;
	contador_troca = 0;
	contador_comparacoes = 0;
	
	write_parameters_in_file(parameters);

	close_file();


//--------------------------------------------------------------------
	free(v);
	return 0;
}

