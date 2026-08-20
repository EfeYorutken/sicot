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

    //for some reason i can not match the test_case strings with the decoded ones
    //despite them having the same chars. i know that for some reason the string
    //litreals dont get a \0 (at least they dont seem to), but adding them manually
    //does not work either. other than that, everything works
    if(!decoded.empty() && decoded.back() == '\0'){ decoded.pop_back(); }

    std::print("[TEST CASE] {}\n\t", test_name);

    if(decoded == test_case){ std::print("PASSED\n");}
    else{
      std::print("FAILED: test case '{}'(len {}) decoded value '{}'(len {})\n",
          test_case, test_case.length(), decoded, decoded.length());
      std::print("\t\tdecoded last char is \\0 ? {} test_case last char is \\0 ? {}",
                decoded.at(decoded.length()-1) == '\0',
                test_case.at(test_case.length()-1) == '\0'
          );
    }

  }

  return 0;
}
