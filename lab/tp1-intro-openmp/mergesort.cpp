#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <chrono>
#include "omp.h"

void assertExo(const std::vector<int> & A) {
  bool flag = true;
  for (int i = 1; i < A.size(); i++) {
    auto diff = A[i] - A[i-1];
    if ((diff)/std::abs(diff) < 0) {
      flag = false;
      break;      
    }
  }
  if(flag) {
    std::cout << "It works ! " << std::endl;
  } else {
    std::cout << "It does not work ! :(" << std::endl;
  }  
}

void merge(int * res, 
           const int * tabA,
           const int sizeA,
           const int * tabB,
           const int sizeB)
{
  int i = 0, j = 0;
  while(i != sizeA && j != sizeB ) {
    if (tabA[i] < tabB[j]) {
      res[i+j] = tabA[i];
      i++;
    } else {
      res[i+j] = tabB[j];
      j++;
    }
  }
  if (i == sizeA) {
    for(; j < sizeB; j++) {
      res[i+j] = tabB[j];
    }
  } else {
    for(; i < sizeA; i++) {
      res[i+j] = tabA[i];
    }
  }
}

int main() 
{
  std::srand(123);
  int N = 10000000;
  std::vector<int> A(N);
  std::vector<int> temp(N);

  for (int i = 0; i < N; i++) {
      A[i] = std::rand();
  }

  auto start = std::chrono::high_resolution_clock::now();
  //TODO:
  
  std::chrono::duration<double> time = std::chrono::high_resolution_clock::now() - start;
  std::cout << "Time: " << time.count() << "s\n";

  assertExo(A);
  return 0;

}
