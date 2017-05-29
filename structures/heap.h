// this file implements the max(min)-heap, which based on a dynamic array



enum HEAP_MODE {
  MAX_HEAP=1,
  MIN_HEAP=2
};



typedef struct {
    double* content;
    unsigned int max_size;
    unsigned int occup; //the maximal value of occup should only be (max_size-1)
    enum HEAP_MODE mode; //if type==true, means it is a max-heap
} Heap;




// NOTE: the limit here is not hard, the heap can be dynamically reallocated
// NOTE: the heap is a pointer to some allocated space
// NOTE: it will register the space
void create_heap(Heap* heap, enum HEAP_MODE mode, int limit);


void deconstruct_heap(Heap* heap); //only free the content




int heap_insert(Heap* heap, double data);

void up_float(double* heap_data, int index, enum HEAP_MODE mode);

void build_heap(Heap* heap, enum HEAP_MODE mode, double* data, int size);


void print_heap(Heap* heap);



//
