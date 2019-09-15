#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>

typedef int i;
typedef size_t st;
typedef std::vector<i> vi;
typedef std::vector<vi> vvi;
typedef std::unordered_map<i, vi> m_ivi;

i search(vi& numbers, i target){
   for(auto number : numbers){
      if(number == target) return number;
   }
   return -1;
}

i negativeRange(vi& number){
   for(i x{0}; x<number.size(); x++){
      if(number[x] > 0) return x-1;
   }
   return -1;
}

vvi combinations(vi& numbers){
   vvi zeroSum;
   std::sort(numbers.begin(), numbers.end());
   i range{negativeRange(numbers)};

   if(range == -1) return zeroSum;

   for(st x{0}; x<range; x++){
      i front{numbers[x]};
      for(st y{x+1}; y<numbers.size(); y++){
         i back{numbers[y]};
         i remainder{back+front};
         if(remainder < 0){
            remainder *= -1;
         }
         i element{search(numbers,remainder)};
         if(element != -1){
            vi combos{front,back,element};
            zeroSum.push_back(combos);
         }
      }
   }
   return zeroSum;
}

int main(){
   vi numbers{-1, 0, 1, 2, -1, -4};
   vi numbers1{-4,-1,0,1,2,3};
   vvi combos{combinations(numbers1)};

   for(auto x : combos){
      for(auto y : x){
         std::cout<<y;
         std::cout<<" ";
      }
      std::cout<<std::endl;
   }
}
