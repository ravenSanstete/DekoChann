#include <stdio.h>
#include <iostream>

#include "core.h"
using namespace std;






// implement insertion sort methods
void sort(double* dat, int len, SORT_METHOD mode, double* buf){
  if(buf!=nullptr){
    //first copy the data into the buf
    memcpy(buf, dat, len);
  }


}
