#include<string>
#include<iostream>

int lastLength(std::string word){
    int wordSize{0};
    for(size_t i{word.size()-1};i>=0;i--){
        if(word[i]== ' '){
            break;
        }
        else{
            wordSize = i;
        }
    }
    return word.substr(wordSize, word.size()-1).size();
}

int main(){
    std::string word{"hello world"};
    std::cout<<lastLength(word)<<std::endl;
}
