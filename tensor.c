#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


#include "hub.h"
#include "tensor.h"


static HUB* default_hub;


void init_env(int max_size){
  HUB a = init_hub(max_size);
  default_hub = &a;
  return;
}

//please return a struct rather than the
TENSOR  _init_zero_tensor(int* shape, int dim){
  int sig= register_obj(default_hub, dim, shape);

}


TENSOR _init_tensor(int* shape, int dim, float* init_data){

}











// morino
