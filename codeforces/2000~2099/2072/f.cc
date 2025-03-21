#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 1000000;
vector<i64> p2(MAX_N+1);

void precompute() {
  for (int i = 1; i <= MAX_N; ++i) {
    int x = i;
    while (x % 2 == 0) {
      p2[i]++;
      x /= 2;
    }
  }

  for (int i = 1; i <= MAX_N; ++i) {
    p2[i] += p2[i-1];
  }
}

int c_mod2(int n, int k) {
  i64 top = p2[n];
  i64 bot = p2[k] + p2[n-k];
  return top > bot ? 0 : 1;
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  n--;
  vector<int> ans;
  for (int i = 0; i <= n; ++i) {
    ans.push_back(c_mod2(n, i) * k);
  }

  for (int a : ans) {
    cout << a << " ";
  }
  cout << endl;
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
