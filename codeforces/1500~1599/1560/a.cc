#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_K = 1000;

vector<int> ans(MAX_K+1);

void precompute() {
  int i = 1;
  for (int k = 1; k <= MAX_K; ++k) {
    while (i % 3 == 0 || i % 10 == 3) {
      i++;
    }
    ans[k] = i++;
  }
}

void solve() {
  int k = 0;
  cin >> k;
  cout << ans[k] << endl;
}

int main(void) {
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
