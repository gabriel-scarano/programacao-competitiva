/*
    LINK DO EXERCÍCIO: https://olimpiada.ic.unicamp.br/pratique/ps/2021/f1/tempo/
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int i, tempo;
    char tipo;
    struct lista *prox;
} Lista;

void imprimir (Lista *li);
void inserir (Lista **li, int i);
void altera (Lista **li, int i);
int tempo (Lista **li, int t);

int main ()
{   int n, x, i, t = 1;
    char c;
    Lista *li = NULL;

    scanf(" %d", &n);

    for (i = 0; i < n; i++)
    {   scanf(" %c %d", &c, &x);

        if (c == 'R' || c == 'E')
        {   t = tempo(&li, t);

            if (c == 'E')
                altera(&li, x);
                
            if (c == 'R')
                inserir(&li, x);
        } else
            t = x;
    }

    imprimir(li);

    return 0;
}

void imprimir (Lista *li)
{   Lista *aux = li;

    while (aux)
    {   if (aux->tipo == 'R')
            aux->tempo = -1;
        
        printf("%d %d\n", aux->i, aux->tempo);
        aux = aux->prox;
    }
}

void inserir (Lista **li, int i)
{   Lista *novo = malloc(sizeof(Lista)), *aux, *ant;
    novo->tempo = 0;
    novo->i = i;
    novo->tipo = 'R';

    if (*li == NULL)
    {   *li = novo;
        novo->prox = NULL;
    } else if (novo->i < (*li)->i)
    {   novo->prox = *li;
        *li = novo;
    } else
    {   ant = *li;
        aux = (*li)->prox;

        while (aux && aux->i < novo->i)
        {   ant = aux;
            aux = aux->prox;
        }

        if (aux && (aux->i == novo->i))
            aux->tipo = 'R';
        else
        {   ant->prox = novo;
            novo->prox = aux;
        }
    }
}

void altera (Lista **li, int i)
{   Lista *aux = *li;

    while (aux && aux->i != i)
        aux = aux->prox;

    if (aux)
        aux->tipo = 'E';
}

int tempo (Lista **li, int t)
{   Lista *aux = *li;

    while (aux)
    {   if (aux->tipo == 'R')
            aux->tempo += t;

        aux = aux->prox;
    }

    return 1;
}
