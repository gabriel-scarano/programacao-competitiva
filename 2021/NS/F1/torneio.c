/*
    LINK DO EXERCÍCIO: https://olimpiada.ic.unicamp.br/pratique/ps/2021/f1/torneio/
*/

#include <stdio.h>

int main ()
{   char c;
    int i, vit = 0;

    for (i = 0; i < 6; i++)
    {   scanf(" %c", &c);

        if (c == 'V')
            vit++;
    }

    if (vit == 0)
        printf("-1");
    else if (vit == 1 || vit == 2)
        printf("3");
    else if (vit == 3 || vit == 4)
        printf("2");
    else
        printf("1");

    return 0;
}
