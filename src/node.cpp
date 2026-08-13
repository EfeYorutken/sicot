#include <memory>
#include <iostream>

namespace node {

  class Node{

    public:

      char val;
      bool empty;
      std::unique_ptr<Node> left;
      std::unique_ptr<Node> right;

      Node(): val('\0'), empty(true), left(nullptr),right(nullptr){}
      Node(char v) : val(v), empty(false), left(nullptr),right(nullptr){}

      //additions when there are children should not be allowed
      bool add_left(std::unique_ptr<Node> n){
        bool res = this->left == nullptr;
        if(res){
          this->left = std::move(n);
        }
        return res;
      }

      bool add_right(std::unique_ptr<Node> n){
        bool res = this->right == nullptr;
        if(res){
          this->right = std::move(n);
        }
        return res;
      }

      void print(int indent = 0){

        for(int i = 0; i < indent;i++){ std::cout << "-"; }

        if(this->empty){ std::cout << "| </>" << std::endl; }
        else{ std::cout << "| " << this->val << std::endl; }

        if(this->left != nullptr){ this->left->print(indent+1); }
        if(this->right != nullptr){ this->right->print(indent+1); }

      }

  };

}
