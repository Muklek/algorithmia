#include<vector>
#include<string>
#include<iostream>

// could have bugs. Not tested.


inline void deleteReplicas(std::vector<char>& raw, int front, int back){
    while(front != back){
        raw.erase(raw.begin() + front);
        front--;
    }
}


void append(std::vector<char>& raw, int front, int back, int count){
    std::string stringCount{count};
    deleteReplicas(raw, front, back);
    if(count > 1 && count<10){
        raw.insert(raw.begin()+(back+1), stringCount[0]);
    }
    else if (count>9){
       for(int i{0}; i<stringCount.size();i++){
           raw.insert((raw.begin()+(back+1)), stringCount[i]);
       } 
    }
}


void compress(std::vector<char>& raw){
    int front{0},back{0}, charCount{0};
    while(front<raw.size()){
        if(raw[front] == raw[back]){
            front++;
        }
        else{
            charCount = (front - back) + 1;
            append(raw, front, back, charCount);
            back=front;
            front++;
            }
        }
}



int main(){
    std::vector<char> uncompressed{'a','a','b','b','c','c','c'};
    compress(uncompressed);
    for(char c : uncompressed){
        std::cout<<c<<std::endl;
    }
}
