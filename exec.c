#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "file_aux.h"

int spawn (char* program, char** arg_list) {
  pid_t child_pid;
  child_pid = fork();
  
  if (child_pid != 0) { 
    return child_pid;
  }else {
    execvp(program, arg_list);
    waitpid(child_pid, NULL, 0);
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

int main(int argc, char **argv) {
  const int EXEC_QUANTITY = 10;
  char prog_name[20];
  analysis_parameters params[EXEC_QUANTITY];
  memset(params, 0, EXEC_QUANTITY * sizeof(analysis_parameters));
  
  if(argv[1] != NULL) { 
    memmove(prog_name, "./", strlen("./") + 1);
    memmove(prog_name + strlen(prog_name), argv[1], strlen(argv[1]) + 1);
    printf("%s\n", prog_name);
    
    for(int i = 0; i < EXEC_QUANTITY; i++) {
      printf("===============execuçao %d===============", i + 1);
      open_file();
      spawn(prog_name, NULL);
      wait(NULL);
      params[i] = get_parameters();
      print_params(params[i]);
      close_file();
      sleep(1);
    }
    printf("===============result===============\n");
    analysis_parameters average_params = calc_analysis_average(params, EXEC_QUANTITY);
    print_params(average_params);
  } else {
    printf("esqueceu de passar argv!\n");
  }
  
  return 0;
}