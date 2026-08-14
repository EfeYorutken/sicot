#include "src/huffmann.cpp"

#include <vector>
#include <unordered_map>
#include <print>

//                    case          name
std::vector<std::pair<std::string, std::string>> tests = {

  { "","empty" },
  { "abc","one of each" },
  { "aaabc","many of one" },
  { "aaaabbbccd","many of many" },

};

int main(){

  for(auto test : tests){

    std::string test_case = test.first;
    std::string test_name = test.second;

    auto pair = huffman::encode( test_case );

    auto dict = pair.first;
    std::vector<bool> encoding = pair.second;

    std::string decoded = huffman::decode( dict, encoding );

    std::print("[TEST CASE] {}\t", test_name);std::cout << std::endl;

    if(decoded == test_case){ std::print("PASSED"); std::cout << std::endl;}
    else{
      std::print("FAILED: test case '{}' decoded value '{}'", test_case, decoded);std::cout << std::endl;
    }

  }

  return 0;
}
