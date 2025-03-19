#ifndef BUBBLE_H
#define BUBBLE_H
#include <time.h>
#include <iostream>

double BubbleSort(int *elem, int n)
{
    int chave, troca = 1, i, j; 
    clock_t inicio, fim; 
    double tempo = 0.0; 

    
    inicio = clock();

    //Loop para controlar o número de passagens pela lista
    for (j = n - 1; (j >= 1) && (troca == 1); j--)
     {
        troca = 0; // Marca "troca" como 0 para verificar se houve trocas nesta passagem

        //Loop para comparar elementos adjacentes
        for (i = 0; i < j; i++) {
            // Verifica se o elemento atual é maior que o próximo
            if (elem[i] > elem[i + 1]) 
            {
                //Troca os elementos, colocando o maior na posição correta
                chave = elem[i];
                elem[i] = elem[i + 1];
                elem[i + 1] = chave;

                //Marca que houve uma troca nesta passagem
                troca = 1;
            }
        }
    }

    fim = clock();

  
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    return tempo; 
}
#endif