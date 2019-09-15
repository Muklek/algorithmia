#include<stack>
#include<iostream>
#include<unordered_map>
#include<string>

bool isValid(std::string parentesisCombo){
    std::unordered_map<std::string,std::string> validParentesis;
    std::stack<std::string> matches;
    
    validParentesis[")"]="(";
    validParentesis["]"]="[";

    for(int i{0}; i<parentesisCombo.size();i++){
        std::string csd{parentesisCombo[i]};
        std::string topElement{""};
        if(matches.size()>0){
            topElement = matches.top();
        }
        if(matches.size()>0 && validParentesis[csd] == topElement){
            matches.pop();
        }
        else{
            matches.push(csd);
        }
    }
    return matches.size()>0?true:false;
}




int main(){
    std::string conbo1{"()()()()"};
    std::string conbo2{"(([[]]))"};
    std::string conbo3{"(]))"};

    std::cout<<isValid(conbo1)<<std::endl;
    std::cout<<isValid(conbo2)<<std::endl;
    std::cout<<isValid(conbo3)<<std::endl;

}
