#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "hub.h"






HUB init_hub(int max_size){
  assert(max_size>=0);

  HUB hub;
  hub.objs= NULL;
  hub.deps= NULL;

  hub.capacity=(max_size==0)? MAX_HUB: max_size;

  hub.occup=0;
  return hub;
}


//only return the id content of the signature, which allows the obj manager to work more bravely
int register_obj(HUB* hub, int dim, int* shape){
  if(hub->occup>=hub->capacity){ //which means the hub is already full, please register in some visible future
    return -1; //the user should check it
  }
  hub->occup++;


  struct Node n_node;
  struct Signature sig;


  srand(time(NULL));
  // initialize the signature
  sig.content =  rand();
  sig.dim= dim;
  sig.shape= (int*)(malloc(dim*sizeof(int)));

  //copy the shape into a hub instance
  memcpy(sig.shape, shape, dim*sizeof(int));



  // insert a new node with the newly-created signature into the hub
  n_node.cur = &sig;
  n_node.next = hub->objs;

  hub->objs= &n_node;

  return sig.content;
}




//
