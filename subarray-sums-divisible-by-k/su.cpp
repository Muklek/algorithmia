#include<iostream>
#include<vector>

// complexity o(n)
// additional space o(k)

inline __attribute__((always_inline))
int16_t getArrayDivisible(const std::vector<int16_t>& list, const int16_t& k){
  std::vector<int16_t> tracker; // remainder tracker;
  tracker.reserve(k);
  std::fill(tracker.begin(), tracker.end(), 0);
  tracker[0] = 1; // initialise when remainder = 0 = valid;

  int16_t count{0}, sum{0}, rem{0};

  for(const int16_t& number : list){
    sum += number;
    rem = sum % k;

    if(rem < 0) rem += k;

    count += tracker[rem];
    ++tracker[rem];
  }

  return count;
}



int main(){
  std::vector<int16_t> numbers{4,5,0,-2,-3,1};
  int16_t divisible{5};
  int16_t result{getArrayDivisible(numbers, 5)};

  std::cout<<"number of items: "<<result<<'\n';
}

