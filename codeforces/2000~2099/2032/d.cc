#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int query(int a, int b) {
  cout << "? " << a << " " << b << endl;
  int r = -1;
  cin >> r;
  return r;
}

void answer(vector<int>& p) {
  cout << "! ";
  for (int i = 1; i < (int)p.size(); ++i) {
    cout << p[i] << " ";
  }
  cout << endl;
}

void solve() {
  int n = 0;
  cin >> n;

  vector<int> parent(n);

  vector<int> l0 = {1}, l1;
  int node = 2;
  while (node < n) {
    int r = query(node, 1);
    if (r) {
      parent[node] = 0;
      l0.push_back(node);
      node++;
    } else {
      parent[node] = 1;
      l1.push_back(node);
      node++;
      break;
    }
  }

  int j = 1;
  while (node < n && j < (int)l0.size()) {
    int r = query(node, l0[j]);
    if (!r) {
      parent[node] = l0[j];
      l1.push_back(node);
      node++;
      j++;
    } else {
      j++;
    }
  }

  while (node < n) {
    vector<int> l2;
    j = 0;
    while (node < n && j < (int)l1.size()) {
      int r = query(node, l1[j]);
      if (!r) {
        parent[node] = l1[j];
        l2.push_back(node);
        node++;
        j++;
      } else {
        j++;
      }
    }
    l1 = std::move(l2);
  }

  answer(parent);
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
