#include <iostream>
#include "heap.h"



using namespace std;

#define SIZE 10



int main(){
  double test_data[SIZE]={0.88932536,  0.57389895,  0.91596383,  0.13723108,  0.31260902,
        0.33786487,  0.15253643,  0.74920588,  0.15696222,  0.29805741};

 Heap* heap = (Heap*)malloc(sizeof(Heap));

 build_heap(heap, MAX_HEAP, test_data, SIZE);

 print_heap(heap);

  return 0;
}


//
