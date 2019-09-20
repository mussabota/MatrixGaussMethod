//
//  Funtions.c
//  Matrix_Gauss_method
//
//  Created by Адиль Рашитов on 6/4/18.
//  Copyright © 2018 Адиль Рашитов. All rights reserved.
//

#include "Funtions.h"
#include <stdlib.h>
#include <stdio.h>

int getSize(FILE *fp)
{
    if (fp == NULL){
        printf("Could not open file.\n");
    }else
    {
        char str[10];
        return atoi(fgets(str, 10, fp));
    }
    return 0;
}

void print_matrix(double** matrix, int* size)
{
    FILE *fp = fopen("Matrix", "wr");
    
    for(int i=0;i<*size;i++)
    {
        for(int j=0;j<*size;j++)
        {
            fprintf(fp, "%lf  ",matrix[i][j]);
        }
        fprintf(fp,"\n");
    }
}

void print_matrix_result(double** matrix, double* result, int* size)
{
    FILE *fp = fopen("Matrix_result", "wr");
    
    for(int i=0;i<*size;i++)
    {
        for(int j=0;j<*size;j++)
        {
            fprintf(fp, "%lf  ",matrix[i][j]);
        }
        fprintf(fp," | %lf\n",result[i]);
    }
}

void print_result(double* results, int size)
{
    FILE *fp = fopen("Output", "wr");
    fprintf(fp,"Totla result is: \n");
    for(int i=0;i<size;i++)
    {
        fprintf(fp,"%lf\n",results[i]);
    }
}

void Calculate_as_Gauss_leave(double** matrix, double* result, int* size)
{
    
    // Here we set 0 to all elements under diagonal
    for(int i=0;i<*size;i++)// Iteration through diagonal
    {
        become_current_column_to_one(matrix, result, i, *size, *size);
        withdrow_current_from_below(matrix, result, i, *size, *size);
    }
    
//    print_matrix_result(matrix,result, size);
  
    double output[*size]; // Array which shows total result
    for(int i=0;i<*size;i++)
    {
        output[i]=result[i];
    }
    
    // Calculation results
    for(int i = *size-2;i>=0;i--)// From down to up
    {
        if(matrix[i][i]==0.00000000)
        {
            output[i]=0;
        }
        else
        {
            for(int j=*size-1;j>i;j--)
            {
                if(matrix[i][j]==0.0000000)
                    continue;
                output[i]-=matrix[i][j]*output[j];
            }
            output[i]/=matrix[i][i];
        }
    }
    print_result(output, *size);
   
}

void become_current_column_to_one(double** matrix, double* result, int pozition,int stop, int size)
{
    for(int i=pozition;i<stop;i++)
    {
        if(matrix[i][pozition]==0.00000000)
            continue;
        else
        {
            result[i]=result[i]/matrix[i][pozition];
            
            for(int j=pozition+1;j<size;j++)
            {
                matrix[i][j] = matrix[i][j]/matrix[i][pozition];
            }
            matrix[i][pozition]=1;
        }
    }
}

void withdrow_current_from_below(double** matrix, double* result, int pozition,int stop, int size)
{
    for(int i=pozition+1;i<stop;i++)
    {
        if(matrix[i][pozition]==0.00000000)
            continue;
        for(int j=pozition;j<size;j++)
        {
            matrix[i][j]=matrix[i][j]-matrix[pozition][j];
        }
        result[i]-=result[pozition];
    }
}

void matrix_initilizing(FILE *fp, double** matrix,double* result,int size)
{
    if (fp == NULL){
        printf("Could not open file.\n");
    }
    else {
        char str[255];
        int line=0;
        int column=0;
        // reading file
        for (int i=0;i<size*size;i++)
        {
            fgets(str, 255, fp);
            matrix[line][column] = atof(str);
            column++;
            if(column==20)
            {
                line++;
                column=0;
            }
        }
        for(int i=0;i<size;i++)
        {
            fgets(str, 255, fp);
            result[i]=atof(str);
        }
        
    }
}
