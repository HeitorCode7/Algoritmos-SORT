#ifndef SELECTION_H
#define SELECTION_H
#include <time.h>
#include <iostream>

double SelectionSort(int *elem, int n) 
{
    int i, j, menor, chave; 
    clock_t inicio, fim; 
    double tempo = 0.0; 

    inicio = clock(); 

    //Percorre o array até o penúltimo elemento
    for (i = 0; i < (n - 1); i++) //até n-1 p garantir q o ultimo elem não seja processado novamente, pois estara ordenado dps da última iteração.
    {
        menor = i; //Assume que o índice atual contém o menor valor

        //Encontra o índice do menor elemento 
        for (j = i + 1; j < n; j++) 
        {
            if (elem[j] < elem[menor]) //Verifica se o elemento atual é menor que o menor conhecido
                menor = j; //Atualiza o índice do menor elemento encontrado
        }

        //Se o índice atual `i` não for o do menor valor, troca os elementos
        if (i != menor) 
        {
            chave = elem[i]; //Salva o valor do elemento atual
            elem[i] = elem[menor]; //Coloca o menor valor na posição `i`
            elem[menor] = chave; //Coloca o valor salvo na posição onde estava o menor
        }
    }

    fim = clock(); 
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    return tempo; 
}
#endif