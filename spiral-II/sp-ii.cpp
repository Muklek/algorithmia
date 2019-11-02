#include<iostream>
#include<vector>

// Needs fix. Reserve not working.

class SpiralBuilder{
   public:
      SpiralBuilder(int length)
      :length{length}{}
      void generateMatrix();
      void printMatrix();
   private:
      std::vector<std::vector<int>> matrix;
      int length;
};


void SpiralBuilder::generateMatrix(){
   size_t c1{0}, c2{length-1};
   size_t r1{0}, r2{length-1};
   int value{0};

   for(size_t i{0}; i<length; i++) matrix.push_back(std::vector<int>{});
   for(size_t i{0}; i<length; i++) matrix[i].resize(length);

   while(c1 <= c2 && r1<=r2){
      for(size_t c{c1}; c<=c2; c++) matrix[r1][c] = ++value;
      for(size_t r{r1}; r<=r2; r++) matrix[r][c2] = ++value;
      if(c1 < c2 && r1 < r2){
         for(size_t c{c2-1}; c > c1; c--) matrix[r2][c] = ++value;
         for(size_t r{r2}; r > r1; r--) matrix[r][c1] = ++value;
      }
      c1++;r1++;
      c2--;r2--;
   }
}

void SpiralBuilder::printMatrix(){
   std::cout<<matrix.size()<<std::endl;
   std::cout<<matrix[0].size()<<std::endl;
   for(auto y : matrix){
      for(auto x : y){
         std::cout<<x;
         std::cout<<" ";
      }
      std::cout<<std::endl;
   }
}

int main(){
   SpiralBuilder sp{4};
   sp.generateMatrix();
   sp.printMatrix();
}
