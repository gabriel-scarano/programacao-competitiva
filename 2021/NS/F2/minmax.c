#include <stdio.h>

int somaDigitos (int n)
{   if (n != 0)
        return (n % 10) + somaDigitos(n/10);
}

int main ()
{   int s, a, b, i, min, max;

    scanf(" %d", &s);
    scanf(" %d %d", &a, &b);

    i = a;
    while (somaDigitos(i) != s)
        i++;

    min = i;

    i = b;
    while (somaDigitos(i) != s)
        i--;

    max = i;

    printf("%d\n%d", min, max);

    return 0;
}
