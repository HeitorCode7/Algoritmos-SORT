#include <stdio.h>
#include <iostream>
#include "menu.h"
#include "funcoes.h"
#include "pastas.h"
#include "entradas.h"
#include "filas.h"
#include <cstdio>
#include <cstdlib>  // Para rand()

 
using namespace std;

int main() 
{
    srand(static_cast<unsigned int>(time(nullptr))); // Inicializa o gerador de números aleatórios

    int algoritmo, tipoentrada, tam;
    algoritmo = Menu(); //Algoritmo, InsertionSort
    tipoentrada = Entrada();    //Tipo = crescente, decrescente ou random. 
    tam = Instancia();        //Instancia 
    tam = ConverteTamanho(tam); 

   
    CaminhoPasta(pasta(algoritmo), tipoentrada); //Cria as pastas
    GeraEntrada(algoritmo, tipoentrada, tam); //Gera os arquivos de entrada, saída e tempo

    return 0;
}
