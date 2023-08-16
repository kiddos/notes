#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool has_integer_solution(i64 x, i64 y, i64& ans) {
  if (x * x < 4 * y) return false;
  i64 z = x * x - 4 * y;
  i64 s = sqrt(z);
  if (s * s != z) return false;

  ans = x + s;
  if (ans % 2 == 1) return false;
  ans /= 2;
  return true;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  map<i64,i64> freq;
  for (i64 val : a) {
    freq[val]++;
  }
  
  int q = 0;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    i64 x = 0, y = 0;
    cin >> x >> y;

    i64 ans = 0;
    i64 ai = 0;
    if (has_integer_solution(x, y, ai)) {
      i64 aj = x - ai;
      if (freq.count(ai) && freq.count(aj)) {
        if (ai == aj) {
          ans = freq[ai] * (freq[aj] - 1) / 2;
        } else {
          ans = freq[ai] * freq[aj];
        }
      }
    }
    cout << ans << " ";
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
