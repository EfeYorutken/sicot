#include "tree.cpp"

#include <vector>
#include <algorithm>
#include <unordered_map>

#include <print>

namespace huffman {

  std::pair<std::unordered_map<std::vector<bool>, char>, std::vector<bool>>
    encode(std::string str){

      if(str.length() == 0){ return { {},{} }; }

      std::unordered_map<std::vector<bool>, char> dict;
      std::unordered_map< char,std::vector<bool>> encode_dict;
      std::vector<bool> encoded;
      tree::Tree local_tree;

      std::unordered_map<char, int> freqs;
      std::vector<char> chars;

      for(char c : str){ freqs[c]++; }
      for(auto p : freqs){ chars.push_back(p.first); }

      std::sort(chars.begin(), chars.end(),
          [&freqs](char a, char b){ return freqs[a] > freqs[b]; }
          );

      local_tree = tree::Tree( chars.back() );
      chars.pop_back();

      while(chars.size() > 0){
        local_tree.join(chars.back());
        chars.pop_back();
      }

      encode_dict = local_tree.get_dict();

      for(char c : str){

        auto p = encode_dict[c];

        dict[p] = c;
        encoded.insert(encoded.end(), p.begin(), p.end());
      }

      return { dict, encoded };
    }

  std::string
    decode(std::unordered_map<std::vector<bool>, char> dict, std::vector<bool> encoded){

      if(encoded.empty()){ return ""; }

      std::vector<bool> temp;
      std::string res;

      for(auto bit : encoded){
        temp.push_back( bit );

        if(dict.contains(temp)){
          res += dict[temp];
          temp.clear();
        }

      }

      res += dict[temp];

      return res;
    }

}
