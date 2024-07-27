#include <bits/stdc++.h>

using namespace std;

struct Node {
  int val;
  Node* left;
  Node* right;

  Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
  if (!root) {
    return new Node(val);
  } else if (root->val >= val) {
    root->left = insert(root->left, val);
  } else {
    root->right = insert(root->right, val);
  }
  return root;
}

void cleanup(Node* root) {
  if (root) {
    cleanup(root->left);
    cleanup(root->right);
    delete root;
  }
}

class BSTIterator {
 public:
  BSTIterator(Node* root) {
    push_left(root);
  }

  virtual int next() {
    Node* node = lefts_.top();
    lefts_.pop();
    push_left(node->right);
    return node->val;
  }

  virtual bool has_next() { return !lefts_.empty(); }

 private:
  stack<Node*> lefts_;

  void push_left(Node* node) {
    while (node) {
      lefts_.push(node);
      node = node->left;
    }
  }
};

class PeekIterator : public BSTIterator {
 public:
  PeekIterator(Node* root) : BSTIterator(root), peeked_(false) {}

  int peek() {
    if (peeked_) return last_;
    peeked_ = true;
    last_ = BSTIterator::next();
    return last_;
  }

  int next() override {
    if (peeked_) {
      peeked_ = false;
      return last_;
    }
    return BSTIterator::next();
  }

  bool has_next() override { return peeked_ || BSTIterator::has_next(); }

 private:
  bool peeked_;
  int last_;
};

using Pair = pair<int, shared_ptr<PeekIterator>>;

class Merge {
 public:
  vector<int> mergeKTrees(vector<Node*> roots) {
    priority_queue<Pair, vector<Pair>, greater<Pair>> q;
    for (Node* root : roots) {
      shared_ptr<PeekIterator> it = make_shared<PeekIterator>(root);
      if (it->has_next()) {
        q.push({it->peek(), it});
      }
    }

    vector<int> ans;
    while (!q.empty()) {
      Pair p = q.top();
      q.pop();

      shared_ptr<PeekIterator> it = p.second;
      ans.push_back(it->next());
      if (it->has_next()) {
        q.push({it->peek(), it});
      }
    }

    return ans;
  }
};


int main(void) {
  constexpr int n = 1000;
  constexpr int k = 10;
  default_random_engine gen(chrono::system_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> dist(-n, n);

  vector<Node*> roots(k, nullptr);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      roots[j] = insert(roots[j], dist(gen));
    }
  }

  vector<int> ans = Merge().mergeKTrees(roots);
  int last_val = numeric_limits<int>::min();
  for (int a : ans) {
    assert(a >= last_val);
    cout << a << " ";
    last_val = a;
  }
  cout << endl;

  for (int j = 0; j < k; ++j) {
    cleanup(roots[j]);
  }
  return 0;
}
