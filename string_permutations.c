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

int next_permutation(int n, char **s)
{
    // Step - 1
    // Find i such that s[i-1] < s[i]
    int i = n - 1;
    for (i = n - 1; i >= 1; i--)
    {
        if (strcmp(*(s + i), *(s + (i - 1))) > 0)
        {
            break;
        }
    }
    // Step - 2
    // If i == 0, then array is in decending order, no more permutations possible.
    if (!i)
    { // if i == 0 then treat it as 1 and return 0
        return 0;
    }
    // Step - 3
    // Find j such that, s[i-1] < s[j] && j < i
    int j;
    for (j = n - 1; j >= 1; j--)
    {
        if (strcmp(*(s + j), *(s + (i - 1))) > 0)
        {
            break;
        }
    }
    // Step - 4
    // Swap s[i-1] & s[j]
    swap((s + (i - 1)), (s + j));
    // Step - 5
    // Reverse the s[i..n)
    j = n - 1;
    while (i < j)
    {
        swap((s + i), (s + j));
        i++;
        j--;
    }
    return 1;
}

void main()
{
    int n;
    scanf("%d", &n);
    // char **s = (char **)malloc(n * sizeof(char *));
    char **s = calloc(n, sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        *(s + i) = calloc(20,sizeof(char));
        scanf("%s", *(s + i));
        *(s + i) = realloc(*(s + i), strlen(*(s + i)));
    }
    do
    {
        print_str_arr(s, n);
    } while (next_permutation(n, s));
}