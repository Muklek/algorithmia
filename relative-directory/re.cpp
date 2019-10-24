#include<string>
#include<iostream>

typedef std::string st;


void cleanDots(st& dir, int& index){
   while(dir[index] != '/'){
      dir.erase(dir.begin()+index);
      --index;
   }
   dir.erase(dir.begin()+index);
}

void moveDir(st& dir, int& index){
   cleanDots(dir, index);

   ++index;
   while(dir[index] == '.'){
      dir.erase(dir.begin()+index);
      --index;
   }
}


void stayDir(st& dir, int& index){
   cleanDots(dir, index);
}

void getRelativeDir(st& dir){
   int index{0};
   
   while(index < dir.size()){
      if(dir[index] == '.'){
         if(dir[index+1] == '.'){
            index -= 2;
            moveDir(dir, index);
         }
         else stayDir(dir, index);
      }
      ++index;
   }
}


int main(){
   st absolute_dir1{"/Users/X/Documents/../Desktop/./../"};
   st absolute_dir2{"/Users/X/Pictures/Pets/CuteCats/./../.././"};

   getRelativeDir(absolute_dir1);
   getRelativeDir(absolute_dir2);
   
   // /Users/X
   std::cout<<absolute_dir1<<std::endl;
   // /Users/X/Pictures
   std::cout<<absolute_dir2<<std::endl;
   
}
