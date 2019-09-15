#include<iostream>
#include<vector>

typedef int i;
typedef size_t st;
typedef std::vector<i> vi;
typedef std::vector<vi> vvi;

vi spiral(vvi& matrix){
   st r1{0},r2{matrix.size()-1};
   st c1{0},c2{matrix[0].size()-1};
   vi result;

   while(r1<=r2 && c1<=c2){
      for(st c=c1; c<=c2; c++) result.push_back(matrix[r1][c]);
      for(st r=r1+1; r<=r2; r++) result.push_back(matrix[r][c2]);
      if(r1 < r2 && c1 < c2){
         for(st c=c2-1; c>c1; c--) result.push_back(matrix[r2][c]);
         for(st r=r2; r>r1; r--) result.push_back(matrix[r][c1]);
      }
      r1++;r2--;
      c1++;c2--;
   }
   return result;
}


int main(){
   vvi matrix{{1,2,3,4},
              {6,7,8,9},
              {11,12,13,14},
              {15,16,17,18}};

   vi result{spiral(matrix)};
   for(i number : result){
      std::cout<<number;
      std::cout<<" ";
   }
   std::cout<<std::endl;
}
