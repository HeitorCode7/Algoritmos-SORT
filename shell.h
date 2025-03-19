#ifndef SHELL_H
#define SHELL_H
#include <time.h>
#include <iostream>
//versão otmizada do insertion. 

double ShellSort(int *lista, int n) 
{
    int i, j, valor, h = 1;
    clock_t inicio, fim;
    double tempo = 0.0; 

    inicio = clock();

while(h < n) //distancia
{
    h = 3*h + 1;  //h == distancia, ordena o vetor comparando valores distantes
}
//Começa o processo de ordenação, reduzindo h gradativamente. Equanto h > 0(até 1)
while (h > 0)
{
    //Itera sobre o array começando do índice h até o final
    for(i = h; i < n; i++) 
    {
        valor = lista[i];  //Armazena o valor atual
        j = i;  //Inicializa j como o índice atual i

        //Realiza a ordenação por inserção com o intervalo h
        while (j > h - 1 && valor <= lista[j - h]) 
        {
            lista[j] = lista[j - h];  //Move o elemento lista[j - h] para a posição j
            j = j - h;  //Atualiza j para o índice anterior com intervalo h
        }

        lista[j] = valor;  //Coloca valor na posição correta dentro do intervalo h
    }

    h = h / 3;  //Reduz o intervalo h para a próxima iteração.
}

    fim = clock();

    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    return tempo;
}
#endif