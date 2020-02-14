#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **str1, char **str2)
{
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

void print_str_arr(char **s, int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t", *(s + i));
    }
    printf("\n");
}

int next_permutation(int n, char **s) {
    
}

void main()
{
    int n;
    scanf("%d", &n);
    char **s = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        *(s + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(s + i));
        *(s + i) = realloc(*(s + i), strlen(*(s + i)));
    }
    
}