#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }

  vector<int> contestants = a;
  sort(contestants.begin(), contestants.end());

  auto kevin = find(contestants.begin(), contestants.end(), a[0]);
  vector<int> c(m);
  for (int i = 0; i < m; ++i) {
    if (b[i] > a[0]) {
      auto it = lower_bound(kevin + 1, contestants.end(), b[i]);
      c[i] = contestants.end() - it;
    }
  }

  sort(c.begin(), c.end());
  auto sum_ranking = [&](int k) -> i64 {
    int num_contest = m / k;
    i64 ans = 0;
    for (int i = 0; i < num_contest; ++i) {
      ans += c[(i+1) * k -1] + 1;
    }
    return ans;
  };

  for (int k = 1; k <= m; ++k) {
    i64 sum = sum_ranking(k);
    cout << sum << " ";
  }
  cout << endl;
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
