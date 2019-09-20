//
//  main.c
//  Matrix_Gauss_method
//
//  Created by Адиль Рашитов on 6/4/18.
//  Copyright © 2018 Адиль Рашитов. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Funtions.h"
int main(int argc, const char * argv[]) {
    
    clock_t t;
    t = clock();
    
    // Memory allocating and initilizing
    double **matrix;
    double *result;
    FILE *fp = fopen("Data", "r");
    if(fp==NULL)
    {
        printf("Null pointer exception at file\n");
        return 1;
    }
    int* size=(int*)malloc(sizeof(int));
    *size = getSize(fp);
    matrix = (double**)malloc(*size*sizeof(double*));
    result = (double*)malloc(*size*sizeof(double));
    for(int i=0;i<*size;i++)
    {
        matrix[i]=(double*)malloc(*size*sizeof(double));
    }
    matrix_initilizing(fp, matrix, result, *size);
   
    // function which performs all calculation
    Calculate_as_Gauss_leave(matrix,result,size);
    
    // Memory clean
    for(int i=0;i<*size;i++)
    {
        free(matrix[i]);
    }
    free(size);
    free(matrix);
    free(result);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("Execution time is: %lf",time_taken);
    return 0;
}
