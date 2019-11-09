#include<iostream>
#include<string>

typedef std::string st;


inline int getHigherVersion(st& a, st& b){
   int aFront{0}, aBack{0};
   int bFront{0}, bBack{0};

   while(aFront<a.size() && bFront<b.size()){
      while(a[aFront] != '.' && aFront < a.size()) ++aFront;
      while(b[bFront] != '.' && bFront < b.size()) ++bFront;

      int aVal{std::stoi(a.substr(aBack, aFront-aBack))};
      int bVal{std::stoi(b.substr(bBack, bFront-bBack))};

      if(aVal > bVal) return 1;
      if(aVal < bVal) return -1;
      aBack = ++aFront;
      bBack = ++bFront;
   }
   for(; aFront<a.size(); aFront++){
      if(a[aFront] != '.' && a[aFront] != '0') return 1;
   }
   for(; bFront<b.size(); bFront++){
      if(b[bFront] != '.' && b[bFront] != '0') return -1;
   }
   return 0;
}


int main(){
   st versionA_1{"0.1"};
   st versionA_2{"1.1"};

   st versionB_1{"000001.0.01.11.1"};
   st versionB_2{"1"};

   st versionC_1{"7.5.3.4"};
   st versionC_2{"7.5.3"};

   st versionD_1{"1.01"};
   st versionD_2{"1.001"};

   st versionE_1{"1.0"};
   st versionE_2{"1.0.0"};

   st versionF_1{"10.500"};
   st versionF_2{"10.500.0"};

   int aResult{getHigherVersion(versionA_1, versionA_2)};
   int bResult{getHigherVersion(versionB_1, versionB_2)};
   int cResult{getHigherVersion(versionC_1, versionC_2)};
   int dResult{getHigherVersion(versionD_1, versionD_2)};
   int eResult{getHigherVersion(versionE_1, versionE_2)};
   int fResult{getHigherVersion(versionF_1, versionF_2)};

   std::cout<<aResult<<std::endl;
   std::cout<<bResult<<std::endl;
   std::cout<<cResult<<std::endl;
   std::cout<<dResult<<std::endl;
   std::cout<<eResult<<std::endl;
   std::cout<<fResult<<std::endl;

}
