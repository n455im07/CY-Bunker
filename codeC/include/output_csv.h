#ifndef OUTPUT_CSV_H
#define OUTPUT_CSV_H

#include "avl.h"

void write_csv(AVL* avl, FILE* file);
void write_csv_minmax(AVL* avl, FILE* file);


#endif // OUTPUT_CSV_H