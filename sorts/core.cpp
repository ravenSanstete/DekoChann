#include <stdio.h>
#include <iostream>

#include "core.h"

#ifndef HEAP_H
#define HEAP_H
#include "../structures/heap.h"
#endif


using namespace std;




void insertion_sort(double* dat, int len);
void swap(double* a, double* b);
void h_sort(double* dat, int len);


// implement insertion sort methods
void sort(double* dat, int len, SORT_METHOD mode, double* buf){
  if(buf!=nullptr){
    //first copy the data into the buf
    memcpy(buf, dat, len);
  }

  if(mode==INSERTION){
     if(buf==nullptr)
        insertion_sort(dat, len);
      else
        insertion_sort(buf, len);
  }else if(mode==HEAP){
    if(buf==nullptr)
        h_sort(dat, len);
     else
        h_sort(buf, len);
  }
  return;
}

void swap(double* a, double* b){
  double tmp = *a;
  *a = *b;
  *b = tmp;
  return;
}


//NOTE: INCR
void insertion_sort(double* dat, int len){
  int i,j;
  for(i=1; i<len; i++){
    j=i-1;

    while(j>=0 && dat[j]>=dat[j+1]){
      swap(dat+j, dat+(j+1));
      j--;
    }
  }
  return;
}


//use the heap structure to do the sort
void h_sort(double* dat, int len){
  Heap* heap = (Heap*)malloc(sizeof(Heap));
  //then allocate a buffer to store the data
  double* buf = (double*)malloc(len*sizeof(double));

  build_heap(heap, MIN_HEAP, dat, len);

  heap_sort(heap, buf);

  memcpy(dat, buf, len*sizeof(double));

  free(buf);
  free(heap);
}
