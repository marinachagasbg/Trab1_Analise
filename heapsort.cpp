/*
  Recebe o arquvio:
      feat-matrix.txt 
      
  Gera os arquivos de features ordenadas:
      (rank_f) + arquivo de id(rank_f_id)
*/

#include <stdlib.h>
#include <sys/timeb.h>
#include <iostream>
#include <vector>
#include <omp.h> // Teste para tentar paralelizar
extern "C" {
  #include "file_aux.h"
}

using namespace std;

int trocas = 0;
int comparacoes = 0;

// --------------------------------------- HEAP SORT ------------------------------------------------------------------------

void exchange(vector<float>& distances, vector<int>& curRk, int i, int j) {
  //Distances
  float t = distances[i];
  distances[i] = distances[j];
  distances[j] = t;
  //Ranked Lists
  int trk = curRk[i];
  curRk[i] = curRk[j];
  curRk[j] = trk;

  trocas = trocas + 1;
}

void downheapDist(vector<float>& distances, vector<int>& curRk, int n, int v) {
  int w = 2 * v + 1; //first descendant of v
  while (w < n) {
    comparacoes += 1;
    if (w + 1 < n) {
      if (distances[w + 1] > distances[w]) {
        comparacoes += 1;
        w++;
      }
    } 
    if (distances[v] >= distances[w]) {
      comparacoes += 1;
      return;
    }
    exchange(distances, curRk, v, w);
    v = w;
    w = 2 * v + 1;
  }
  comparacoes += 1;
}


void buildheap(vector<float>& distances, vector<int>& curRk, int n) {
  for (int v = n / 2 - 1; v >= 0; v--) {  // não sei se v = n ou v = features
    comparacoes += 1;
    downheapDist(distances, curRk, n, v);  
  }
}

void heapsort(vector<float>& distances, vector<int>& curRk, int n) {
  buildheap(distances, curRk, n);
  while (n > 1) {
    comparacoes += 1;
    n--;
    exchange(distances, curRk, 0, n);

    downheapDist(distances, curRk, n, 0);
    
  }
  comparacoes += 1;
}


void mainHeapSort( float*& matrix, vector<float>& feat_list, vector<int>& rkLists, int n, int features) {
  for (int rk = 0; rk < features; rk++) {
    comparacoes += 1;
  
    vector<float> distances(n);
    vector<int> curRk(n);
    #pragma omp parallel for
    for (int j = 0; j < n; j++) {
      curRk[j] = j;
      distances[j] = matrix[features*j+rk];
    }
    heapsort(distances, curRk, n);
    
    for (int j = 0; j < n; j++) {
      rkLists[n*rk+j] = curRk[j];
      feat_list[n*rk+j] = distances[j];                
    }        
  }
}
// --------------------------------------------------------------------------------------------------------------------------

float* initMatrix(int n,int features) {
  cout << "\t - Intializing Feature Matrix ..." << endl;

  float* matrix = NULL;
  long int nN = ((long int) n)*features;
  matrix = new float[nN]();  //initialize all values to zero, but allocate memory immediately

  cout << "\t - Matrix Successfully Initialized ..." << endl;

  return matrix;
}
// --------------------------------------------------------------------------------------------------------------------------

int main(int argc, char *argv[]) 
{
  if (argc < 2){
      exit(1);
  }

  int i,j;
  int n = atoi(argv[1]);              
  int features = 1;        
  float* matrix = initMatrix(n,features);
  
  FILE *report;

  report = fopen("./report.txt","w");

  // init ranked lists
  //vector<int> rkLists;

  vector<int> rkLists(n*features);
  vector<float> feat_list(n*features);
  
  for (int i = 0; i < features; i++) {
    for (int j = 0; j < n; j++) {
      rkLists[i*n+j] = j;
    }
  }

  // CRIANDO O VETOR QUE VAI SER ORDENADO:

  srand(time(NULL));                      // Gerando aleatório

  for (int i = 0; i < n*features; i++) {
    matrix[i] = rand() % 100; 
  }

  // -------------------------------------

  // Ordenando

  struct timeb start,end;
  float diff;
  analysis_parameters parameters;

	create_file();

  ftime(&start);

  mainHeapSort(matrix, feat_list, rkLists, n, features);

  ftime(&end);

  diff = (float) (1000* (end.time - start.time) + (end.millitm - start.millitm));
  diff = diff/1000; 

  printf("\nTamanho do vetor: %d\n", n);
  printf("Tempo gasto (heap-sort): %lf segundos\n",diff);
  printf("Número de trocas: %d\n", trocas);
  printf("Número de comparações: %d\n", comparacoes);

  fprintf(report,"\n  Tamanho do vetor: %d", n);
  fprintf(report,"\n  Tempo de Ordenação: %f segundos",diff);
  fprintf(report,"\n  Número de trocas: %d", trocas);
  fprintf(report,"\n  Número de comparações: %d", comparacoes);
  
  parameters.best_case_time = diff;
  parameters.middle_case_time = diff;
  parameters.worst_case_time = diff;
  parameters.best_case_comparison_quantity = comparacoes;
  parameters.middle_case_comparison_quantity = comparacoes;
  parameters.worst_case_comparison_quantity = comparacoes;
  parameters.best_case_swap_quantity = trocas;
  parameters.middle_case_swap_quantity = trocas;
  parameters.worst_case_swap_quantity = trocas;
  
  write_parameters_in_file(parameters);

	close_file();


  // PRINT DA MATRIZ ORDENADA

  // for (int i = 0; i < n*features; i++) {
  //     printf("%d ",(int)matrix[i]);
  // }


  fclose(report);
  return 0;
}


/* Comandos 
diff arq1.txt arq2.txt

awk -F 'caractere''{print NF;exit}' teste.txt

*/
