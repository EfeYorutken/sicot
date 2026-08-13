#include "huffmann.cpp"

#include <print>
#include <unordered_map>

using namespace std;

int main(){

  std::unordered_map<std::vector<bool>, char> dict;
  std::vector<bool> encoding;
  std::string test = "hello there-general kenobi!!";

  std::pair<decltype(dict), decltype(encoding)> pair = huffman::encode(test);

  encoding = pair.second;
  dict = pair.first;

  for(bool bit : encoding){
    if(bit){ std::cout << "1"; }
    else{    std::cout << "0"; }
  }

  cout << endl;

  for(auto a : dict){
    std::print("{} => {}\n", a.first, a.second);
  }

  cout << "----------" << endl;

  string decoded = huffman::decode( dict, encoding );

  print("{}\n", decoded);

  return 0;
}
