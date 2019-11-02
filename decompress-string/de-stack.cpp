#include<iostream>
#include<string>
#include<vector>
#include<iomanip>

typedef std::string st;
typedef std::vector<int> vi;
typedef std::vector<st> vst;

// non-rescursive approach

st decompress(st& compressedStr){
   st result{""};
   vi multiplier;
   vst combinations;

   for(int i{0}; i<compressedStr.size(); i++){
      if(std::isdigit(compressedStr[i])){
         multiplier.push_back(static_cast<int>(compressedStr[i] - '0'));
         combinations.push_back(result);
         result = "";
         ++i;
      }
      else if(compressedStr[i] == ']'){
         st temp{""};
         int loop{multiplier.back()};

         while(loop-- > 0){
            temp += result;
         }

         result = combinations.back();
         result += temp;

         multiplier.pop_back();
         combinations.pop_back();
      }
      else result += compressedStr[i];
   }
   return result;
}

int main(){
   st compressed1{"3[abc]4[ab]c"};
   st compressed2{"3[2[a]3[b]c]d"};
   st compressed3{"1[1[1[1[1[1[a]]]]]]"};

   auto const finalString1{decompress(compressed1)};
   auto const finalString2{decompress(compressed2)};
   auto const finalString3{decompress(compressed3)};

   std::cout<<finalString1<<std::endl;
   std::cout<<finalString2<<std::endl;
   std::cout<<finalString3<<std::endl;
}

