#ifndef PATHFINDER
#define PATHFINDER

int mx_errors_check(int argcc, const char *argvv);
int mx_is_digit_line(const char *p);
int mx_errors_format(const char *argvv);
char **mx_errors_isl(const char *str1);
int mx_atoi(const char *str);
char *mx_del_fals(const char *str);
int **mx_matrix_graph(char *file, char **ostrovi);
void mx_algorithm(int **matrix, char *str, char **ostrovi);
int mx_min_number(int *dest, int kilkist, int *vis);
int **mx_recovery_alg(int kilkist, int *dest, int begin, int **matrix);
int *mx_same_path2(int **matrix, int end, int *dest, int *kil_b);
int mx_dist_pr(int **matrix, int **recover, int p, int i);
void mx_print_route(char **ostrovi, int **matrix, int **recover, int **conc1);
int mx_test_same(int *dest, int **matr, int end, int kilkist);
void mx_print_same_path(char **ostrovi, int **matrix, int *arr, int *recover);
int *mx_fprint_same(int kilkist, int *recover);
int mx_dist_pr_same(int **matrix, int *recover, int i);
int mx_first_line(const char *argvv);
void mx_print_sm(int i, int **recover, char **ostrovi, int arr);
void mx_del_intarr(int ***arr, int n);
void mx_free_rout(int *new, int *sf_same);
void mx_fix_audit(int *k_l_con, char **splite, int kilkisto);
char **mx_fix_audit1(int *k_l_con, char **splite, char **arr, int kilkisto);
char **mx_helper_errors(int *k_l_con_i, char *str, int kilkisto);
int *mx_helper_matrix(int *rc_coc, char **arrchek, char **ostrovi, int i);
int *mx_algorithm_helper(int *min_mindex, int *vis, int **matrix, int *dest);
int mx_hpath(int *dest, int *bwsvk_eik, int *buffarr, int **matrix);
void mx_error_space(char str, int count_n);
void mx_two(char a, char b, int count_n);
void mx_loop(const char *str1);
void mx_first_zero(char *str);
int **mx_creating_arr(int *arr, int *alcopy, int kilkist);
void mx_free_conc(int ***conc);
void mx_ne_svyz(int *en_b_w_k_b);
void mx_is_empty(const char *argvv);

#endif
