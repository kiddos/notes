#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 200001;

vector<bool> is_prime(MAX_N+1, true);

void precompute() {
  is_prime[1] = false;
  for (int i = 2; i <= MAX_N; ++i) {
    for (int j = i+i; j <= MAX_N; j += i) {
      is_prime[j] = false;
    }
  }
}

void solve() {
  int n = 0;
  cin >> n;

  if (is_prime[n+1]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
