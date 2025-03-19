
#ifndef FILAS_H
#define FILAS_H
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void swapt(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(int arr[], int n, int i) {
    int menor = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && arr[esq] < arr[menor])
        menor = esq;

    if (dir < n && arr[dir] < arr[menor])
        menor = dir;

    if (menor != i) {
        swapt(&arr[i], &arr[menor]);
        min_heapify(arr, n, menor);
    }
}

void build_min_heap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        min_heapify(arr, n, i);
}

int heap_minimum(int arr[]) {
    return arr[0];
}

int heap_extract_min(int arr[], int *n) {
    if (*n < 1) {
        printf("Heap vazio\n");
        return -1;
    }

    int mini = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    min_heapify(arr, *n, 0);
    return mini;
}

void heap_increase_key(int arr[], int i, int key) {
    if (key < arr[i]) {
        printf("Nova chave é menor que a chave atual\n");
        return;
    }

    arr[i] = key;
    while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
        swapt(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void max_heap_insert(int **arr, int *n, int key) {
    (*n)++;


    *arr = (int*) realloc(*arr, (*n) * sizeof(int));

    
    (*arr)[*n - 1] = INT_MIN;

   
    heap_increase_key(*arr, *n - 1, key);
}

#endif