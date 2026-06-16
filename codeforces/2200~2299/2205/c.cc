#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void append(vector<int>& a, const vector<int>& b) {
  list<int> d;
  int n = a.size();
  unordered_map<int, list<int>::iterator> pos;

  for (int i = 0; i < n; ++i) {
    d.push_back(a[i]);
    pos[a[i]] = prev(d.end());
  }
  for (int x : b) {
    if (pos.count(x)) {
      auto it = pos[x];
      d.erase(it);
      d.push_front(x);
      pos[x] = d.begin();
    } else {
      d.push_front(x);
      pos[x] = d.begin();
    }
  }
  a = vector<int>(d.begin(), d.end());
}


void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> a(n);
  for (int i = 0; i < n; ++i) {
    int l = 0;
    cin >> l;
    for (int j = 0; j < l; ++j) {
      int aj = 0;
      cin >> aj;
      a[i].push_back(aj);
    }
  }

  for (int i = 0; i < n; ++i) {
    int size = a[i].size();
    set<int> s;
    vector<int> l;
    for (int j = size-1; j >= 0; --j) {
      if (!s.count(a[i][j])) {
        s.insert(a[i][j]);
        l.push_back(a[i][j]);
      }
    }
    reverse(l.begin(), l.end());
    a[i] = l;
  }

  vector<bool> used(n);
  set<int> added;
  vector<vector<int>> c;
  for (int i = 0; i < n; ++i) {
    vector<pair<vector<int>, int>> b;
    for (int j = 0; j < n; ++j) {
      if (used[j]) {
        continue;
      }
      vector<int> l2;
      for (int e : a[j]) {
        if (!added.count(e)) {
          l2.push_back(e);
        }
      }
      b.push_back({l2, j});
    }
    auto comp = [&](auto& l1, auto& l2) {
      vector<int> x(l1.first.rbegin(), l1.first.rend());
      vector<int> y(l2.first.rbegin(), l2.first.rend());
      return x < y;
    };
    auto it = min_element(b.begin(), b.end(), comp);
    int idx = it->second;

    for (int e : it->first) {
      added.insert(e);
    }
    used[idx] = true;
    // cout << "idx="<< idx << endl;
    c.push_back(a[idx]);
  }

  reverse(c.begin(), c.end());

  vector<int> ans;
  for (vector<int>& l : c) {
    // for (int x : l) {
    //   cout << x << " ";
    // }
    // cout << endl;
    append(ans, l);
  }
  for (int x : ans) {
    cout << x << " ";
  }
  cout << endl;
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
