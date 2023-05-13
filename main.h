#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <signal.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/* HSH */
int main(__attribute__((unused)) int argc, char **argv, char **env);
int handle_input(int argc, char **argv);
void loop(int argc, char **argv);
void handle_empty_input_error(char *prog_name, int c);

/* Add comd to history */
char *my_strcpy(char *dest, const char *src);
void history(char *input, char **hist_buf, int *hist_count);

/* Handle Signal */
void sigint_sig(int sig);

/* Read File */
size_t my_strlen(const char *str);
ssize_t read_file(const char *file_name, char **buffer, size_t buf);

/* Handle Builtin */
int my_strcmp(const char *s1, const char *s2);
int handle_builtin(char **args, char **environ);

/* Parse comd */
char **parse_comd(char *comd);

/* My Getline */
void *_realloc(void *ptr, size_t old_size, size_t new_size);
char *my_getline(const int fd);

/* Handle Comd */
void handle_pwd(void);
void handle_cd(char **comd);
int handle_comd(char **comd, char *input, int argc, char **argv);

/* Print Environment Variable */
void print_environ(char **env);

/* Free mem */
void free_mem(int argc, char **argv);

/* Free all */
void free_all(char **comd, char *input, int null_term);

void _prompt(void);

#endif
