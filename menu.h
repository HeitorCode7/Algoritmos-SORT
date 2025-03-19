#include<stdio.h>
#include <iostream>

using namespace std;

int Menu()
{
    int num;
    printf("###MENU###\n");
    printf("1 - Insertion Sort\n");
    printf("2 - Bubble Sort\n");
    printf("3- Selection Sort\n");
    printf("4- Shell Sort\n");
    printf("5- Merge Sort\n");
    printf("6- Quick Sort, primeiro pivo\n");
    printf("7- Quick Sort, media pivo\n");
    printf("8- Quick Sort, random pivo\n");
    printf("9- Heap Sort\n");
    printf("10- Heap minimo\n");
    printf("11- Heap Extract min\n");
    printf("12 - Heap Incrase Key\n");
    printf("13 - Heap Insert\n");

    printf("\nEscolha uma Opcao: ");
    cin >> num; //lê o número e guarda em num

    return num;
}

int Entrada()
{
    int entrada;
    printf("###ENTRADAS###\n");
    printf("1 - Crescente\n");
    printf("2 - Decrescente\n");
    printf("3 - Random\n");

    cin >> entrada;

    return entrada;
}

int Instancia()
{
    int instancia;
    printf("###INSTANCIAS###\n");
    printf("1 - 10\n");
    printf("2 - 100\n");
    printf("3 - 1000\n");
    printf("4 - 10000\n");
    printf("5 - 100000\n");
    printf("6 - 1000000\n");

    cin >> instancia;

    return instancia;
}
