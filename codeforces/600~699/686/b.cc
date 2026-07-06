#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<pair<int,int>> ans;
  auto move_to = [&](int i1, int i2) {
    for (int j = i1-1; j >= i2; --j) {
      ans.push_back({j, j+1});
      swap(a[j], a[j+1]);
    }
  };
  for (int i = 0; i < n; ++i) {
    int idx = i;
    for (int j = i; j < n; ++j) {
      if (a[j] < a[idx]) {
        idx = j;
      }
    }
    if (idx != i) {
      move_to(idx, i);
    }
  }

  for (auto [l, r] : ans) {
    cout << (l+1) << " " << (r+1) << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
