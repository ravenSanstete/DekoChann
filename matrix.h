/* Define some data structure for matrix*/



typedef struct {
  float* data;
  int sig; // the signature of this MAT
  int* shape; // an array to determine the shape of the tensor
} TENSOR;




//maintain a hub to keep track of the matrix that has been constructed





// The best grammar is
/*
  TENSOR A= | 1 2 3 |
            | 2 3 1 |
            | 1 3 2 |
*/
