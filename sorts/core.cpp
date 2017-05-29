#include <stdio.h>
#include <iostream>

#include "core.h"
using namespace std;

void insertion_sort(double* dat, int len);
void swap(double* a, double* b);


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
  }
  return;
}

void swap(double* a, double* b){
  double tmp = *a;
  *a = *b;
  *b = tmp;
  return;
}

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
