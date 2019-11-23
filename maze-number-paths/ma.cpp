#include<iostream>
#include<vector>
#include<stack>

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

void traverse(vvi& map, int y, int x, int& paths){
   if(y == map.size()-1 && x == map[map.size()-1].size()-1){
      if(paths == 0) ++paths;
   }
   else if((y+1 < map.size() && map[y+1][x] == 0) &&
      (x+1 < map[y].size() && map[y][x+1] == 0)){

      if(y == 0 && x == 0) paths+=2;
      else paths++;

      traverse(map, y+1, x, paths);
      traverse(map, y, x+1, paths);
   }
   else if(y+1 < map.size() && map[y+1][x] == 0){
      traverse(map, y+1, x, paths);
   }
   else if(x+1 < map[y].size() && map[y][x+1] == 0){
      traverse(map, y, x+1, paths);
   }
   else --paths;
}

int getNumPaths(vvi& map){
   int paths{0};
   traverse(map, 0, 0, paths);
   return paths == -1 ? 0 : paths;
}

int main(){
   vvi map1{{0,1,1},
            {0,0,1},
            {1,0,0}};

   vvi map2{{0,0,1,1,1},
            {0,0,0,1,1},
            {0,1,0,0,0},
            {0,0,1,0,0}};

   vvi map3{{0,1,1},
            {1,0,1},
            {1,0,0}};

   int numPaths1{getNumPaths(map1)};
   int numPaths2{getNumPaths(map2)};
   int numPaths3{getNumPaths(map3)};

   std::cout<<numPaths1<<std::endl;
   std::cout<<numPaths2<<std::endl;
   std::cout<<numPaths3<<std::endl;
}

