#include <bits/stdc++.h>

using namespace std;

// Recover Binary Search Tree
//
// the idea is to do inorder traversal
// for BST inorder traversal should be sorted
// so find the first and last node that voilates that condition

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  ~TreeNode() {
    if (left) delete left;
    if (right) delete right;
  }
};

class Solution {
 public:
  void recoverTree(TreeNode* root) {
    TreeNode *prev = nullptr, *first = nullptr, *second = nullptr;
    function<void(TreeNode*)> inorder = [&](TreeNode* node) {
      if (!node) return;
      inorder(node->left);
      if (prev && node->val < prev->val && !first) {
        first = prev;
      }
      if (prev && node->val < prev->val && first) {
        second = node;
      }
      prev = node;
      inorder(node->right);
    };
    inorder(root);
    swap(first->val, second->val);
  }
};

void inorder(TreeNode* root) {
  if (!root) return;
  inorder(root->left);
  cout << root->val << " ";
  inorder(root->right);
}

int main(void) {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(3);
  root->left->right = new TreeNode(2);

  Solution().recoverTree(root);
  inorder(root);

  delete root;
  return 0;
}
