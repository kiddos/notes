#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  ~TreeNode() {
    if (left) delete left;
    if (right) delete right;
  }
};

class Solution {
 public:
  int pathSum(TreeNode *root, int targetSum) {
    // prefix_sum + sum(path_sum) = currentSum
    unordered_map<int, int> prefix_sum;
    prefix_sum[0] = 1;
    int ans = 0;
    function<void(TreeNode *, int)> dfs = [&](TreeNode *node, int sum) {
      if (!node) return;
      sum += node->val;
      ans += prefix_sum[sum - targetSum];
      prefix_sum[sum]++;
      dfs(node->left, sum);
      dfs(node->right, sum);
      prefix_sum[sum]--;
    };
    dfs(root, 0);
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(-2);
  root->right = new TreeNode(-3);

  int target = -1;
  int ans = Solution().pathSum(root, target);
  assert(ans == 1);

  delete root;
  return 0;
}
