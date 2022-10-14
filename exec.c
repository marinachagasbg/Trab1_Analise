#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "file_aux.h"

#define ENTRY_QUANTITY 19

int spawn (char* program, char** arg_list) {
  pid_t chilld_pid;
  chilld_pid = fork();
  
  if (chilld_pid != 0) { 
    return chilld_pid;
  }else {
    execvp(program, arg_list);
    wait(NULL);
    fprintf (stderr, "\num erro ocorreu em execvp\n");
    abort ();
  }
}

float calc_average(float *arr, int n) {
  float sum = 0;
  for(int i = 0; i < n; i++) {
    sum += arr[i];
  }
  
  return sum / n;
}

float somatorio(float *arr, int initial_index, int final_index) {
  float sum = 0.0;
  
  if(initial_index < final_index) {    
    for(int i = initial_index; i < final_index; i++) {
      sum += arr[i];
    }
  }
  
  return sum;
}

float *get_float_parameter_array(analysis_parameters *arr, int array_size, parameters_t parameter) {
  float *parameter_list = (float *)malloc(array_size * sizeof(float));
  memset(parameter_list, 0, sizeof(parameter_list));
  
  switch (parameter) {
    case 1:
      for(int i = 0; i < array_size; i++) {
        parameter_list[i] = arr[i].best_case_time;
      }
    break;
    
    case 2:
      for(int i = 0; i < array_size; i++) {
        parameter_list[i] = arr[i].middle_case_time;
      }
      
    break;
    
    case 3:
      for(int i = 0; i < array_size; i++) {
        parameter_list[i] = arr[i].worst_case_time;
      }
    break;
  }
  
  return parameter_list;
}

float media(float *arr, int size) {
  float sum = somatorio(arr, 0, size);
  
  return sum / size;
}

float standard_deviation(float *arr, double media, int arr_size) {
  float sum = 0.0;
  
  for(int i = 0; i < arr_size; i++) {
    float diff = arr[i] - media;
    float pow_of_diff = pow(diff, 2);
    sum += pow_of_diff;
  }
  
  float div = sum / (arr_size);
  float desvio = sqrt(div);
  return desvio;
}

analysis_parameters calc_analysis_average(analysis_parameters *params, int size) {
  analysis_parameters average_params;
  memset(&average_params, 0, sizeof(average_params));
  
  for(int i = 0; i < size; i++) {
    average_params.best_case_time += params[i].best_case_time;
    average_params.middle_case_time += params[i].middle_case_time;
    average_params.worst_case_time += params[i].worst_case_time;
    average_params.best_case_comparison_quantity += params[i].best_case_comparison_quantity;
    average_params.middle_case_comparison_quantity += params[i].middle_case_comparison_quantity;
    average_params.worst_case_comparison_quantity += params[i].worst_case_comparison_quantity;
    average_params.best_case_swap_quantity += params[i].best_case_swap_quantity;
    average_params.middle_case_swap_quantity += params[i].middle_case_swap_quantity;
    average_params.worst_case_swap_quantity += params[i].worst_case_swap_quantity;
  }
  
  average_params.best_case_time /= size;
  average_params.middle_case_time /= size;
  average_params.worst_case_time /= size;
  average_params.best_case_comparison_quantity /= size;
  average_params.middle_case_comparison_quantity /= size;
  average_params.worst_case_comparison_quantity /= size;
  average_params.best_case_swap_quantity /= size;
  average_params.middle_case_swap_quantity /= size;
  average_params.worst_case_swap_quantity /= size;
  
  return average_params;
}

