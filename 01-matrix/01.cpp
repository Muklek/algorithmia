#include<vector>
#include<iostream>
#include<unordered_map>


typedef int i;
typedef std::vector<i> vi;
typedef std::vector<vi> vvi;
typedef std::unordered_map<i, vi> mivi;
typedef std::pair<i, vi> pivi;

void printList(vvi&);

//non-recursive approach

std::pair<mivi, mivi> getPositions(vvi& matrix){
   mivi ones, zeroes;

   for(i row{0}; row<matrix.size(); row++){
      for(i col{0}; col<matrix[row].size(); col++){
         if(matrix[row][col] == 0){
            if(zeroes.count(row) > 0){
               zeroes.at(row).push_back(col);
            }
            else{
               zeroes.insert({row, vi{col}});
            }
         }
         else if(matrix[row][col] == 1){
            if(ones.count(row) > 0){
               ones.at(row).push_back(col);
            }
            else{
               ones.insert({row, vi{col}});
            }
         }
      }
   }
   return std::make_pair(zeroes, ones);
}

void markDistances(vvi& matrix, mivi zeroPos, i row, i col){
   i pathSum{99};

   for(pivi zeroes : zeroPos){
      i zRow{zeroes.first};
      for(i zCol : zeroes.second){
         i temp{std::abs((std::abs(row-zRow))+(std::abs(col-zCol)))-1};
         pathSum = std::min(pathSum, temp);

      }
   }
   matrix[row][col] = pathSum;
}

void mapDistances(vvi& matrix){
   std::pair<mivi,mivi> pos{getPositions(matrix)};
   mivi zeroMap{pos.first};
   mivi oneMap{pos.second};
   
   for(pivi ones : oneMap){
      i oRow{ones.first};
      for(i oCol : ones.second){
         markDistances(matrix, zeroMap, oRow, oCol);
      }
      
   }
}

void printList(vvi& matrix){
   for(auto row : matrix){
      for(auto col : row){
         std::cout<<col<<" ";
      }
      std::cout<<std::endl;
   }
}

int main(){
   vvi matrix{{0,1,0},
              {0,1,1},
              {1,1,1},
              {1,1,1},
              {1,1,1}};

   mapDistances(matrix);

   printList(matrix);
}
