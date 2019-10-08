#include<iostream>
#include<string>
#include<vector>

typedef std::string st;
typedef std::vector<int> vi;

st rotate(st word, vi& direction, vi& amount){
   
   for(int i{0}; i<direction.size(); i++){
      int const displacement{amount[i]};
      
      if(direction[i] == 0){
         int loop{word.size()};
         int posToMove{0}, currentIndex{0};
         char temp{' '}, value{word[currentIndex]};

         while(loop-- > 0){
            posToMove = currentIndex - displacement;
            posToMove += word.size();
            if(posToMove >= word.size()){
               posToMove = posToMove % word.size();
            }

            temp = word[posToMove];
            word[posToMove] = value;
            value = temp;
            currentIndex = posToMove;
         }
      }
      else if(direction[i] == 1){
         int loop{word.size()};
         int posToMove{0}, currentIndex{0};
         char temp{' '}, value{word[currentIndex]};

         while(loop-- > 0){
            posToMove = (currentIndex + displacement) % word.size();

            temp = word[posToMove];
            word[posToMove] = value;
            value = temp;
            currentIndex = posToMove;

         }
      }
   }
   return word;
}

int main(){
   st word{"arthe"};
   vi direction{1};
   vi amount{1};

   std::cout<<rotate(word, direction, amount)<<std::endl;

}
