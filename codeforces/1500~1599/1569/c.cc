#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 200000;
constexpr int MOD = 998244353;

vector<i64> f(MAX_N+1, 1);

void precompute() {
  for (int i = 2; i <= MAX_N; ++i) {
    f[i] = f[i-1] * i;
    f[i] %= MOD;
  }
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  map<int, int> counts;
  for (int i = 0; i < n; ++i) {
    counts[a[i]]++;
  }

  if (counts.size() == 1) {
    cout << f[n] << endl;
  } else {
    int largest = counts.rbegin()->first;
    int second_largest = next(counts.rbegin())->first;
    if (second_largest != largest-1 && counts[largest] == 1) {
      cout << "0" << endl;
      return;
    }
    if (counts[largest] == 1) {
      i64 c2 = counts[second_largest];
      i64 ans = f[c2] * c2;
      ans %= MOD;
      for (int i = c2+2; i <= n; ++i) {
        ans *= i;
        ans %= MOD;
      }
      cout << ans << endl;
    } else {
      cout << f[n] << endl;
    }
  }
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
