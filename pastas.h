#include <iostream>
#include <direct.h> // biblioteca para _mkdir
using namespace std; 

string pasta(int b) //Tipo string para determinar e retornar o nome da pasta
{
    
    string pasta;
    switch(b) //Se b = 1 retora InsertionSort
    {
        case 1:
        pasta = "InsertionSort";
        break;
        case 2: 
        pasta = "BubbleSort";
        break;
        case 3: 
        pasta = "SelectionSort";
        break;
        case 4: 
        pasta = "ShellSort";
        break;
        case 5: 
        pasta = "MergeSort";
        break;
        case 6:
        pasta = "QuickSort Primerio";
        break;
        case 7: 
        pasta = "QuickSort Media";
        break;
        case 8: 
        pasta = "QuickSort Random";
        break;
        case 9: 
        pasta = "Heap Sort";
        break;
        case 10: 
        pasta = "Heap Minimo";
        break;
        case 11:
        pasta = "Heap Extract Min";
        break;
        case 12:
        pasta = "Incrase Key";
        break;
        case 13:
        pasta = "Heap Insert";
        break;
    }
    return pasta;
}

void CriarPasta(const std::string& caminho) //caminho para a pasta
{
    if (_mkdir(caminho.c_str()) != 0) 
     {
        if (errno != EEXIST)
        {
            std::cerr << "Erro ao criar a pasta: " << caminho << std::endl;
        }
    }
}

void CaminhoPasta(const std::string& nome, int entrada) 
{
    CriarPasta(nome);

    CriarPasta(nome + "/Arquivosdeentrada");
    CriarPasta(nome + "/Arquivosdesaida");
    CriarPasta(nome + "/Arquivosdetempo");

    if (entrada == 1) 
    {
        CriarPasta(nome + "/Arquivosdeentrada/crescente");
        CriarPasta(nome + "/Arquivosdesaida/crescente");
        CriarPasta(nome + "/Arquivosdetempo/crescente");
    } else if (entrada == 2) 
    {
        CriarPasta(nome + "/Arquivosdeentrada/decrescente");
        CriarPasta(nome + "/Arquivosdesaida/decrescente");
        CriarPasta(nome + "/Arquivosdetempo/decrescente");
    } else if (entrada == 3) 
    {
        CriarPasta(nome + "/Arquivosdeentrada/random");
        CriarPasta(nome + "/Arquivosdesaida/random");
        CriarPasta(nome + "/Arquivosdetempo/random");
    }
}

