#include <bits/stdc++.h>

using namespace std;

int update(int a) {
  string s = to_string(a);
  int new_a = 0;
  for (char ch : s) {
    new_a += (ch-'0');
  }
  return new_a;
}

void solve(vector<int>& a, vector<vector<int>>& query) {
  int n = a.size();
  set<int> s;
  for (int i = 0; i < n; ++i) {
    if (a[i] > 9) s.insert(i);
  }

  for (vector<int>& q : query) {
    int type = q[0];
    if (type == 1) {
      int l = q[1]-1, r = q[2]-1;

      while (!s.empty()) {
        auto p = s.lower_bound(l);
        if (p == s.end() || *p > r) break;

        int index = *p;
        s.erase(p);

        a[index] = update(a[index]);
        if (a[index] > 9) {
          s.insert(index);
        }
        l = index+1;
      }
    } else if (type == 2) {
      int x = q[1]-1;
      cout << a[x] << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0, q = 0;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<int>> query;
    for (int i = 0; i < q; ++i) {
      int type = 0;
      cin >> type;
      if (type == 1) {
        int l = 0, r = 0;
        cin >> l >> r;
        query.push_back({type, l, r});
      } else if (type == 2) {
        int x = 0;
        cin >> x;
        query.push_back({type, x});
      }
    }

    solve(a, query);
  }
  return 0;
}
