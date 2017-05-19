/* Define some data structure for matrix*/





typedef struct {
  float* data;
  int signature; // the signature of this mathe. obj
  int* shape; // an array to determine the shape of the tensor
  int dim; //which indicates the length of the shape
} TENSOR;

//maintain a hub to keep track of the matrix that has been constructed






// some private c-routine for initializing the tensor
// init the environment, which also init the hub
void init_env(int max_size);



TENSOR _init_zero_tensor(int* shape, int dim);
TENSOR _init_tensor(int* shape, int dim, float* init_data);



// The best grammar is
/*
  This should be implemented with an external intepreter

         A= | 1 2 3 |
            | 2 3 1 |
            | 1 3 2 |
*/
