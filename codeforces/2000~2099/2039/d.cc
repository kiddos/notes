#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int count_prime_factors(int x) {
  int ans = 0;
  for (int d = 2; d*d <= x; ++d) {
    while (x % d == 0) {
      x /= d;
      ans++;
    }
  }
  if (x > 1) {
    ans++;
  }
  return ans;
}

constexpr int MAX_N = 100000;
vector<int> p(MAX_N+1);
void precompute() {
  for (int i = 2; i <= MAX_N; ++i) {
    p[i] = count_prime_factors(i);
  }
}

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> s(m+1);
  for (int i = 1; i <= m; ++i) {
    cin >> s[i];
  }

  vector<int> ans;
  for (int i = 1; i <= n; ++i) {
    if (m - p[i] <= 0) {
      cout << "-1" << endl;
      return;
    }

    ans.push_back(s[m-p[i]]);
  }

  for (int i = 0; i < (int)ans.size(); ++i) {
    cout << ans[i] << " ";
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