void write_final_results(analysis_parameters *result_parameters, int exec_quantity) {
  char results[150];
  create_file();
  for(int i = 0; i < exec_quantity; i++) {
    memset(results, 0, sizeof(results));
    sprintf(results, "bt: %f | mt: %f | wt: %f | bs: %lld | ms: %lld | ws: %lld | bc: %lld | mc: %lld | wc: %lld\n", 
      result_parameters[i].best_case_time,
      result_parameters[i].middle_case_time,
      result_parameters[i].worst_case_time,
      result_parameters[i].best_case_swap_quantity,
      result_parameters[i].middle_case_swap_quantity,
      result_parameters[i].worst_case_swap_quantity,
      result_parameters[i].best_case_comparison_quantity,
      result_parameters[i].middle_case_comparison_quantity,
      result_parameters[i].worst_case_comparison_quantity
    );
    write_in_file(results);
  }
  close_file();
}

int main(int argc, char **argv) {
  const int EXEC_QUANTITY = 10;
  char prog_name[20];
  char exec_prog_command[20];
  int entry_sizes[ENTRY_QUANTITY] = {
    1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000,
    10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 
    90000, 100000
  };
  analysis_parameters final_results[ENTRY_QUANTITY];
  
  analysis_parameters params[EXEC_QUANTITY];
  
  if(argv[1] != NULL) { 
    memmove(prog_name, argv[1], strlen(argv[1]) + 1);
    memmove(exec_prog_command, "./", strlen("./") + 1);
    memmove(exec_prog_command + strlen(exec_prog_command), argv[1], strlen(argv[1]) + 1);
    create_generic_file("desvios.txt");
    
    char size_arg[7];
    
    for(int j = 0; j < ENTRY_QUANTITY; j++) {
      sprintf(size_arg, "%d", entry_sizes[j]);
      char *args[3] = {prog_name, size_arg, NULL};
      memset(params, 0, EXEC_QUANTITY * sizeof(analysis_parameters));
      
      for(int i = 0; i < EXEC_QUANTITY; i++) {
        printf("tamanho: %d\n", entry_sizes[j]);
        printf("===============execuçao %d===============", i + 1);
        spawn(exec_prog_command, args);
        wait(NULL);
        open_file();
        params[i] = get_parameters();
        print_params(params[i]);
        close_file();
        sleep(1);
      }
      
      printf("===============result===============\n");
      final_results[j] = calc_analysis_average(params, EXEC_QUANTITY);
      print_params(final_results[j]);
      
      float *best_case_time_list = get_float_parameter_array(params, EXEC_QUANTITY, 1);
      float *middle_case_time_list = get_float_parameter_array(params, EXEC_QUANTITY, 2);
      float *worst_case_time_list = get_float_parameter_array(params, EXEC_QUANTITY, 3);
      float best_case_time_standard_deviation = standard_deviation(best_case_time_list, media(best_case_time_list, EXEC_QUANTITY), EXEC_QUANTITY);
      float middle_case_time_standard_deviation = standard_deviation(middle_case_time_list, media(middle_case_time_list, EXEC_QUANTITY), EXEC_QUANTITY);
      float worst_case_time_standard_deviation = standard_deviation(worst_case_time_list, media(worst_case_time_list, EXEC_QUANTITY), EXEC_QUANTITY);
      
      printf("best_case_time_standard_deviation = %f\n", best_case_time_standard_deviation);
      printf("middle_case_time_standard_deviation = %f\n", middle_case_time_standard_deviation);
      printf("worst_case_time_standard_deviation = %f\n", worst_case_time_standard_deviation);
      
      char buffer[150];
      sprintf(buffer, "bt: %f | mt: %f | wt: %f\n", best_case_time_standard_deviation, middle_case_time_standard_deviation, worst_case_time_standard_deviation);
      
      open_generic_file("desvios.txt");
      write_in_generic_file(buffer);
      close_generic_file();
      
      memset(buffer, 0, sizeof(buffer));
      memset(size_arg, 0, sizeof(size_arg));
      
      free(best_case_time_list);
      free(middle_case_time_list);
      free(worst_case_time_list);
    }
    
    write_final_results(final_results, ENTRY_QUANTITY);
  } else {
    printf("esqueceu de passar argv!\n");
  }
  
  return 0;
}