#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>

class tel{
    public:
        std::unordered_map<char,std::string> numberRecord{{'2',"abc"},{'3',"def"}};
        std::vector<std::string> charCombinations;
        void getCombinations(std::string);
        void localCombinations(std::string,std::string);
        void printCombinations();
};


void tel::localCombinations(std::string remaining_numbers, std::string charCombo){
    if(remaining_numbers.size() == 0){
        charCombinations.push_back(charCombo);
    }
    else{
        std::string charLocal{numberRecord.at(remaining_numbers[0])};
        for(int i{0};i<charLocal.size();i++){
            localCombinations(remaining_numbers.substr(1),charCombo+charLocal[i]);
        }
    }
}

void tel::getCombinations(std::string numbers){
    std::string characters{numberRecord.at(numbers[0])};
    for(int i{0}; i<characters.size(); i++){
        std::string comboStart{characters[i]};
        localCombinations(numbers.substr(1), comboStart);
    }
}


void tel::printCombinations(){
    for(auto combo : charCombinations){
        std::cout<<combo<<std::endl;
    }
}


int main(){
    tel telephoneCharCombos;
    telephoneCharCombos.getCombinations("23");
    telephoneCharCombos.printCombinations();
}
