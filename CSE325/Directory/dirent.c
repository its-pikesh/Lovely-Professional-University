#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>


int main() {
    DIR * dp;
    struct dirent * dptr;

    mkdir("Faisal", 0777);
    dp = opendir("Faisal");

    while ((dptr = readdir(dp)) != NULL) {
        printf("Name: \t%s\n" \
               "Type: \t%d\n" \
               "Inode number: %llu\n\n", \
               dptr->d_name, dptr->d_type, dptr->d_ino
        );
    }

    exit(EXIT_SUCCESS);
}