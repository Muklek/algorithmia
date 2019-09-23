#include<iostream>
#include<string>
#include<vector>
#include<iomanip>

class generateString{
   public:
      std::vector<int>  multiplier;
      void combination(std::string&, int&, std::string&);
      std::string decompress(std::string&);
};


void generateString::combination(std::string& compressedStr,
                                 int& index,
                                 std::string& localStr){
   std::string localResult{""};

   while(compressedStr[index] != ']'){
      if(std::isdigit(compressedStr[index])){
         multiplier.push_back(static_cast<int>(compressedStr[index] - '0'));
         index++;
         combination(compressedStr, index, localResult);
         index--;
      }
      else{
         if(compressedStr[index] != '[' && compressedStr[index] != ']'){
            localResult += compressedStr[index];
         }
      }
      ++index;
   }
   std::string const multiplierStr{localResult};
   while(multiplier.back() -1 > 0){
      localResult += multiplierStr;
      --multiplier.back();
   }
   localStr += localResult;
   ++index;
   multiplier.pop_back();

}

std::string generateString::decompress(std::string& compressedStr){
   std::string result{""};
   for(int i{0}; i<compressedStr.size(); i++){
      if(std::isdigit(compressedStr[i])){
         int num{(int) compressedStr[i] - '0'};
         multiplier.push_back(num);
         i++;
         combination(compressedStr, i, result);
         i--;
      }
      else{
         if(compressedStr[i] != ']') result+=compressedStr[i];
      }
   }
   return result;
}

int main(){
   std::string compressed1{"3[abc]4[ab]c"};
   std::string compressed2{"3[2[a]3[b]c]d"};
   std::string compressed3{"1[1[1[1[1[1[a]]]]]]"};

   generateString gs;
   auto const finalString1{gs.decompress(compressed1)};
   auto const finalString2{gs.decompress(compressed2)};
   auto const finalString3{gs.decompress(compressed3)};

   std::cout<<finalString1<<std::endl;
   std::cout<<finalString2<<std::endl;
   std::cout<<finalString3<<std::endl;
   
}

