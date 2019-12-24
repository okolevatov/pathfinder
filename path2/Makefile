NAME = pathfinder

LIBAR = ./libmx/libmx.a

DIROBJ = obj

LIB = ./libmx

SRC = src/main.c \
	src/mx_errors_check.c \
	src/mx_is_digit_line.c \
	src/mx_errors_format.c \
	src/mx_errors_isl.c \
	src/mx_atoi.c \
	src/mx_del_fals.c \
	src/mx_matrix_graph.c \
	src/mx_algorithm.c \
	src/mx_min_number.c \
	src/mx_recovery_alg.c \
	src/mx_same_path2.c \
	src/mx_dist_pr.c \
	src/mx_print_route.c \
	src/mx_test_same.c \
	src/mx_fprint_same.c \
	src/mx_print_same_path.c \
	src/mx_dist_pr_same.c \
	src/mx_first_line.c \
	src/mx_print_sm.c \
	src/mx_del_intarr.c \
	src/mx_free_rout.c \
	src/mx_fix_audit.c \
	src/mx_fix_audit1.c \
	src/mx_helper_errors.c \
	src/mx_helper_matrix.c \
	src/mx_algorithm_helper.c \
	src/mx_helper_same_path.c \
	src/mx_error_space.c \
	src/mx_two.c \
	src/mx_loop.c \
	src/mx_first_zero.c \
	src/mx_creating_arr.c \
	src/mx_free_conc.c \
	src/mx_ne_svyz.c \
	src/mx_is_empty.c \

OUT = main.o \
	mx_errors_check.o \
	mx_is_digit_line.o \
	mx_errors_format.o \
	mx_errors_isl.o \
	mx_atoi.o \
	mx_del_fals.o \
	mx_matrix_graph.o \
	mx_algorithm.o \
	mx_min_number.o \
	mx_recovery_alg.o \
	mx_same_path2.o \
	mx_dist_pr.o \
	mx_print_route.o \
	mx_test_same.o \
	mx_fprint_same.o \
	mx_print_same_path.o \
	mx_dist_pr_same.o \
	mx_first_line.o \
	mx_print_sm.o \
	mx_del_intarr.o \
	mx_free_rout.o \
	mx_fix_audit.o \
	mx_fix_audit1.o \
	mx_helper_errors.o \
	mx_helper_matrix.o \
	mx_algorithm_helper.o \
	mx_helper_same_path.o \
	mx_error_space.o \
	mx_two.o \
	mx_loop.o \
	mx_first_zero.o \
	mx_creating_arr.o \
	mx_free_conc.o \
	mx_ne_svyz.o \
	mx_is_empty.o \
	

INC = inc/pathfinder.h

FLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean
install:
	@make install -C $(LIB)
	@mkdir $(DIROBJ)
	@clang $(FLAGS) $(SRC) -c $(SRC) -I $(INC)
	@mv $(OUT) $(DIROBJ)
	@clang $(FLAGS) $(SRC) $(LIBAR) -o $(NAME) -I $(INC)

uninstall: clean
	@rm -rf $(NAME)
	@make uninstall -C $(LIB)
clean: 	
	@make clean -C $(LIB)
	@rm -rf $(DIROBJ)
	
reinstall: uninstall install 
