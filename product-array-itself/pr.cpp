#include<iostream>
#include<array>

template<int size>
std::array<int, size> getProductItself(const std::array<int, size>& arr){
  int product{1};
  for(const int& number : arr) product *= number;

  std::array<int, size> solution;

  for(int i{0}; i< size; i++) solution[i] = product / arr[i];

  return solution;
}



int main(){
  constexpr std::array<int, 4> numbers{1,2,3,4};

  auto const solution{getProductItself<numbers.size()>(numbers)};

  for(auto const number : solution) std::cout<<number<<'\n';
}

