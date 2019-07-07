#include <stdio.h>
#include <stdlib.h>    // exit
#include <string.h>    // memset

int
main(int argc, char *argv[])
{
    FILE *fp;
    char buff[5];

    if (argc <= 1) {
        printf("wunzip: file1 [file2 ...]\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 1; i < argc; i++) {
        if ((fp = fopen(argv[i], "r")) == NULL) {
            printf("wunzip: cannot open file\n");
            exit(EXIT_FAILURE);
        }

        memset(buff, 0, strlen(buff));
        while (fread(buff, 4, 1, fp)) {
            int count = *buff;
            memset(buff, 0, strlen(buff));
            fread(buff, 1, 1, fp);
            for (size_t i = 0; i < count; i++) {
                printf("%s", buff);
            }
        }
    }

    return 0;
}
