#include <bits/stdc++.h>

using namespace std;

// Count Complete Tree Nodes
//
// its easy to come up with O(n) solution where n is the number of nodes
// to do this in O(log(n)^2)
// if left and right has same size
// its complete binary tree -> nodes = pow(2, n) - 1
// else its missing some nodes at the right

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
  ~TreeNode() {
    delete left;
    delete right;
  }
};

class Solution {
 public:
  int countNodes(TreeNode *root) {
    TreeNode *left = root, *right = root;
    int l = 0, r = 0;
    while (left) {
      left = left->left;
      l++;
    }
    while (right) {
      right = right->right;
      r++;
    }
    if (l == r) return (1 << l) - 1;
    return countNodes(root->left) + countNodes(root->right) + 1;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  TreeNode* root =  new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  int ans = Solution().countNodes(root);
  assert(ans == 5);

  delete root;
  return 0;
}
