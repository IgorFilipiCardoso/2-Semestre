#include <stdio.h>

void bubbleEstranho(int size, int turnos);

int main()
{

    int turnos = 1, size = 1;

    while (size != 0 && turnos != 0)
    {
        scanf("%d %d", &size, &turnos);

        bubbleEstranho(size, turnos);
    }

    return 0;
}

void bubbleEstranho(int size, int turnos)
{
    if (!size && !turnos)
    {
        return;
    }

    int trocou = 1;
    int trocas = 0, i = 0, j = 0, k = 0, temp = 0;

    int array[size];

    // Criar uma lista no array;
    for (i = 1; i < size + 1; i++)
    {
        array[i - 1] = i;
    }

    for (i = 0; i < turnos; i++)
    {
        // Pegar quantas trocas é para fazer
        scanf("%d", &trocas);

        j = 0; // Enquando j não chegar a quantidade de trocas fica rodando.

        while (j < trocas && trocou)
        {

            trocou = 0;
            // Se K estivel valendo 0 ele volta para o final do array.
            if (k == 0)
            {
                k = size - 1;
            }

            if (turnos == 1 && trocas == 1)
            {
                temp = array[0];
                array[0] = array[1];
                array[1] = temp;
                j++;
                trocou = 1;
            }
            else if (array[k] > array[k - 1])
            {
                temp = array[k];
                array[k] = array[k - 1];
                array[k - 1] = temp;
                j++;
                trocou = 1;
            }

            k--;
        }
    }

    for (i = 0; i < size; i++)
    {

        if (i == (size - 1))
        {
            printf("%d", array[i]);
        }
        else
        {
            printf("%d ", array[i]);
        }
    }

    printf("\n");
}
