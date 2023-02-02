/*
    LINK DO EXERCÍCIO: https://olimpiada.ic.unicamp.br/pratique/ps/2021/f1/baralho/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{   char s[157];
    int i, j, n, mod, count, flag;
    int **baralho;

    baralho = malloc(4 * sizeof(int));
    for (i = 0; i < 4; i++)
        baralho[i] = calloc(14, sizeof(int));

    scanf("%s", s);

    for (i = 0; i < strlen(s); i++)
    {   mod = i % 3;
        
        if (mod == 0)
            n = (s[i] - '0') * 10;
        else if (mod == 1)
            n += (s[i] - '0');
        else
        {   switch(s[i])
            {   case 'C':
                    baralho[0][n]++;
                    break;
                case 'E':
                    baralho[1][n]++;
                    break;
                case 'U':
                    baralho[2][n]++;
                    break;
                case 'P':
                    baralho[3][n]++;
                    break;
            }
        }
    }

    for (i = 0; i < 4; i++)
    {   count = flag = 0;
        for (j = 1; j < 14 && !flag; j++)
        {   count += baralho[i][j];

            if (baralho[i][j] > 1)
                flag = 1;
        }

        if (flag)
            printf("erro\n");
        else
            printf("%d\n", 13-count);
    }


    for (i = 0; i < 4; i++)
        free(baralho[i]);
    free(baralho);

    return 0;
}
