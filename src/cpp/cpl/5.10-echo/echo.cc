//
// Created by suzumiya on 10/2/19.
//

#include <cstdio>

int main(int argc, char *argv[])
{
    while(argc-- > 1)
//        printf("%s%s", *++argv, (argc > 1)?" ":"");
        printf(argc > 1 ? "%s ":"%s", *++argv);

    printf("\n");
    return 0;
}