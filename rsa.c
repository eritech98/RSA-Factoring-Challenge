#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool prime(unsigned long long int num);
int main(int argc, char *argv[])
{
    unsigned long long int n = 1;
    unsigned long long int num = 0;
    unsigned long long int div = num;
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
            if (num % i == 0 && prime(i) && prime(num / i))
            {
                div = num / i;
                n = i;
                printf("%lld = %lld * %lld\n", num, div, n);
                break;
            }
        }
        
    }
    fclose(file);

    return 0;
}


bool prime(unsigned long long int num)
{
    int i;

    for (i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

