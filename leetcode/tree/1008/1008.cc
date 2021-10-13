#include <bits/stdc++.h>

using namespace std;

// Construct Binary Search Tree from Preorder Traversal
//
// My initial solution was O(n*n) where I find the right node in linear time
//
// This idea is to continue to build the left part of the tree
// if current preorder[index] < root->val
// else build the right part of the tree with numeric_limits<int>::max()

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
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    int n = preorder.size();
    int index = 0;
    function<TreeNode*(int)> build = [&](int bound) {
      if (index >= n || preorder[index] > bound) return (TreeNode*)nullptr;
      TreeNode* root = new TreeNode(preorder[index++]);
      root->left = build(root->val);
      root->right = build(bound);
      return root;
    };
    return build(numeric_limits<int>::max());
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> preorder = {8,5,1,7,10,12};

  TreeNode* root = Solution().bstFromPreorder(preorder);
  delete root;
  return 0;
}
