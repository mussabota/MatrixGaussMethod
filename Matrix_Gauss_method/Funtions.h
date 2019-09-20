//
//  Funtions.h
//  Matrix_Gauss_method
//
//  Created by Адиль Рашитов on 6/4/18.
//  Copyright © 2018 Адиль Рашитов. All rights reserved.
//

#ifndef Funtions_h
#define Funtions_h

#include <stdio.h>
int getSize(FILE *fp);
void matrix_initilizing(FILE *fp, double** matrix,double* result,int size);
void Calculate_as_Gauss_leave(double** matrix, double* result, int* size);
void become_current_column_to_one(double** matrix, double* result, int pozition, int stop, int size);
void withdrow_current_from_below(double** matrix, double* result, int pozition, int stop, int size);
void print_matrix(double** matrix, int* size);
void print_matrix_result(double** matrix, double* result, int* size);
void print_result(double* results, int size);
#endif /* Funtions_h */
