#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool prime(unsigned long long int number);
int main(int argc, char *argv[])
{
    unsigned long long int n = 1;
    unsigned long long int number = 0;
    unsigned long long int div_ = number;
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
        number = strtoull(buffer, &end, 10);

        for (int i_ = 2; i_< number; i_++)
        {
            if (number % i_ == 0 && prime(i_) && prime(number / i_))
            {
                div_ = number / i_;
                n = i_;
                printf("%lld = %lld * %lld\n", number, div_, n);
                break;
            }
        }
        
    }
    fclose(file);

    return 0;
}


bool prime(unsigned long long int number)
{
    int i_;

    for (i_ = 2; i_ < number; i_++)
    {
        if (number % i_ == 0)
        {
            return false;
        }
    }
    return true;
}

