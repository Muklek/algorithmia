#include<iostream>
#include<vector>
#include<string>

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;


void flood(int sr,
      int sc,
      const int& target,
      const int& color,
      vvi& landscape){
   
   if(landscape[sr][sc] == target) landscape[sr][sc] = color;
   
   if(sr-1 >=  0 && landscape[sr-1][sc] == target){
      flood(sr-1, sc, target, color, landscape);
   } 
   if(sr+1 <= landscape.size()-1 && landscape[sr+1][sc] == target){
      flood(sr+1, sc, target, color, landscape);
   }
   if(sc+1 <= landscape[sr].size()-1 && landscape[sr][sc+1] == target){
      flood(sr, sc+1, target, color, landscape);
   }
   if(sc-1 >= 0 && landscape[sr][sc-1] == target){
      flood(sr, sc-1, target, color, landscape);
   }
}



int main(){
   vvi landscape{{1,1,1},
                  {1,1,0},
                  {1,0,1}};
   int const row{1};
   int const col{1};
   int const target(landscape[row][col]);
   flood(row,col, target, 2, landscape);

   for(auto x : landscape){
      for(auto y : x){
         std::cout<<y<<" ";
      }
      std::cout<<std::endl;
   }
}
