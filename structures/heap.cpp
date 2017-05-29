

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include "heap.h"

using namespace std;

#define MORINO
void _build_heap(double* heap_data, enum HEAP_MODE mode, int size);
void _heap_sort(double* heap_data, enum HEAP_MODE mode, int occup, double* store);
void _print_heap(double* heap_data, int occup);
void _max_heapify(double* heap_data, int ind, int occup);
void _min_heapify(double* heap_data, int ind, int occup);
int _parent(int i);
int _l_child(int i);
int _r_child(int i);
void _swap(double* a, double* b);



//NOTE: this will build out a heap according to the array given
//NOTE: which is used for search problem
//NOTE: the effect on the pointer's data is destructive
void build_heap(Heap* heap, enum HEAP_MODE mode, double* data, int size){
    heap->mode = mode;
    heap->max_size= size;
    heap->occup = size-1;
    heap->content = data;

    _build_heap(heap->content, heap->mode, heap->occup);
}

//occup, the last occupied position
void _build_heap(double* heap_data, enum HEAP_MODE mode, int occup){
  int i = _parent(occup); // iterate from the last node who has a child
  //do the heapify from the bottom to up
  while(i>=0){
    if(mode==MAX_HEAP)
      _max_heapify(heap_data, i, occup);
    else
      _min_heapify(heap_data, i, occup);

    #ifndef MORINO
    cout<<i<<endl;
    _print_heap(heap_data, occup);
    #endif


    i--;
  }
}

void _max_heapify(double* heap_data, int ind, int occup){
    int largest = ind;
    int l_child = _l_child(ind);
    int r_child = _r_child(ind);


    //if left children larger then the occup, no need to recursively process
    if(l_child >= occup){
      return;
    }

    //if left child larger than the current value
    if(heap_data[l_child] > heap_data[ind]){
      largest = l_child;
    }
    //if right child larger the the current largest
    if((r_child < occup) && (heap_data[r_child] > heap_data[largest])){
      largest = r_child;
    }

    if(ind != largest){
      //swap
      _swap(&(heap_data[largest]), &(heap_data[ind]));
      //recursively invoke the subroutine
      _max_heapify(heap_data, largest, occup);
    }

    return;
}


void heap_sort(Heap* heap, double* store){
    _heap_sort(heap->content, heap->mode, heap->occup, store);
}


void _heap_sort(double* heap_data, enum HEAP_MODE mode, int occup, double* store){
  int i=occup;
  while(i>=0){
    _swap(&(heap_data[i]), &(heap_data[0]));
    //put the data in the store
    store[occup-i] = heap_data[i];
    i--;
    //reformulate the heap
    if(mode==MAX_HEAP)
      _max_heapify(heap_data, 0, i);
    else
      _min_heapify(heap_data, 0, i);
  }
}




//NOTE: this always constructs an empty heap and then for the user to dynamically insert entry into it
//NOTE: used basically for priority queue or something like that
void create_heap(Heap* heap, enum HEAP_MODE mode, int limit){
  heap->mode = mode;
  heap->max_size = limit;
  heap->occup = 0;

  heap->content = (double*)malloc(limit*sizeof(double));
}




int heap_insert(Heap* heap, double data){
  //if it overflows the allocated space, you should just reallocate a 2-size large space
  if((heap->occup+1)>=heap->max_size){
      unsigned enlarged_size = 2*(heap->max_size);
      double* new_space = (double*)malloc(enlarged_size*sizeof(double));
      memcpy(new_space, heap->content, heap->occup);
      free(heap->content);
      heap->content = new_space;
  }

  //then do the insertion again, first
  heap->occup+=1;
  assert(heap->occup<heap->max_size); // this should be asserted
  //Then we should insert the data to the pos "heap->occup"
  (heap->content)[heap->occup] = data;

   up_float(heap->content, heap->occup, heap->mode);


   return -1; //not implemented
}



//the newly inserted data should float to a proper position on the heap
void up_float(double* heap_data, int index, enum HEAP_MODE mode){

}



void deconstruct_heap(Heap* heap){
  free(heap->content);
}


//for user's inspection
void print_heap(Heap* heap){
  _print_heap(heap->content, heap->occup);
}



void _print_heap(double* heap_data, int occup){
  int i=0;
  int split=2;
  while(i<=occup){
      cout<<heap_data[i]<<"\t";
      if(i==split-2){
          cout<<"\n";
          split=split<<1;
      }
      i++;
  }

  cout<<"\n";
}


void _swap(double* a, double* b){
  double tmp = *a;
  *a = *b;
  *b = tmp;
}


int _parent(int i){
  if(i==0){
    return -1; //the parent of the root should be minus to indicate the finish of the recurrence
  }

  return (i-1)/2;
}

int _l_child(int i){
  return 2*i+1;
}

int _r_child(int i){
  return 2*(i+1);
}





// the min-heap counterpart
void _min_heapify(double* heap_data, int ind, int occup){
    int smallest = ind;
    int l_child = _l_child(ind);
    int r_child = _r_child(ind);

    //if left children larger then the occup, no need to recursively process
    if(l_child > occup){
      return;
    }





    //if left child smaller than the current value
    if(heap_data[l_child] < heap_data[ind]){
      smallest = l_child;
    }
    //if right child larger the the current largest
    if((r_child < occup) && (heap_data[r_child] < heap_data[smallest])){
      smallest = r_child;
    }

    if(ind != smallest){
      //swap
      _swap(&(heap_data[smallest]), &(heap_data[ind]));
      //recursively invoke the subroutine
      _min_heapify(heap_data, smallest, occup);
    }

    return;
}
