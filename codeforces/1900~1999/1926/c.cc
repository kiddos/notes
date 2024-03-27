#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 200000;

vector<i64> ans(MAX_N+1);

void precompute() {
  for (int i = 1; i <= MAX_N; ++i) {
    int x = i;
    while (x > 0) {
      ans[i] += x % 10;
      x /= 10;
    }
    ans[i] += ans[i-1];
  }
}

void solve() {
  int n = 0;
  cin >> n;
  cout << ans[n] << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}