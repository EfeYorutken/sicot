#include "tree.cpp"

#include <vector>
#include <algorithm>
#include <unordered_map>

#include <print>

namespace huffman {

  std::pair<std::unordered_map<std::vector<bool>, char>, std::vector<bool>>
    encode(std::string str){ 

      if(str.length() == 0){ return {{}, {}}; }

      tree::Tree tree;
      std::vector<char> chars;
      std::vector<bool> encoded;
      std::unordered_map<std::vector<bool>, char> decoding_dict;
      std::unordered_map<char, int> freqs;
      auto sorter = [&freqs](char a, char b){ return freqs[a] > freqs[b]; };

      for(char c : str){ freqs[c]++; }

      for(auto p : freqs){ chars.push_back(p.first); }

      std::sort( chars.begin(), chars.end(), sorter );

      char current_char = chars.back();
      chars.pop_back();
      tree = tree::Tree(current_char);

      while(chars.size() > 1){
        char current_char = chars.back();
        chars.pop_back();

        tree.join(current_char);
      }

      std::unordered_map<char, std::vector<bool>> dict = tree.get_dict();
      decoding_dict.reserve(dict.size());

      for(auto p : dict){ decoding_dict[p.second] = p.first; }

      for(char c : str){
        auto encoding = dict[c];
        std::print("pushing {}\n", encoding );
        encoded.insert(encoded.end(), encoding.begin(), encoding.end());
      }

      return {decoding_dict, encoded};
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
