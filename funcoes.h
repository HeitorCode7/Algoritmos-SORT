#ifndef FUNCAO_H
#define FUNCAO_H
#include<stdio.h>


int ConverteTamanho(int n) 
{
    switch(n)
    {
        case 1:
        n = 10;
        break;

        case 2:
        n = 100;
        break;

        case 3:
        n = 1000;
        break;

        case 4:
        n = 10000;
        break;

        case 5:
        n = 100000;
        break;

        case 6:
        n = 1000000;
        break;
    }

return n;
}
#endif













