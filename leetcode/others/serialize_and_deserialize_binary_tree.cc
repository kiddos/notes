#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int value) {
  if (!root) {
    root = new TreeNode(value);
  } else if (value < root->val) {
    root->left = insert(root->left, value);
  } else {
    root->right = insert(root->right, value);
  }
  return root;
}

void cleanup(TreeNode* root) {
  if (root) {
    cleanup(root->left);
    cleanup(root->right);
    delete root;
  }
}

class Codec {
 public:
  string serialize(TreeNode* root) {
    stringstream ss;
    serialize(root, ss);
    return ss.str();
  }

  TreeNode* deserialize(const string& s) {
    stringstream ss(s);
    return construct(ss);
  }

 private:
  void serialize(TreeNode* root, stringstream& ss) {
    if (root) {
      ss << root->val << " ";
      serialize(root->left, ss);
      serialize(root->right, ss);
    } else {
      ss << "null ";
    }
  }

  TreeNode* construct(stringstream& ss) {
    string s;
    ss >> s;
    if (s != "null") {
      int val = stoi(s);
      TreeNode* root = new TreeNode(val);
      root->left = construct(ss);
      root->right = construct(ss);
      return root;
    }
    return nullptr;
  }
};

bool same(TreeNode* r1, TreeNode* r2) {
  if (!r1 && !r2) return true;
  if (r1 && !r2) return false;
  if (!r1 && r2) return false;
  return r1->val == r2->val && same(r1->left, r2->left) && same(r1->right, r2->right);
}

int main(void) {
  int n = 100;
  mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> dist(0, n * 10);

  TreeNode* root = nullptr;
  for (int i = 0; i < n; ++i) {
    root = insert(root, dist(gen));
  }

  Codec c;
  string s = c.serialize(root);
  cout << s << endl;

  TreeNode* new_root = c.deserialize(s);
  assert(same(root, new_root));

  cleanup(root);
  cleanup(new_root);
  return 0;
}
