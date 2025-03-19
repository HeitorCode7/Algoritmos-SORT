#ifndef INSERTION_H
#define INSERTION_H
#include <time.h>
#include <iostream>

double InsertionSort(int *elem, int n)
{
    int chave, i, j;
    clock_t inicio, fim;
    double tempo = 0.0;

    inicio = clock();

    for (i = 1; i < n; i++)
    {
        chave = elem[i];
        j = i - 1;
        while (j >= 0 && elem[j] > chave)
        {
            elem[j + 1] = elem[j];
            j = j - 1;
        }
        elem[j + 1] = chave;
    }

    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    return tempo;
}
#endif