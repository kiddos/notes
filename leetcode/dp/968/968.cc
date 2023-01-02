#include <bits/stdc++.h>

using namespace std;

// Binary Tree Cameras
//
// 2 ways to think of this problem
// - a greedy way
//  3 state to represent a node
//  - has camera
//  - covered by other camera
//  - not covered
//
//  if the left or right node already has a camera
//   this parent node state should be "covered"
//  else if the left or right not is "not covered"
//   this parent node state should be "has camera", which answer should increment by 1
//  else
//   this parent node state should be "not covered"
//
//
// - DP way
//  compute 3 best result
//   - has camera
//   - covered by other camera
//   - not covered
//
//  the result for current node should be
//   - has_camera = 1 + min(left has camera, covered or not covered) + min(right has camera, covered, or not covered)
//   - covered = min(left has camera + min(right has camera, right covered), right has camera + min(left has camera, left covered))
//   - not covered = left covered + right covered

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

enum State {
  HAS_CAMERA,
  COVERED,
  NOT_COVERED,
};

class Solution {
 public:
  int minCameraCover(TreeNode* root) {
    int ans = 0;
    function<State(TreeNode*)> dfs = [&](TreeNode* node) {
      if (!node) return COVERED;
      State l = dfs(node->left);
      State r = dfs(node->right);
      if (l == NOT_COVERED || r == NOT_COVERED) {
        ans++;
        return HAS_CAMERA;
      } else {
        if (l == HAS_CAMERA || r == HAS_CAMERA) {
          return COVERED;
        }
        return NOT_COVERED;
      }
    };
    State r = dfs(root);
    if (r == NOT_COVERED) ans++;
    return ans;
  }
};

struct Result {
  int not_covered, covered, has_camera;
};

class Solution2 {
 public:
  int minCameraCover(TreeNode* root) {
    const int INF = 1e9;
    function<Result(TreeNode*)> dfs = [&](TreeNode* node) {
      if (!node) return Result{0, 0, INF};
      Result l = dfs(node->left);
      Result r = dfs(node->right);
      return Result{l.covered + r.covered,
                    min(l.has_camera + min(r.has_camera, r.covered),
                        r.has_camera + min(l.has_camera, l.covered)),
                    1 + min({l.not_covered, l.covered, l.has_camera}) +
                        min({r.not_covered, r.covered, r.has_camera})};
    };
    Result result = dfs(root);
    return min(result.covered, result.has_camera);
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}
