#include<string>
#include<iostream>
#include<vector>

typedef std::string st;


inline int getLengthFirstWord(st& word){
   for(int i{0}; i<word.size(); i++){
      if(word[i] == ' ') return i;
   }
}


std::vector<st> getMissingWords(st& o, st& m){
   std::vector<st> result;
   int oFront{getLengthFirstWord(o)}, oBack{0};
   int mFront{getLengthFirstWord(m)}, mBack{0};
   
   while(oFront < o.size()){

      while(o[oFront] != ' ' && oFront <= o.size()) oFront++;

      if(o[oBack] == ' ') oBack++;
      if(m[mBack] == ' ') mBack++;

      if(o.substr(oBack, oFront-oBack) == m.substr(mBack, mFront-mBack)){
         
         if(mFront < m.size()){
            mBack = mFront;
            mFront++;
            while(m[mFront] != ' ' && mFront <= m.size()) mFront++;
   
         }

         oBack = oFront;
         oFront++;

      }
      else if(o.substr(oBack, oFront-oBack) != m.substr(mBack, mFront-mBack)){
         result.push_back(o.substr(oBack, oFront-oBack));

         oBack = oFront;
         oFront++;
      }

   }
   return result;
}



int main(){
   st t{"I am using hackerrank to improve programming"};
   st s{"am hackerrank to improve"};
   std::vector<st> result{getMissingWords(t, s)};
   for(auto const word : result){
      std::cout<<word<<std::endl;
   }
}
