
#include <iostream>
#include <fstream>
#include <assert.h>

#include "./core.h"


#define PATH "/Users/morino/Desktop/DekoChann/sorts/test_data.dat"


using namespace std;


//which uses assertion to check the partial order relation
void assert_incr_order(double* candy, int len);

int main(){
  ifstream test_data;
  test_data.open(PATH, ios::in);
  int test_num,i=0;
  test_data >> test_num;


  cout<<test_num<<endl;
  double* dat = new double[test_num];
  char comma;
  while(i<test_num){
    test_data >> dat[i];
    test_data >> comma;
    i++;
  }


  double* buf= nullptr;


  sort(dat, test_num, INSERTION, buf);

  if(buf==nullptr){
      assert_incr_order(dat, test_num);
  }else{
      assert_incr_order(buf, test_num);
  }


  //then we going to test the outcome of the sorting
  cout<<"Test Passed"<<endl;



  delete [] dat;

  return 1;


}




void assert_incr_order(double* candy, int len){
  int i=0;
  while(i<len-1){
    if(candy[i]>candy[i+1]){
      cerr<<"Item "<<i<<":"<<candy[i]<<">"<<"Item "<<(i+1)<<":"<<candy[i+1]<<endl;
    }

    assert(candy[i]<=candy[i+1]);
    i++;
  }
  cout<<"In Order."<<endl;

}

//
