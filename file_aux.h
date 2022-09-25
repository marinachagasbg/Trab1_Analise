#include <stdio.h>

typedef struct analysis_parameters analysis_parameters;
struct analysis_parameters {
  float best_case_time;
  float middle_case_time;
  float worst_case_time;
  int best_case_swap_quantity;
  int middle_case_swap_quantity;
  int worst_case_swap_quantity;
  int best_case_comparison_quantity;
  int middle_case_comparison_quantity;
  int worst_case_comparison_quantity;
};

extern FILE *fptr;
int create_file();
int open_file();
int write_in_file(char *);
int write_parameters_in_file(analysis_parameters parameters);
float* get_time();
analysis_parameters get_parameters();
void print_params(analysis_parameters param);
void close_file();
