#include "get_next_line.h"
#include <stdio.h>

int    main(int ac, char **av)
{
    char    *lol;
    int        fd1 = 0;
    int        fd2;
    int        fd3;
    int        ret;

    ret = 1;
    if (ac == 1)
        while (ret == 1)
        {
            ret = get_next_line(0, &lol);
            printf("%s\n", lol);
            free(lol);
            lol = NULL;
        }
    else if (ac == 2)
    {
        fd1 = open(av[1] ,O_RDONLY);
        while (ret == 1)
        {
            ret = get_next_line(fd1, &lol);
            if (ret == 1)
                printf("%s\n", lol);
            else if (ret == 0)
                printf("%s", lol);
            free(lol);
            lol = NULL;
        }
    }
    else if (ac == 4)
    {
        fd1 = open(av[1] ,O_RDONLY);
        fd2 = open(av[2] ,O_RDONLY);
        fd3 = open(av[3] ,O_RDONLY);
        ret = get_next_line(fd1, &lol);
        if (ret == 1)
            printf("%s\n", lol);
        else if (ret == 0)
            printf("%s", lol);
        free(lol);
        if (ret != 1)
            return (0);
        ret = get_next_line(fd2, &lol);
        if (ret == 1)
            printf("%s\n", lol);
        else if (ret == 0)
            printf("%s", lol);
        free(lol);
        if (ret != 1)
            return (0);
        ret = get_next_line(fd3, &lol);
        if (ret == 1)
            printf("%s\n", lol);
        else if (ret == 0)
            printf("%s", lol);
        free(lol);
        close(fd2);
        close(fd3);
    }
    if (ac == 1)
        system ("leaks a.out | grep 'leaked'");
    close(fd1);
    return (0);
}
