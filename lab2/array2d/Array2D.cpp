#include "Array2D.h"
#include<iostream>

void PrintTable(int n_rows, int n_columns, int *const *tab);

int **Array2D(int n_rows, int n_columns)
{
    if(n_rows <= 0 || n_columns <= 0)
    {
        return nullptr;
    }
    int ** tab = new int * [n_rows];

    for(int i = 0;i < n_rows;i++)
    {
        tab[i] = new int [n_columns];
    }
    for(int i = 0;i < n_rows;i++)
    {
        for(int j = 0;j < n_columns;j++)
        {
            tab[i][j] = i * n_columns + j + 1;
        }
    }
    return tab;
}

void PrintTable(int n_rows, int n_columns, int *const *tab) {
    for(int i = 0; i < n_rows; i++)
    {
        for(int j = 0;j < n_columns;j++)
        {
            printf("%2d ", tab[i][j]);
        }
        std::cout <<std::endl;
    }
}

void DeleteArray2D(int **array, int n_rows, int n_columns)
{
    for(int i = 0;i < n_rows;i++)
    {
        delete [] array[i];
    }
    delete [] array;
    array = NULL;
}
