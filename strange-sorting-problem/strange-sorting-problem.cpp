#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'strangeSort' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY mapping
 *  2. STRING_ARRAY nums
 */



inline int findIndex(vector<int>& mapping, int target){
   for(int i{0}; i<mapping.size(); i++) if(mapping[i] == target) return i;
   return -1;
}


inline tuple<int,string,int> makeTuple(int oPosition, string oValue, string mValue){
   int mappedValue;
   istringstream(mValue) >> mappedValue;

   return make_tuple(oPosition, oValue, mappedValue);
}

inline tuple<bool,int, int> similarConvertedValue(vector<tuple<int,string,int>>& resultMap){
   for(int i{0}; i<resultMap.size()-1; i++){
      if(get<2>(resultMap[i]) == get<2>(resultMap[i+1])){

         int const initialRange{i};
         while(i < resultMap.size()-1 && (get<2>(resultMap[i]) == get<2>(resultMap[i+1]))){
            ++i;
         }
         int const endRange{static_cast<int>(resultMap.size()) - i};
         return make_tuple(true,initialRange,endRange);
      }
   }
   return make_tuple(false,-1,-1);
}

inline void getValues(vector<tuple<int,string,int>>& resultMap, vector<string>& result){
   for(tuple<int,string,int> numTuple : resultMap){
      result.push_back(get<1>(numTuple));
   }
}

void generateValues(vector<int>& mapping,
                    vector<string>& nums,
                    vector<tuple<int,string,int>>& resultMap){
   int position{0};
   for(string numStr : nums){
      string value{""};
      for(int i{0}; i<numStr.size();i++){
         int valIndex{findIndex(mapping, static_cast<int>(numStr[i]- '0'))};
         if(valIndex != -1) value+= static_cast<char>(valIndex + '0');
      }
      tuple<int,string,int> localMappedTuple{makeTuple(position, numStr, value)};
      resultMap.push_back(localMappedTuple);
      position++;
   }
}

bool sortByConvertedValue(tuple<int,string,int> a, tuple<int,string,int> b){
   return(get<2>(a) < get<2>(b));
}

bool sortByOriginalPosition(tuple<int,string,int> a, tuple<int,string,int> b){
   return(get<0>(a) <  get<0>(b));
}

vector<string> strangeSort(vector<int> mapping, vector<string> nums) {
   vector<string> result;
   vector<tuple<int, string, int>> resultMap;

   result.reserve(nums.size());
   resultMap.reserve(nums.size());

   generateValues(mapping, nums, resultMap);

   sort(resultMap.begin(),resultMap.end(), sortByConvertedValue);

   tuple<bool,int,int> similarValues(similarConvertedValue(resultMap));
   if(get<0>(similarValues)){
      sort(resultMap.begin()+get<1>(similarValues),
           resultMap.end()-get<2>(similarValues), sortByOriginalPosition);
   }

   getValues(resultMap, result);

   return result;
}


// helper function used to print out the result
inline void print(auto& numbers){
   for(auto& number : numbers){
      cout<<number<<endl;
   }
   cout<<endl;
}

// code compiled with g++
int main(){
   //input case 1:
   vector<int> mapping_case_1{2,1,4,8,6,3,0,9,7,5};
   vector<string> nums_case_1{"12","02","4","023","65","83","224","50"};
   //expected output case 1:
   //4, 224, 12, 83, 65, 02, 50, 023
   //output case 1:
   cout<<"Output for case 1:"<<endl;
   auto const case_1{strangeSort(mapping_case_1, nums_case_1)};
   print(case_1);

   //input case 2:
   vector<int> mapping_case_2{0,1,2,3,4,5,6,7,8,9};
   vector<string> nums_case_2{"180","84","99","003","53","28","60","070","1"};
   //expected output case 2:
   //1, 003, 28, 53, 60, 070, 84, 99, 180
   //output case 2:
   cout<<"Output for case 2:"<<endl;
   auto const case_2{strangeSort(mapping_case_2, nums_case_2)};
   print(case_2);


   //input case 3:
   vector<int> mapping_case_3{4,8,2,5,0,3,1,6,7,9};
   vector<string> nums_case_3{"8","44438","291","4438","948","438","056"};
   //expected output case 3:
   //8, 44438, 4438, 438, 291, 056, 948
   //output case 3:
   cout<<"Output for case 3:"<<endl;
   auto const case_3{strangeSort(mapping_case_3, nums_case_3)};
   print(case_3);

}
