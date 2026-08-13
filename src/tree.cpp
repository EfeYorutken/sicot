#include "./node.cpp"
#include <memory>
#include <algorithm>
#include <vector>
#include <unordered_map>

namespace tree {
  class Tree{

    private:
      std::unique_ptr<node::Node> root;

      std::unordered_map<char, std::vector<bool>> bin2char(const std::unique_ptr<node::Node>& cur){
        if(!cur->empty){ return {{ cur->val, {} }}; }

        //left is 0, right is 1
        auto left = bin2char(cur->left);
        auto right = bin2char(cur->right);

        for(auto& a : left){ a.second.push_back(false);  }
        for(auto& a : right){ a.second.push_back(true);  }

        left.insert(right.begin(), right.end());

        return left;
      }

    public:
      Tree() : root(){}
      Tree(char c) {
        this->root = std::make_unique<node::Node>(node::Node(c));
      }

      void join(char c){

        auto new_node = std::make_unique<node::Node>(node::Node());
        auto new_char_node = std::make_unique<node::Node>(node::Node(c));
          
        new_node->add_left(std::move(new_char_node));
        new_node->add_right(std::move(this->root));

        this->root = std::move(new_node);
      }

      std::unordered_map<char, std::vector<bool>> get_dict(){
        return this->bin2char(this->root);
      }

      void print(){ this->root->print(); }

  };
}
