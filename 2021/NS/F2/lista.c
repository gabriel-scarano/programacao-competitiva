/*
    LINK DO EXERCÍCIO: https://olimpiada.ic.unicamp.br/pratique/ps/2021/f2/lista/corrige/
*/

#include <stdio.h>
#include <stdlib.h>

int verificaPalindromo (int *vet, int n)
{   int i;

    for (i = 0; i < n/2; i++)
        if (vet[i] != vet[n-1-i])
            return i;

    return -1;
}

void moveVetor (int *vet, int ind, int n)
{   int i;
    for (i = ind; i < n-1; i++)
        vet[i] = vet[i+1];
}

int main ()
{   int *vet, n, i, ind, count = 0;

    scanf(" %d", &n);

    vet = malloc (n * sizeof(int));

    for (i = 0; i < n; i++)
        scanf(" %d", &vet[i]);

    while ((ind = verificaPalindromo(vet, n)) != -1)
    {   if (vet[ind] < vet[n-1-ind])
        {   vet[ind] = vet[ind] + vet[ind+1];
            moveVetor(vet, ind+1, n);
        } else {
            vet[n-2-ind] = vet[n-2-ind] + vet[n-1-ind];
            moveVetor(vet, n-1-ind, n);
        }
        --n;
        ++count;
    }

    printf("%d", count);

    return 0;
}
