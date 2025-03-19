#include <iostream>
#include <time.h>
#include <fstream> //manipulação de arquivos
#include "funcoes.h"
#include "insertion.h"
#include "bubble.h"
#include "selection.h"
#include "shell.h"
#include "merge.h"
#include "quicksort_versao1.h"
#include "quicksort_versao2.h"
#include "quicksort_versao3.h"
#include "heap_sort.h"
#include "filas.h"

double Executa(int algoritmo, int *lista, int n) // retorna o tempo de execucao
{
    double tempo = 0.0; // Inicializar `tempo`
    int *original_arr = (int *)malloc(n * sizeof(int));
    if (!original_arr) {
        printf("Erro ao alocar memoria.\n");
        return -1;
    }

    switch (algoritmo)
    {
    case 1:
        tempo = InsertionSort(lista, n);
        break;
    case 2:
        tempo = BubbleSort(lista, n);
        break;
    case 3:
        tempo = SelectionSort(lista, n);
        break;
    case 4:
        tempo = ShellSort(lista, n);
        break;
    case 5:
        tempo = MergeSort(lista, n);
        break;
    case 6:
        tempo = Quick1(lista, n);
        break;
    case 7:
        tempo = QuickM(lista, n);
        break;
    case 8:
        tempo = QuickSort3(lista, n);
        break;
    case 9:
        tempo = HeapSort(lista, n);
        break;
    case 10: {
        printf("Heap Minimo\n\n");
        printf("Vetor Original: ");
        for (int i = 0; i < n; i++) {
            original_arr[i] = rand() % 100;
            printf("%d ", original_arr[i]);
        }
        printf("\n");

        build_min_heap(original_arr, n);
        printf("Apos a build: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", original_arr[i]);
        }
        printf("\n");

        printf("Elemento Minimo: %d\n", heap_minimum(original_arr));
        break;
    }
    case 11: {
        printf("Heap Extract Min\n\n");
        printf("Vetor Original: ");
        for (int i = 0; i < n; i++) {
            original_arr[i] = rand() % 100;
            printf("%d ", original_arr[i]);
        }
        printf("\n");

        build_min_heap(original_arr, n);
        printf("Heap apos build_min_heap: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", original_arr[i]);
        }
        printf("\n");

        int extracted_min = heap_extract_min(original_arr, &n);
        printf("Elemento Minimo: %d\n", extracted_min);

        printf("Heap apos heap_extract_min: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", original_arr[i]);
        }
        printf("\n");
        break;
    }
    case 12:{
        printf("Heap Increase Key\n\n");
            printf("Vetor Original: ");
            for (int i = 0; i < 10; i++) {
                original_arr[i] = rand() % 100;
                printf("%d ", original_arr[i]);
            }
            printf("\n");

            build_min_heap(original_arr, 10);
            printf("Vetor Chamando Build: ");
            for (int i = 0; i < 10; i++){
                printf("%d ", original_arr[i]);
            }
            printf("\n");

            int posicao;
            printf("Determine a posicao para inserir o valor 1000: ");
            scanf("%d", &posicao);

            heap_increase_key(original_arr, posicao, 1000);

            printf("Vetor apos a Insercao: ");
            for (int i = 0; i < 10; i++){
                printf("%d ", original_arr[i]);
            }

        break;
    }
    case 13:{
           printf("Heap Insert\n\n");
            printf("Vetor Original: ");
            for (int i = 0; i < 10; i++) {
                original_arr[i] = rand() % 100;
                printf("%d ", original_arr[i]);
            }
            printf("\n");
            max_heap_insert(&original_arr, &n, 1000);
            printf("Vetor apos a Insercao: ");
            for (int i = 0; i < 11; i++){
                printf("%d ", original_arr[i]);
            }
        break;
    }
    default:
        break;
    }

    free(original_arr); // Liberar memoria alocada
    return tempo;
}


