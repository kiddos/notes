#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> get_factors(int x) {
  vector<int> f;
  for (int d = 1; d * d <= x; ++d) {
    if (x % d == 0) {
      f.push_back(d);
      f.push_back(x / d);
    }
  }
  sort(f.begin(), f.end());
  f.resize(unique(f.begin(), f.end()) - f.begin());
  return f;
}

unordered_map<int, bool> memo;

bool dp(int n) {
  if (n == 1) {
    return false;
  }

  if (memo.count(n)) {
    return memo[n];
  }

  vector<int> factors = get_factors(n);
  for (int f : factors) {
    if (f % 2 == 1 && f > 1) {
      if (!dp(n / f)) {
        return memo[n] = true;
      }
    }
  }
  if (!dp(n-1)) {
    return memo[n] = true;
  }
  return memo[n] = false;
}

void solve() {
  int n = 0;
  cin >> n;

  bool win = dp(n);
  if (win) {
    cout << "Ashishgup" << endl;
  } else {
    cout << "FastestFinger" << endl;
  }
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
