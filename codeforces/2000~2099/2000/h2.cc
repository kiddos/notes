#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct TreapNode {
  pair<int,int> key;
  int priority;
  TreapNode* left;
  TreapNode* right;
  TreapNode(pair<int,int> key, int priority) : key(key), priority(priority), left(nullptr), right(nullptr) {}
  ~TreapNode() {
    if (left) delete left;
    if (right) delete right;
  }
};

void split(TreapNode* node, pair<int,int> key, TreapNode** left, TreapNode** right) {
  if (!node) {
    *left = *right = nullptr;
  } else if (node->key <= key) {
    split(node->right, key, &node->right, right);
    *left = node;
  } else {
    split(node->left, key, left, &node->left);
    *right = node;
  }
}

void merge(TreapNode** node, TreapNode* left, TreapNode* right) {
  if (!left || !right) {
    *node = left ? left : right;
  } else if (left->priority < right->priority) {
    merge(&left->right, left->right, right);
    *node = left;
  } else {
    merge(&right->left, left, right->left);
    *node = right;
  }
}

void insert(TreapNode** root, TreapNode* node) {
  if (!*root) {
    *root = node;
  } else if (node->priority < (*root)->priority) {
    split(*root, node->key, &node->left, &node->right);
    *root = node;
  } else {
    if ((*root)->key <= node->key) {
      insert(&(*root)->right, node);
    } else {
      insert(&(*root)->left, node);
    }
  }
}

void erase(TreapNode** root, pair<int,int> key) {
  if (!(*root)) {
    return;
  }

  if ((*root)->key == key) {
    TreapNode* temp_root = *root;
    merge(root, (*root)->left, (*root)->right);
    temp_root->left = temp_root->right = nullptr;
    delete temp_root;
  } else {
    if (key < (*root)->key) {
      erase(&((*root)->left), key);
    } else {
      erase(&((*root)->right), key);
    }
  }
}

void traverse(TreapNode* node, int indent) {
  if (!node) {
    return;
  }
  cout << string(indent, ' ');
  cout << "key=" << node->key.first << "," << node->key.second << ", priority=" << node->priority << endl;
  traverse(node->left, indent + 2);
  traverse(node->right, indent + 2);
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  TreapNode* root = nullptr;

  auto insert_interval = [&](pair<int,int>& p) {
    int len = p.second - p.first + 1;
    int left = p.first;
    pair<int,int> key = {len, left};
    TreapNode* node = new TreapNode(key, left);
    insert(&root, node);
  };

  auto erase_interval = [&](pair<int,int> key) {
    erase(&root, key);
  };

  auto query = [&](int len) {
    TreapNode *left = nullptr, *right = nullptr;
    pair<int,int> key = {len, -1};
    split(root, key, &left, &right);
    // cout << "len=" << len << endl;
    // cout << "right node " << right << endl;
    // if (left) {
    //   cout << "left=" << left->priority << endl;
    // }
    assert(right);
    // cout << "min left: " << right->priority << endl;
    int result = right->priority;
    merge(&root, left, right);
    return result;
  };

  constexpr int MAX_A = 5000000;
  vector<pair<int,int>> intervals;

  for (int i = 0, last = 0; i < n; ++i) {
    if (a[i] != last + 1) {
      int start = last + 1;
      int end = a[i] - 1;
      intervals.emplace_back(start, end);
    }
    last = a[i];
  }
  intervals.emplace_back(a.back() + 1, MAX_A);

  map<int,int> miss;
  for (auto& p : intervals) {
    // cout << p.first << "~" << p.second << endl;
    insert_interval(p);
    miss[p.second] = p.first;
  }

  int m = 0;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    char op = '\0';
    cin >> op;
    if (op == '+') {
      int x = 0;
      cin >> x;

      auto it = miss.lower_bound(x);
      if (it != miss.end() && it->second <= x) {
        pair<int,int> left = {it->second, x-1};
        pair<int,int> right = {x+1, it->first};

        erase_interval({it->first - it->second + 1, it->second});
        miss.erase(it);

        if (left.first <= left.second) {
          insert_interval(left);
          miss[left.second] = left.first;
        }
        if (right.first <= right.second) {
          insert_interval(right);
          miss[right.second] = right.first;
        }
      }
    } else if (op == '-') {
      int x = 0;
      cin >> x;

      pair<int,int> p = {x, x};
      auto it = miss.lower_bound(x);
      if (it != miss.end() && it->second == x + 1) {
        p.second = it->first;
        erase_interval({it->first - it->second + 1, it->second});
        miss.erase(it);
      }
      it = miss.upper_bound(x);
      if (it != miss.begin() && prev(it)->first == x - 1) {
        --it;
        p.first = it->second;
        erase_interval({it->first - it->second + 1, it->second});
        miss.erase(it);
      }
      insert_interval(p);
      miss[p.second] = p.first;
    } else if (op == '?') {
      int k = 0;
      cin >> k;
      int ans = query(k);
      cout << ans << " ";
    }

    // traverse(root, 0);
  }
  cout << endl;

  if (root) {
    delete root;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
