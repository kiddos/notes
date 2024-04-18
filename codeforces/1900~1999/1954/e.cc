#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  int max_a = *max_element(a.begin(), a.end());
  vector<i64> c(max_a + 1);
  for (int i = 1; i <= n; ++i) {
    if (i == 1 || a[i] > a[i-1]) {
      c[a[i]]++;
    }
    if (i+1 <= n && a[i] < a[i+1]) {
      c[a[i]]--;
    }
  }

  for (int i = 2; i <= max_a; ++i) {
    c[i] += c[i-1];
  }
  vector<i64> ans(max_a+1);
  for (int k = 1; k <= max_a; ++k) {
    for (int x = 1, d = 1; x <= max_a; x += k, ++d) {
      ans[k] += d * (c[min(x+k-1, max_a)] - c[x-1]);
    }
  }

  for (int k = 1; k <= max_a; ++k) {
    cout << ans[k] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
