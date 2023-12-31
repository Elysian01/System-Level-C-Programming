/*
============================================================================
Name : 27d.c
Author : Abhishek Gupta
Description : Write a program to execute ls -Rl by the following system calls
				a. execl
				b. execlp
				c. execle
				d. execv
				e. execvp
Date: 8th Sept, 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *arr[] = {"ls", "-R", "-l", NULL};
	// v => vector
	execv("/bin/ls", arr);

	return 0;
}
