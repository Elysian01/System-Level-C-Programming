/*
============================================================================
Name : 11.c
Author : Abhishek Gupta
Description : Write a program to open a file, duplicate the file descriptor and
              append the file with both the descriptors and check whether the file
              is updated properly or not.
                a. use dup
                b. use dup2
                c. use fcntl
Date: 28th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("1 arguments are required\n");
        return 0;
    }
    int fd, fd1, fd2, fd3;
    fd = open(argv[1], O_CREAT | O_EXCL | O_WRONLY | O_APPEND, 0777);
    if (fd < 0)
    {
        printf("Problem in opening the file");
        return 0;
    }
    // dup, will create the duplicate of file descriptor with availabe FD numbers
    // we have 3 system calls to do this operation
    // fcntl, dup, dup2
    // fcntl and dup is same it will create a new FD say 6, which will point to the contents of the input FD
    // in dup2, we can specify the FD value explicitly, like below we specically want 7 as FD value
    fd1 = fcntl(fd, F_DUPFD, 9);
    if (fd1 == -1)
    {
        printf("Problem in duplicating fd using fcntl");
        return 0;
    }
    write(fd1, "Welcome\n", 8);

    fd2 = dup(fd);
    if (fd2 == -1)
    {
        printf("Problem in duplicating fd using dup");
        return 0;
    }
    write(fd1, "to\n", 3);

    fd3 = dup2(fd, 7);
    if (fd3 == -1)
    {
        printf("Problem in duplicating fd using dup2");
        return 0;
    }
    write(fd1, "SS Lab\n", 7);
    getchar();

    // while (1)
    //     ;

    // ./a.out filename &
    // ll /proc/<pid>/fd  => to check the linkage

    // close(fd);
    // close(fd1);
    // close(fd2);
    // close(fd3);
}