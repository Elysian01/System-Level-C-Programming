/*
============================================================================
Name : 27b.c
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
	// lp => yaha par path of cmd deni ki jarurat nhi hai
	execlp("ls", "ls", "-R", "-l", NULL);

	return 0;
}
