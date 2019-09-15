#include<iostream>
#include<deque>
#include<string>
#include<unordered_map>

// double ended queue (deque) data structure implementation

bool check(std::string combination){
    std::unordered_map<std::string,std::string> validMatch{{")","("}};
    std::deque<std::string> dStack;
    for(int i{0};i<combination.size();i++){
        dStack.push_back(combination.substr(i));
        if(validMatch.at(combination.substr(i))){
            dStack.pop_back();
            dStack.pop_front();
        }
    }
    if(dStack.size() > 0){
        return false;
    }
    else{
        return true;
    }
}



int main(){
    std::string combo1{"()"};
    std::string combo2{"(())"};
    std::string combo3{"()((("};
    std::cout<<check(combo1)<<std::endl; //true
    std::cout<<check(combo2)<<std::endl; // true
    std::cout<<check(combo3)<<std::endl; // false
}
