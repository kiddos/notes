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

  map<int,int> count;
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }

  int side_count = 0;
  i64 symmetric = 0;
  for (auto& [side, c] : count) {
    i64 take = c / 2 * 2;
    symmetric += take * side;
    side_count += take;
    c %= 2;
  }

  if (symmetric == 0) {
    cout << "0" << endl;
    return;
  }

  vector<int> rest;
  for (auto [side, c] : count) {
    if (c > 0) {
      rest.push_back(side);
    }
  }

  i64 ans = 0;
  if (side_count >= 3) {
    ans = symmetric;
  }
  int size = rest.size();
  for (int i = size-1; i >= 0; --i) {
    int other = i > 0 ? rest[i-1] : 0;
    if (rest[i] < symmetric + other) {
      ans = max(ans, symmetric + other + rest[i]);
    }
  }
  cout << ans << endl;
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
