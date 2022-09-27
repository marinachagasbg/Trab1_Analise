#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_aux.h"

FILE *fptr;

analysis_parameters init_analysis_parameters() {
  analysis_parameters parameters;
  parameters.best_case_time = 0;
  parameters.middle_case_time = 0;
  parameters.worst_case_time = 0;
  parameters.best_case_swap_quantity = 0;
  parameters.middle_case_swap_quantity = 0;
  parameters.worst_case_swap_quantity = 0;
  parameters.best_case_comparison_quantity = 0;
  parameters.middle_case_comparison_quantity = 0;
  parameters.worst_case_comparison_quantity = 0;
  
  return parameters;
}

int create_file() {
  fptr = fopen("results.bin", "wb");
  
  if(fptr != NULL) {
    return 1;
  }
  
  return 0;
}

int open_file() {
  fptr = fopen("results.bin", "rb");
  if(fptr != NULL) {
    return 1;
  }
  
  return 0;
}

int write_parameters_in_file(analysis_parameters parameters) {
  fseek(fptr, 0, SEEK_SET);
  return fwrite(&parameters, sizeof(analysis_parameters), 1, fptr);
}

int write_in_file(char *result) {
  fseek(fptr, 0, SEEK_END);
  return fwrite(result, strlen(result), 1, fptr);
}

float* get_time() {
  fseek(fptr, 0, SEEK_SET);
  float *times = malloc(3 * sizeof(float));
  
  fread(times, sizeof(float), 3, fptr);
  return times;
}

analysis_parameters get_parameters() {
  fseek(fptr, 0, SEEK_SET);
  analysis_parameters parameters;
  fread(&parameters, sizeof(analysis_parameters), 1, fptr);
  return parameters;
}

void print_params(analysis_parameters param) {
  printf("\nanalysis_parameters obj: {\n");
  printf("\tbest_case_time: %f\n", param.best_case_time);
  printf("\tmiddle_case_time: %f\n", param.middle_case_time);
  printf("\tworst_case_time: %f\n", param.worst_case_time);
  printf("\tbest_case_swap_quantity: %lld\n", param.best_case_swap_quantity);
  printf("\tmiddle_case_swap_quantity: %lld\n", param.middle_case_swap_quantity);
  printf("\tworst_case_swap_quantity: %lld\n", param.worst_case_swap_quantity);
  printf("\tbest_case_comparison_quantity: %lld\n", param.best_case_comparison_quantity);
  printf("\tmiddle_case_comparison_quantity: %lld\n", param.middle_case_comparison_quantity);
  printf("\tworst_case_comparison_quantity: %lld\n", param.worst_case_comparison_quantity);
  printf("}\n");
}

void print_list_params(analysis_parameters *param, int size) {
  for(int i = 0; i < size; i++) {
    print_params(param[i]);
    printf("\n");
  }
}

void close_file() {
  fclose(fptr);
}