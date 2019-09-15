#include<iostream>
#include<algorithm>
#include<vector>


int margin(std::vector<int>& prices){
   int commulativePnL{0}, buy{0}, sell{0};
   for(int i{0}; i<prices.size()-1;i++){
       if(prices[i+1] < prices[sell]){
           commulativePnL += prices[sell] - prices[buy];
           sell++;
           buy=sell;
       }
       else if(i+2 == prices.size() &&
               prices[i+1] >= prices[buy]){
           commulativePnL+=prices[i+1] - prices[buy];
       }
       else{
           sell++;
       }
   }
   return commulativePnL;
}

int main(){
    std::vector<int> numbers1{7,1,5,3,6,4};
    std::vector<int> numbers2{1,2,3,4,5};
    std::cout<<margin(numbers1)<<std::endl;
    std::cout<<margin(numbers2)<<std::endl;
}
