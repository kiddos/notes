#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct LinkListNode {
  int value;
  LinkListNode* next;

  LinkListNode(int value) : value(value), next(nullptr) {}
  ~LinkListNode() {
    if (next) {
      delete next;
    }
  }
};

class DisjointSet {
 public:
  DisjointSet(int n) : parent_(n), sizes_(n, 1), head_(n, nullptr), tail_(n, nullptr) {
    iota(parent_.begin(), parent_.end(), 0);
    for (int i = 1; i < n; ++i) {
      LinkListNode* node = new LinkListNode(i);
      head_[i] = node;
      tail_[i] = node;
    }
  }

  int find(int x) {
    if (parent_[x] != x) {
      parent_[x] = find(parent_[x]);
    }
    return parent_[x];
  }

  void join(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) {
      return;
    }

    if (sizes_[px] >= sizes_[py]) {
      parent_[py] = px;
      sizes_[px] += sizes_[py];
      merge(px, py);
    } else {
      parent_[px] = py;
      sizes_[py] += sizes_[px];
      merge(py, px);
    }
  }

  LinkListNode* get_nodes(int x) {
    int px = find(x);
    return head_[px];
  }

  void merge(int px, int py) {
    LinkListNode* last = tail_[px];
    last->next = head_[py];
    tail_[px] = tail_[py];
  }

 private:
  vector<int> parent_;
  vector<int> sizes_;
  vector<LinkListNode*> head_;
  vector<LinkListNode*> tail_;
};


void solve() {
  int n = 0;
  cin >> n;
  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int x = 0, y = 0;
    cin >> x >> y;
    edges.emplace_back(x, y);
  }

  DisjointSet ds(n+1);

  int size = edges.size();
  for (int i = 0; i < size; ++i) {
    auto [x, y] = edges[i];
    ds.join(x, y);
  }

  LinkListNode* head = ds.get_nodes(1);
  LinkListNode* it = head;
  while (it) {
    cout << it->value << " ";
    it = it->next;
  }
  cout << endl;

  delete head;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
