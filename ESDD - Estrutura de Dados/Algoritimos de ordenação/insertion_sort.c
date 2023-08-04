#include <stdio.h>
#include <time.h>
#define SIZE 100
#define TRUE 1
#define FALSE 0

void insertion_sort(int dataset[]);
void show(int dataset[]);
void random_number(int dataset[]);

int main()
{
    int array[SIZE];
    srand((unsigned)time(NULL));

    // Colocar numeros aleatórios no Array
    random_number(array);
    
    // Ordenar com o método Insertion Sort
    insertion_sort(array);

    // Mostrar o Array
    show(array);

    return 0;
}

void show(int dataset[])
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        printf("Posicao [%d]: %d \n", i + 1, dataset[i]);
    }
}
void random_number(int dataset[])
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        dataset[i] = rand() % 1001;
    }
}
void insertion_sort(int dataset[])
{
    int aux;
    int i, j;

    for (i = 1; i < SIZE; i++)
    {
        aux = dataset[i];

        j = i;
        while (j > 0 && (dataset[j - 1] > aux))
        {

            dataset[j] = dataset[j - 1];

            j--;
        }
        
        dataset[j] = aux;
    }
    
}
