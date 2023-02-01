/*
    LINK DO EXERCÍCIO: https://olimpiada.ic.unicamp.br/pratique/ps/2021/f2/tenis/
*/

#include <stdio.h>

int main ()
{   int vet[4], i, j, key;

    scanf("%d %d %d %d", &vet[0], &vet[1], &vet[2], &vet[3]);

    for (i = 1; i < 4; i++)
    {   key = vet[i];
        j = i - 1;

        while (j >= 0 && vet[j] > key)
        {   vet[j+1] = vet[j];
            j = j - 1;
        }

        vet[j+1] = key;
    }

    printf("%d", vet[3] + vet[0] - vet[2] - vet[1]);

    return 0;
}