void GeraEntrada (int algoritmo, int entrada, int n)  //Indica o algoritmo escolhido, o tipo e tamanho.
{
    FILE *arq;  
    double tempo;

    if (entrada == 1)
     {
        string nome_arquivo = pasta(algoritmo) + "/Arquivosdeentrada/crescente/crescente" + to_string(n) + ".txt";

        arq = fopen(nome_arquivo.c_str(), "w");
        fprintf (arq, "%d\n", n); //mostra a instancia na 1 linha


        int *array = new int[n]; 

        for (int i = 0; i<n;i++) //preenche o vetor de 0 até n - 1
        {
                array[i] = i; //Cria um array de n posicoes 
                fprintf(arq, "%d\n", array[i]); 
        }
        fclose(arq);

        //Gera saida

        tempo = Executa(algoritmo, array, n);
        nome_arquivo = pasta(algoritmo) + "/Arquivosdesaida/crescente/crescente" + to_string(n) + ".txt";
        arq = fopen(nome_arquivo.c_str(), "w");
        fprintf(arq, "%d\n", n); //printa instancia
        for (int i = 0; i<n; i++)
        { //salva o vetor dentro do arquivo de forma ordenada
            fprintf (arq, "%d\n", array[i]);
        }
        fclose(arq);

        //Gera tempo


        nome_arquivo = pasta(algoritmo) + "/Arquivosdetempo/crescente/crescente" + to_string(n) + ".txt";
        arq = fopen(nome_arquivo.c_str(), "w");
        fprintf(arq, "%f\n", tempo); //printa tempo
        fclose(arq);
        delete[] array;

    }
    else if (entrada == 2) 
    {

        string nome_arquivo = pasta(algoritmo) + "/Arquivosdeentrada/decrescente/decrescente" + to_string(n) + ".txt";

        arq = fopen(nome_arquivo.c_str(), "w");
        fprintf (arq, "%d\n", n);


        int *array = new int[n];
        int j = 0;

        for (int i = n; i > 0;i--) //Preenche o vetor com valores de n ate 1 
        {
                array[j] = i; //n posicoes 
                fprintf(arq, "%d\n", array[j]);
                j++; //-> posicao do array
        }
        fclose(arq);



        tempo = Executa(algoritmo, array, n);
        nome_arquivo = pasta(algoritmo) + "/Arquivosdesaida/decrescente/decrescente" + to_string(n) + ".txt";
        arq = fopen(nome_arquivo.c_str(), "w");
        fprintf(arq, "%d\n", n);
        for (int i = 0; i<n; i++) 
        {
            fprintf (arq, "%d\n", array[i]);
        }
        fclose(arq);

        nome_arquivo = pasta(algoritmo) + "/Arquivosdetempo/decrescente/decrescente" + to_string(n) + ".txt";
        arq = fopen(nome_arquivo.c_str(), "w");
        fprintf(arq, "%f\n", tempo);
        fclose(arq);
        delete[] array;

    }
    else if (entrada == 3) 
    {

        string nome_arquivo = pasta(algoritmo) + "/Arquivosdeentrada/random/random" + to_string(n) + ".txt";

        arq = fopen(nome_arquivo.c_str(), "w");
        fprintf (arq, "%d\n", n);
        int random;


        int *array = new int[n];

        for (int i = 0; i<n;i++) // Preenche o vetor com o intervalo de numeros gerados pela funcao rand
        {                       //Cada numero e atribuido a um indice 
                random = rand() % 1000000;
                array[i] = random;
                fprintf(arq, "%d\n", array[i]);
        }
        fclose(arq);

        tempo = Executa(algoritmo, array, n);
        nome_arquivo = pasta(algoritmo) + "/Arquivosdesaida/random/random" + to_string(n) + ".txt";
        arq = fopen(nome_arquivo.c_str(), "w");
        fprintf(arq, "%d\n", n);
        for (int i = 0; i<n; i++) 
        {
            fprintf (arq, "%d\n", array[i]);
        }
        fclose(arq);

        nome_arquivo = pasta(algoritmo) + "/Arquivosdetempo/random/random" + to_string(n) + ".txt";
        arq = fopen(nome_arquivo.c_str(), "w");
        fprintf(arq, "%f\n", tempo);
        fclose(arq);
        delete[] array;

    }


    printf ("%f", tempo);

}
