#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  vector<int> suffix_one;
  for (int i = 0; i < n; ++i) {
    int j = n-1;
    int one = 0;
    while (j >= 0 && a[i][j] == 1) {
      j--;
      one++;
    }
    if (one) {
      suffix_one.push_back(one);
    }
  }

  multiset<int> s(suffix_one.begin(), suffix_one.end());
  for (int i = 1; i < n; ++i) {
    auto it = s.lower_bound(i);
    if (it == s.end()) {
      cout << i << endl;
      return;
    }
    s.erase(it);
  }
  cout << n << endl;
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
