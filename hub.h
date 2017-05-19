/* This maintains a registry hub for different mathematical objects*/
#define MAX_HUB 1024

// this defines the signature of a mathe. obj.
struct Signature {
  int content; // currently only use large random number
  int dim;
  int* shape; // the shape should be deep copied from the source obj
};


struct Node {
  struct Node* next;
  struct Signature* cur;
};


typedef struct {
  struct Node* objs; //a list for tensors that have already been created
  struct Node* deps; //a list that means deprecation
  int capacity;
  unsigned int occup; // the current occupants
} HUB;




//@param max_size: if 0, means use default max size
HUB init_hub(int max_size);


//return a random id to validate the tensor creation
int register_obj(HUB* hub, int dim, int* shape);



//some living analysis may be needed here
