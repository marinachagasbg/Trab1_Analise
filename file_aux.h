#include <stdio.h>

typedef struct analysis_parameters analysis_parameters;
struct analysis_parameters {
  float best_case_time;
  float middle_case_time;
  float worst_case_time;
  unsigned long long int best_case_swap_quantity;
  unsigned long long int middle_case_swap_quantity;
  unsigned long long int worst_case_swap_quantity;
  unsigned long long int best_case_comparison_quantity;
  unsigned long long int middle_case_comparison_quantity;
  unsigned long long int worst_case_comparison_quantity;
};

extern FILE *fptr;
extern analysis_parameters init_analysis_parameters();
extern int create_file();
extern int open_file();
extern int write_in_file(char *);
extern int write_parameters_in_file(analysis_parameters parameters);
extern float* get_time();
extern analysis_parameters get_parameters();
extern void print_params(analysis_parameters param);
extern void close_file();
