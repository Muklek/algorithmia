#include<iostream>
#include<vector>

// non-recursive solution

struct TreeNode {
  int val{0};
  TreeNode* left{nullptr};
  TreeNode* right{nullptr};

  TreeNode(int v, TreeNode* l, TreeNode* r)
    :val(v), left(l), right(r){};
};

__attribute__((always_inline))
bool isSameTree(TreeNode& rootA, TreeNode& rootB){
  std::vector<TreeNode*> nodes{&rootA, &rootB};

  // i -> index;
  // s -> stopping point;
  // a -> last nodes added;
  for(int i{0}, s{1}, a{nodes.size()};
      i<nodes.size();
      i++){

    if(i == s) {

      for(int j{(i - a) + 1}, k{(i - a / 2) + 1}; k <= i; j++, k++){
        if(nodes[j] == nullptr & nodes[k] == nullptr) continue;

        if(nodes[j] == nullptr && nodes[k] != nullptr) return false;
        if(nodes[j] != nullptr && nodes[k] == nullptr) return false;

        if(nodes[j]->val != nodes[k]-> val) return false;
      }
      a = a * 2;
      s += a;
    }
    if(nodes[i] != nullptr) {
      nodes.push_back(nodes[i]->left);
      nodes.push_back(nodes[i]->right);
    }
  }
  return true;
}

int main(){
  TreeNode node1a{1, nullptr, nullptr};
  TreeNode node2a{3, nullptr, nullptr};
  TreeNode node3a{5, nullptr, nullptr};
  TreeNode node4a{2, nullptr, nullptr};
  TreeNode node5a{8, nullptr, nullptr};

  TreeNode node1b{1, nullptr, nullptr};
  TreeNode node2b{3, nullptr, nullptr};
  TreeNode node3b{5, nullptr, nullptr};
  TreeNode node4b{2, nullptr, nullptr};
  TreeNode node5b{8, nullptr, nullptr};

  node1a.right = &node2a;
  node1a.left = &node3a;
  node2a.right = &node4a;
  node3a.left = &node5a;

  node1b.right = &node2b;
  node1b.left = &node3b;
  node2b.right = &node4b;
  node3b.left = &node5b;

  bool result{isSameTree(node1a, node1b)};

  std::cout<<result<<'\n';
}

