#ifndef HEAP_SORT_H
#define HEAP_SORT_H
#include <time.h>
#include "filas.h"

void heapify_min(int arr[], int n, int i);

void troca5(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void build_min_heap(int arr[], int n);

void heapify_min(int arr[], int n, int i) {
    int menor = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && arr[esq] < arr[menor]) {
        menor = esq;
    }

    if (dir < n && arr[dir] < arr[menor]) {
        menor = dir;
    }

    if (menor != i) {
        troca5(&arr[i], &arr[menor]);
        heapify_min(arr, n, menor);
    }
}

void heapsort(int arr[], int n) {
    build_min_heap(arr, n);

    for (int i = n - 1; i > 0; i--) {
        troca5(&arr[0], &arr[i]);
        heapify_min(arr, i, 0);
    }
}

double HeapSort(int *arr, int n) {
    clock_t inicio, fim;
    double tempo;

    inicio = clock();

    heapsort(arr, n); 

    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    return tempo;
}

#endif