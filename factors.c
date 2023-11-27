#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    unsigned long long int num = 0;
    unsigned long long int div = num;
    unsigned long long int n = 1;
    FILE *file;
    char buffer[1000];
    char *end = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: factors <file>\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error opening %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        fgets(buffer, 1000, file);
        if (feof(file) || ferror(file)) break;
        num = strtoull(buffer, &end, 10);
    
        for (int i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                div = num / i;
                n = i;
                printf("%lld = %lld * %lld\n", num, div, n);
                break;
            }
        }
    }

    return 0;
}