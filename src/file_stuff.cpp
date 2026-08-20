#include <fstream>
#include <ios>
#include <string>
#include <vector>
#include <unordered_map>

namespace {

  //specifically convert the mapping to <char>\t<bin> pairs
  bool write_dict_to_file(std::unordered_map<std::vector<bool>, char> dict, std::string file_name){ 

    std::fstream fs(file_name, std::ios::out);

    for(auto p : dict){

      //i am just bored at this point
      std::string to_write = "";

      for(auto bit : p.first){ to_write += bit ? "1" : "0"; }

      to_write = p.second + "\t" + to_write;

      fs.write(to_write.c_str(), to_write.length());

    }

    return false;
  }

  //probably redundent, figure out if there is an 0cost abstraction for these
  std::string read_string_from_file(std::string file_name){ return ""; }
  std::string read_dict_from_file(std::string file_name){ return ""; }

}

namespace filestuff {

  //write these using the functions in the nameless namespace
  bool write(std::vector<bool> encoding, std::unordered_map<char, std::vector<bool>> dict){}
  pair<void, void> read(std::vector<bool> encoding, std::unordered_map<char, std::vector<bool>> dict){}

}
