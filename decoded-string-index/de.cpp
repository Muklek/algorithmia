#include<iostream>
#include<string>

typedef std::string st;

char decodeAtIndex(st& word, int index){
   st combo{""}, localCombo{""};

   for(int i{0}, j{0}; word.size(); i++){
      if(std::isdigit(word[i])){
         j = i;
         while(j < word.size() && std::isdigit(word[j+1])) ++j;
         j = std::stoi(word.substr(i, (j+1)-i));
         
         if(combo.size() * j >= index){
            int k{(index % static_cast<int>(combo.size()))};
            return k == 0 ? combo[k] : combo[k-1];
         }
         else{
            while(--j > 0) localCombo += combo;
            combo += localCombo;
            localCombo = "";
         }
      }
      else combo += word[i];
   }
}

int main(){
   st s1{"lee2ban3"};
   int k1{10};
   
   st s2{"a23121121"};
   int k2{10};

   st s3{"a23121121"};
   int k3{0};
   
   std::cout<<decodeAtIndex(s1, k1)<<std::endl;
   std::cout<<decodeAtIndex(s2, k2)<<std::endl;
   std::cout<<decodeAtIndex(s3, k3)<<std::endl;
}
