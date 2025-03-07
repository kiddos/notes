#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<pair<int,int>> merge(vector<pair<int,int>>& s) {
  sort(s.begin(), s.end());
  vector<pair<int,int>> s2;
  for (auto [l, r] : s) {
    if (s2.empty() || l > s2.back().second) {
      s2.push_back({l, r});
    } else {
      s2.back().second = max(s2.back().second, r);
    }
  }
  // for (auto [l, r] : s2) {
  //   cout << l<< " " << r << "   ";
  // }
  // cout << endl;
  return s2;
}

int total(vector<pair<int,int>>& s) {
  int total = 0;
  for (auto [l, r] : s) {
    total += r - l + 1;
  }
  return total;
}

void solve() {
  int n = 0, m = 0, q = 0;
  cin >> n >> m >> q;
  vector<int> a(q);
  for (int i = 0; i < q; ++i) {
    cin >> a[i];
  }

  vector<pair<int,int>> s = {{m, m}};
  for (int i = 0; i < q; ++i) {
    vector<pair<int,int>> s2;
    for (auto [l, r] : s) {
      if (l > a[i]) {
        s2.push_back({l-1, r});
      } else if (r < a[i]) {
        s2.push_back({l, r+1});
      } else if (l <= a[i] && a[i] <= r) {
        if (r-l+1 > 1) {
          s2.push_back({l, r});
        }
        s2.push_back({1, 1});
        s2.push_back({n, n});
      }
    }
    s = merge(s2);
    cout << total(s) << " ";
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
