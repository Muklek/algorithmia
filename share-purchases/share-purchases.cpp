#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the 'analyzeInvestments' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts STRING s as parameter.
 */

/*
 *
 * Problem solved by Muklek Bokth Choudhury
 * Email: muklek.bc@gmail.com
 * For the 2020 Summer Engineering Internship (London)
 *
 */

bool containsABC(string combination){
   bool foundA{false}, foundB{false}, foundC{false};

   for(int i{0}; i<combination.size(); i++){
      if(combination[i] == 'A'){
         foundA = true;
         if(foundB && foundC) return true;
         else do{i++;} while(i<combination.size() && combination[i] == 'A');
         if(combination[i] != 'B' && combination[i] != 'C') foundA = false;
      }

      if(combination[i] == 'B'){
         foundB = true;
         if(foundA && foundC) return true;
         else do{i++;} while(i<combination.size() && combination[i] == 'B');
         if(combination[i] != 'A' && combination[i] != 'C') foundB = false;
      }

      if(combination[i] == 'C'){
         foundC = true;
         if(foundA && foundB) return true;
         else do{i++;} while(i<combination.size() && combination[i] == 'C');
         if(combination[i] != 'A' && combination[i] != 'B') foundC = false;
      }

      if(foundA || foundB || foundC) --i;
   }
   return (foundA && foundB && foundC);
}


void getCombinations(string& initStr, unordered_set<string>& combinations){
   if(containsABC(initStr) && combinations.count(initStr) == 0){
      combinations.insert(initStr);
   }

   if(initStr.size() == 3) return;

   string prefix{initStr.substr(1,initStr.size())};
   if(containsABC(prefix)) getCombinations(prefix, combinations);

   string sufix{initStr.substr(0,initStr.size()-1)};
   if(containsABC(sufix)) getCombinations(sufix, combinations);

}

long analyzeInvestments(string s) {
   unordered_set<string> combinations;
   string initStr{s};

   getCombinations(initStr, combinations);

   return combinations.size();
}

// Code compiled with g++
int main()
{
   //sample case 1
   string string_case_1{"ABC"};
   long result_case_1 = analyzeInvestments(string_case_1);
   //output: 1
   cout<<"Output case 1: ";
   cout<<result_case_1<<endl;


   //sample case 2
   string string_case_2{"ABCCBA"};
   long result_case_2 = analyzeInvestments(string_case_2);
   //output: 7
   cout<<"Output case 2: ";
   cout<<result_case_2<<endl;


   //sample case 3
   string string_case_3{"PQACBA"};
   long result_case_3 = analyzeInvestments(string_case_3);
   //output: 7
   cout<<"Output case 3: ";
   cout<<result_case_3<<endl;
}
