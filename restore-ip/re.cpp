#include<iostream>
#include<vector>
#include<string>

typedef std::string st;
typedef std::vector<st> vst;

bool checkAddress(st& address){
   int front{0}, back{0};

   for(int i{0} ;i<address.size(); i++){
      if(address[i] == '.'){
         st sub{address.substr(back, i-back)};
         if(sub.compare("255") > 0 && sub.compare("-1") < 0) return false;
         back = i+1;
      }
      if(i == address.size()-1 && (i-back) >= 3) return false;
      //std::cout<<std::endl;
      //std::cout<<i<<std::endl;
      //std::cout<<back<<std::endl;
   }
   return true;

}

void generateString(st& raw, vst& results, int dots, int index){
   //std::cout<<raw<<std::endl;
   if(dots==4 && checkAddress(raw)){
      results.push_back(raw);
      return;
   }
   
   if(dots < 4 && index<raw.size()-1){
      raw.insert(raw.begin() + index + 1, '.');
      generateString(raw, results, ++dots, index+2);
      raw.erase(raw.begin() + index + 1);
      --dots;
   }
   if(dots < 4 && index<raw.size()-2){
      raw.insert(raw.begin() + index + 2, '.');
      generateString(raw, results, ++dots, index+3);
      raw.erase(raw.begin() + index + 2);
      --dots;
   }
   if(dots < 4 && index<raw.size()-3){
      raw.insert(raw.begin() + index + 3, '.');
      generateString(raw, results, ++dots, index+4);
      raw.erase(raw.begin() + index + 3);
      --dots;
   }
}


vst restoreIp(st& raw){
   vst result;
   generateString(raw, result, 0, 0);
   return result;
}



int main(){
    std::string raw{"25525511135"};
    //std::cout<<checkAddress(raw)<<std::endl;
    vst result{restoreIp(raw)};

    for(auto x : result){
      std::cout<<x<<std::endl;
    }
}
