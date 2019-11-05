#include<vector>
#include<string>
#include<iostream>

typedef std::string st;
typedef std::vector<char> vc;



void deleteReplicas(vc& raw, int& front, int& back){
   while(front != back){
      raw.erase(raw.begin()+front);
      --front;
   }
   ++front;
}

void compress(vc& raw, int& front, int& back, int count){
   deleteReplicas(raw, front, back);
   if(count < 9){
      raw.insert(raw.begin()+back, static_cast<char>(count + '0'));
      ++front;
   }
   else {
      st countStr{std::to_string(count)};
      for(int i{0}; i<countStr.size(); i++){
         raw.insert(raw.begin()+back, countStr[i]);
         ++back; ++front;
      }
   }
}


void compress(vc& raw){
   int back{0}, charCount{0};

   for(int i{0}; i<raw.size(); i++){
      std::cout<<i<<" "<<back<<std::endl;  
      if(i+1 == raw.size() && i-back >= 1){
         compress(raw, i, back, (i-back)+1);
      }
      else if(raw[i+1] != raw[back] && i+1 - back == 1){
         ++back;
      }
      else if(raw[i+1] != raw[back] && i-back > 1){
         compress(raw, i, back, (i-back)+1);
         back = i;
         --i;
      }
   }
   std::cout<<std::endl;
}


void print(vc& raw){
   for(auto const x : raw) std::cout<<x<<" ";
   std::cout<<std::endl;
}


int main(){
   vc uncompressed1{'a','a','b','b','c','c','c'};
   vc uncompressed2{'a','b','b','b','b','b','c','c','c'};
   vc uncompressed3{'f','a','a','a','a','a','a','a','a','a','a','b','c','d','d'};
   compress(uncompressed1);
   compress(uncompressed2);
   compress(uncompressed3);
   print(uncompressed1);    
   print(uncompressed2);    
   print(uncompressed3);    
}
