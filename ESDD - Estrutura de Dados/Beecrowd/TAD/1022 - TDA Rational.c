#include <stdio.h>
#include <stdlib.h>

typedef struct number {
    int numerador;
    int denominador;
}*Racional;

typedef struct data {
    Racional numeros[2];
    char operation;
}*Operacao;

Operacao initialize();
Racional criarRacional(int numerador, int denominador);
void defineOperation(Operacao data, char operation);
void destruirRacional(Racional numero);

void define(Operacao data);

void sum(Operacao data);
void subtract(Operacao data);
void divide(Operacao data);
void multiply(Operacao data);

void getResult(Operacao data);
void simplify(Operacao data);

int main()
{
    int rpt;
    Operacao data;

    int numerador, denominador;
    char operation, bar;

    scanf("%d", &rpt);

    data = initialize();

    do {
        scanf("%d", &numerador);
        scanf(" %c", &bar);
        scanf("%d", &denominador);

        data->numeros[0] = criarRacional(numerador, denominador);

        scanf(" %c", &operation);

        defineOperation(data, operation);

        scanf("%d", &numerador);
        scanf(" %c", &bar);
        scanf("%d", &denominador);

        data->numeros[1] = criarRacional(numerador, denominador);

        define(data);

        destruirRacional(data->numeros[0]);
        destruirRacional(data->numeros[1]);

    } while (--rpt != 0);

    return 0;
}

Operacao initialize()
{
    Operacao data;
    data = malloc(sizeof(struct data));
    return data;
}

Racional criarRacional(int numerador, int denominador)
{
    Racional numeroRacional;

    numeroRacional = malloc(sizeof(struct number));

    if (numeroRacional != NULL) {
        numeroRacional->numerador = numerador;
        numeroRacional->denominador = denominador;
    }

    return numeroRacional;
}

void defineOperation(Operacao data, char operation)
{
    data->operation = operation;
}

void destruirRacional(Racional numero)
{
    free(numero);
    numero = NULL;
}

void define(Operacao data)
{

    switch (data->operation) {
        case '+':

            sum(data);

            break;

        case '-':

            subtract(data);

            break;

        case '*':

            multiply(data);

            break;

        case '/':

            divide(data);

            break;
    }

    getResult(data);

    simplify(data);
}

void sum(Operacao data)
{

    data->numeros[0]->numerador = (data->numeros[0]->numerador * data->numeros[1]->denominador) + (data->numeros[0]->denominador * data->numeros[1]->numerador);

    data->numeros[0]->denominador = data->numeros[0]->denominador * data->numeros[1]->denominador;
}

void subtract(Operacao data)
{

    data->numeros[0]->numerador = (data->numeros[0]->numerador * data->numeros[1]->denominador) - (data->numeros[0]->denominador * data->numeros[1]->numerador);

    data->numeros[0]->denominador = data->numeros[0]->denominador * data->numeros[1]->denominador;
}

void divide(Operacao data)
{

    data->numeros[0]->numerador = data->numeros[0]->numerador * data->numeros[1]->denominador;

    data->numeros[0]->denominador = data->numeros[1]->numerador * data->numeros[0]->denominador;
}

void multiply(Operacao data)
{

    data->numeros[0]->numerador = data->numeros[0]->numerador * data->numeros[1]->numerador;

    data->numeros[0]->denominador = data->numeros[0]->denominador * data->numeros[1]->denominador;
}

void getResult(Operacao data)
{
    printf("%d/%d =", data->numeros[0]->numerador, data->numeros[0]->denominador);
}

void simplify(Operacao data)
{
    int bigger, minor, change, divisor = 0;

    bigger = data->numeros[0]->numerador;
    minor = data->numeros[0]->denominador;

    change = minor;

    if (minor > bigger) {
        minor = bigger;
        bigger = change;
    }

    if (minor != 1)
        while (change != 1 && divisor == 0) {
            if (minor % change == 0) {
                if (bigger % change == 0) {
                    data->numeros[0]->numerador = data->numeros[0]->numerador / change;
                    data->numeros[0]->denominador = data->numeros[0]->denominador / change;

                    divisor++;
                }
            }

            change--;
        }

    printf(" %d/%d\n", data->numeros[0]->numerador, data->numeros[0]->denominador);
}