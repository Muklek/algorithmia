#include<iostream>
#include<unordered_map>
#include<string>


bool isIsomorphic(std::string word_a, std::string word_b){
    std::unordered_map<char, char> combos;
    
    for(int i{0}; i<word_a.size(); i++){
        if(combos.count(word_a[i]) == 1){
            if(combos.at(word_a[i]) != word_b[i]){
                return false;
            }
        }
        else{
            combos[word_a[i]] = word_b[i];
        }
    }
    return true;
}




int main(){
    std::string word1_a{"egg"};
    std::string word1_b{"add"};

    std::string word2_a{"foo"};
    std::string word2_b{"bar"};

    std::string word3_a{"paper"};
    std::string word3_b{"title"};

    std::cout<<isIsomorphic(word1_a,word1_b)<<std::endl;
    std::cout<<isIsomorphic(word2_a,word2_b)<<std::endl;
    std::cout<<isIsomorphic(word3_a,word3_b)<<std::endl;
}
