#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 s = 0;
  i64 x = 0;
  cin >> n >> s >> x;
  vector<i64> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  vector<i64> p = a;
  for (int i = 1; i <= n; ++i) {
    p[i] += p[i-1];
  }

  map<i64, int> prefix_count;
  i64 ans = 0;
  for (int i = 1, j = 1; i <= n; ++i) {
    if (a[i] > x) {
      prefix_count.clear();
      j = i+1;
    } else if (a[i] == x) {
      while (j <= i) {
        prefix_count[p[j-1]]++;
        j++;
      }
    }

    ans += prefix_count[p[i] - s];
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
