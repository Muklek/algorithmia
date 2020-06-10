#include<iostream>
#include<string_view>

bool isSubsequence(const std::string& s,
                   const std::string& t) {


  size_t tSize{t.size()}, sSize{s.size()}, sIndex{0};

  if(tSize == 0 || sSize == 0) return false;

  for(size_t tIndex{0}; tIndex < tSize; tIndex++) {
    if(sIndex < sSize && t[tIndex] == s[sIndex]) ++sIndex;
  }
  return sIndex == sSize;
};


int main(){
  std::string s1{"abc"};
  std::string t1{"ahbgdc"};

  std::string s2{"abc"};
  std::string t2{"aec"};

  std::string s3{"abcc"};
  std::string t3{"ahbgcdc"};

  bool result1{isSubsequence(s1, t1)};
  bool result2{isSubsequence(s2, t2)};
  bool result3{isSubsequence(s3, t3)};

  std::cout<<result1<<'\n';
  std::cout<<result2<<'\n';
  std::cout<<result3<<'\n';
}
