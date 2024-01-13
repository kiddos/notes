#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  i64 score = 0;
  for (int i = 1; i < n; ++i) {
    score += abs(a[i] - a[i-1]);
  }

  vector<int> insert_x(n+1);
  insert_x[0] = abs(a[0] - x);
  for (int i = 1; i < n; ++i) {
    insert_x[i] = -abs(a[i-1] - a[i]) + abs(a[i-1]-x) + abs(a[i] - x);
  }
  insert_x[n] = abs(a.back() - x);

  vector<int> insert_one(n+1);
  insert_one[0] = abs(a[0] - 1);
  for (int i = 1; i < n; ++i) {
    insert_one[i] = -abs(a[i-1] - a[i]) + abs(a[i-1]-1) + abs(a[i] - 1);
  }
  insert_one[n] = abs(a.back() - 1);

  vector<int> insert_both(n+1);
  insert_both[0] = min(abs(a[0] - 1), abs(a[0] - x)) + x - 1;
  for (int i = 1; i < n; ++i) {
    insert_both[i] = -abs(a[i-1] - a[i]) + min(abs(a[i-1] - x) + abs(a[i] - 1), abs(a[i-1] - 1) + abs(a[i] - x)) + x - 1;
  }
  insert_both[n] = min(abs(a.back() - 1), abs(a.back() - x)) + x - 1;

  vector<int> p_one = insert_one;
  vector<int> p_x = insert_x;
  for (int i = 1; i <= n; ++i) {
    p_one[i] = min(p_one[i], p_one[i-1]);
    p_x[i] = min(p_x[i], p_x[i-1]);
  }

  constexpr int INF = numeric_limits<int>::max();
  i64 ans = numeric_limits<i64>::max();
  for (int i = n, s1 = INF, s2 = INF; i >= 1; --i) {
    s1 = min(s1, insert_x[i]);
    s2 = min(s2, insert_one[i]);
    i64 s = score + min(s1 + p_one[i-1], s2 + p_x[i-1]);
    ans = min(ans, s);
  }

  for (int i = 0; i <= n; ++i) {
    ans = min(ans, score + insert_both[i]);
  }

  cout << ans << endl;
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
