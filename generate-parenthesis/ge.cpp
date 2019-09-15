#include<vector>
#include<iostream>
#include<string>


class parCombo{
    public:
        std::vector<std::string> combos;
        void generateCombos(std::string,int,int,int);
        void printCombos();
};


void parCombo::generateCombos(std::string combo, int comboMax, int open, int close){
    std::cout<<combo<<std::endl;
    if(combo.size() == (comboMax*2)){
        combos.push_back(combo);
    }
    if(open < comboMax){
        generateCombos("("+combo, comboMax, ++open, close);
    }
    if(close < open){
        generateCombos(")"+combo, comboMax, open, ++close);
    }
}

void parCombo::printCombos(){
    for(std::string combo : combos){
        std::cout<<combo<<std::endl;
    }
}


int main(){
    int maxComboLength{3};
    parCombo gen;
    std::string initial{""};
    gen.generateCombos(initial,maxComboLength,0,0);
    gen.printCombos();
}
