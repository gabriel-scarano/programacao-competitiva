/*
    LINK DO EXERCÍCIO: https://olimpiada.ic.unicamp.br/pratique/ps/2021/f2/poligrama/
*/

#include <stdio.h>
#include <stdlib.h>

int** alocar(int **vet, int n);
int** desalocar(int **vet, int n);
void analisa(int **count, int aux, int n, char *s);
int confereVetor (int **count, int n);

int main ()
{   int n, i, achou = 0;
    char s[100001];
    int **count;

    scanf(" %d", &n);
    scanf(" %s", s);

    for (i = 1; i <= n/2 && !achou; i++)
    {   if (n % i == 0)
        {   count = alocar(count, n/i);
            analisa(count, i, n, s);
            if (confereVetor(count, n/i))
                achou = i;
            count = desalocar(count, n/i);
        }
    }

    if (achou)
    {   for (i = 0; i < achou; i++)
            printf("%c", s[i]);
    } else
        printf("*");

    return 0;
}

int** alocar(int **vet, int n)
{   int i;

    vet = malloc(n*sizeof(int));

    for (i = 0; i < n; i++)
        vet[i] = calloc(26, sizeof(int));

    return vet;
}

int** desalocar(int **vet, int n)
{   int i;

    for (i = 0; i < n; i++)
        free(vet[i]);

    free(vet);

    return vet;
}

void analisa(int **count, int aux, int n, char *s)
{   int i, j;

    for (i = 0; i < n/aux; i++)
        for (j = aux * i; j < (aux*i) + (aux); j++)
            count[i][s[j]-97]++;
}

int confereVetor (int **count, int n)
{   int i, j;

    for (i = 0; i < n-1; i++)
        for (j = 0; j < 26; j++)
            if (count[i][j] != count[i+1][j])
                return 0;

    return 1;
}
