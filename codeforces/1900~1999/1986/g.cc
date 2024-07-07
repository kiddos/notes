#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 500000;
vector<vector<int>> factors(MAX_N+1);

void precompute() {
  for (int i = 1; i <= MAX_N; ++i) {
    for (int j = i; j <= MAX_N; j += i) {
      factors[j].push_back(i);
    }
  }
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }
  
  vector<int> a(n+1), b(n+1);
  vector<vector<int>> a_indices(n+1), b_indices(n+1);
  for (int i = 1; i <= n; ++i) {
    int g = gcd(i, p[i]);
    b[i] = i / g;
    a[i] = p[i] / g;
    a_indices[a[i]].push_back(i);
    b_indices[b[i]].push_back(i);
  }

  i64 ans = 0;
  vector<int> counts(n+1);
  for (int bi = 1; bi <= n; ++bi) {
    for (int i : b_indices[bi]) {
      for (int f : factors[a[i]]) {
        counts[f]++;
      }
    }

    for (int aj = bi; aj <= n; aj += bi) {
      for (int j : a_indices[aj]) {
        ans += counts[b[j]];
      }
    }

    for (int i : b_indices[bi]) {
      for (int f : factors[a[i]]) {
        counts[f]--;
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (b[i] == 1) {
      ans--;
    }
  }

  ans /= 2;
  cout << ans << endl;
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
