#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>

typedef std::string st;
typedef std::vector<st> vst;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::unordered_set<int> ui;


ui getAliveRule(vst& rules){
   ui numCell;
   for(int i{0}; i<rules.size(); i++){
      if(rules[i] == "alive"){
         numCell.insert(i);
      }
   }
   return numCell;
}


inline void iterateState(vvi& table, ui& aliveCells, int numOfSteps){
   
   do{
      for(int row{0}; row<table.size(); row++){
         for(int col{0}; col<table[row].size(); col++){
            int numOfCells{0};

            bool incrementRow{row+1 < table.size()};
            bool decrementRow{row-1 >= 0};
            bool incrementCol{col+1 < table[row].size()};
            bool decrementCol{col-1 >= 0};
            
            //value of cells
            if(decrementRow && table[row-1][col] == 1) ++numOfCells;
            if(incrementRow && table[row+1][col] == 1) ++numOfCells;
            if(decrementCol && table[row][col-1] == 1) ++numOfCells;
            if(incrementCol && table[row][col+1] == 1) ++numOfCells;
            if(decrementCol && decrementRow && table[row-1][col-1] == 1) ++numOfCells;
            if(incrementCol && incrementRow && table[row+1][col+1] == 1) ++numOfCells;
            if(incrementCol && decrementRow && table[row-1][col+1] == 1) ++numOfCells;
            if(decrementCol && incrementRow && table[row+1][col-1] == 1) ++numOfCells;
            
            // convert values
            table[row][col] = numOfCells;

         }
      }
      for(int row{0}; row<table.size(); row++){
         for(int col{0}; col<table[row].size(); col++){
            if(aliveCells.count(table[row][col]) > 0){
               table[row][col] = 1;
            }
            else{
               table[row][col] = 0;
            }
         }
      }


   }while(numOfSteps-- > 0);
}



void start(vvi& table, vst& rules, int numOfSteps){
   ui numCell{getAliveRule(rules)};
   iterateState(table, numCell, numOfSteps);
}


int main(){
   vvi table{{0,1,0,0},{0,0,0,0}};
   vst rules{"dead","alive","dead",
             "alive","dead","dead",
             "dead","dead","dead"};
   int numOfSteps{2};
   start(table, rules, numOfSteps);

   for(auto row : table){
      for(auto col : row){
         std::cout<<col<<" ";
      }
      std::cout<<std::endl;
   }
}
