#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 2000000;
vector<bool> is_prime(MAX_N+1, true);

void precompute() {
  for (int i = 2; i <= MAX_N; ++i) {
    if (is_prime[i]) {
      for (int j = i+i; j <= MAX_N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int sum = accumulate(a.begin(), a.end(), 0);
  if (!is_prime[sum]) {
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
      cout << i+1 << " ";
    }
    cout << endl;
  } else {
    for (int i = 0; i < n; ++i) {
      int s = sum - a[i];
      if (!is_prime[s]) {
        cout << n-1 << endl;
        for (int j = 0; j < n; ++j) if (j != i) {
          cout << j+1 << " ";
        }
        cout << endl;
        return;
      }
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
