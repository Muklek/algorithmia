#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>


const std::vector<std::string>& split(const std::string& line){
    static std::vector<std::string> tokens;
    int front{0},back{0};
    while(++front<line.size()){
        if(line[front] == ' '){
            tokens.push_back(line.substr(back,front-back));
            back=front+1;
        }
        if(front == line.size()-1){
            tokens.push_back(line.substr(back,(++front)-back));
        }
    }
    return tokens;
}


bool isValidPattern(std::string pattern, std::string para){
    std::unordered_map<char, std::string> combo;
    std::vector<std::string> splitted{split(para)};
    for(int i{0}; i<pattern.size(); i++){
        if(combo.count(pattern[i]) > 0){
            if(combo.at(pattern[i]) != splitted[i]){
                return false;
            }
        }
        else{
            combo[pattern[i]] = splitted[i];
        }
    }
    return true;
}


int main(){
    std::string pattern_a{"abbba"};
    std::string para_a{"dog cat cat cat dog"};

    std::string pattern_b{"abba"};
    std::string para_b{"dog cat cat fish"};

    std::cout<<isValidPattern(pattern_a,para_a)<<std::endl;
    std::cout<<isValidPattern(pattern_b,para_b)<<std::endl;
    

}
