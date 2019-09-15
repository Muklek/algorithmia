#include<string>
#include<iostream>
#include<vector>
#include<algorithm>

// binary search approach
// complexity O(nlogn):
//      n -> needed to traverse the whole array
//      logn- -> start the search in the middle of the word
// space complexity: O(1)

bool compare(std::string& wordA, std::string& wordB){
    return wordA.size() < wordB.size();
}

bool checkPrefix(std::vector<std::string>& wordList, int& top, std::string prefix){
    for(std::string word:wordList){
        if(word.substr(0,top) != prefix){
            return false;
        }
    }
    return true;
}

std::string findLargest(std::vector<std::string>& wordList){
    std::sort(wordList.begin(),wordList.end(),compare);
    int higher{wordList[0].size() / 2};
    int lower{0};
    std::string prefix{wordList[0].substr(lower, higher)};
    while(lower<=higher){
        if(checkPrefix(wordList, higher, prefix) == true){
            lower += 1;
        }
        else{
            higher += 1;
        }
    }
    return wordList[0].substr(0,higher);
}

int main(){
    std::vector<std::string> words{"flower","fleet","flora"};
    std::string largestPrefix{findLargest(words)};
    std::cout<<largestPrefix<<std::endl;
}
