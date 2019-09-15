#include<vector>
#include<iostream>
#include<algorithm>

int bestPnL(std::vector<int>& prices){
    int marginpnl{0},buy{0},sell{0};
    for(int i{0}; i<prices.size();i++){
        int localpnl{prices[sell]-prices[buy]};
        marginpnl=std::max(marginpnl,localpnl);
        if(i<=++sell){
            if(prices[buy]>prices[i]){
                buy=i;
            }
        }
    }
    return marginpnl;
}


int main(){
    std::vector<int> numbers{7,1,5,3,6,4};
    std::cout<<bestPnL(numbers)<<std::endl;
}
