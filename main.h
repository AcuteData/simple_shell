#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void);

/* Add comd to history */
char *my_strcpy(char *dest, const char *src);
void history(char *input, char **hist_buf, int *hist_count);

#endif
