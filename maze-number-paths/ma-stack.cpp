#include<iostream>
#include<vector>
#include<stack>
#include<tuple>

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::tuple<int,int> tii;
typedef std::stack<tii> stii;

int getNumPaths(vvi& map){
   int paths{0}, y{0}, x{0};
   stii positions;

   tii origin{std::make_tuple(y, x)};
   positions.push(origin);

   while(!positions.empty()){
      if(y == map.size()-1 && x == map[y].size()-1){
         positions.pop();
         if(!positions.empty()) y = std::get<0>(positions.top());
         if(!positions.empty()) x = std::get<1>(positions.top());
         if(paths == 0) ++paths;
      }
      else if((y+1 < map.size() && map[y+1][x] == 0) &&
         (x+1 < map[y].size() && map[y][x+1] == 0)){

         if(y == 0 && x == 0) paths += 2;
         else ++paths;

         tii down{std::make_tuple(y+1, x)};
         tii right{std::make_tuple(y, x+1)};
         positions.pop();
         positions.push(down);
         positions.push(right);
         y = std::get<0>(positions.top());
         x = std::get<1>(positions.top());
      }
      else if(y+1 < map.size() && map[y+1][x] == 0) ++y;
      else if(x+1 < map[y].size() && map[y][x+1] == 0) ++x;
      else{
         if(paths > 0) --paths;

         positions.pop();
         if(!positions.empty()) y = std::get<0>(positions.top());
         if(!positions.empty()) x = std::get<1>(positions.top());
      }
   }
   return paths;
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

