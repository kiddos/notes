#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  if (k >= 1) {
    int x = a[k-1];
    int count = 0;
    for (int i = 0; i < n; ++i) {
      count += a[i] <= x;
    }
    if (count != k) {
      cout << "-1" << endl;
    } else {
      cout << x << endl;
    }
  } else {
    int min_val = *min_element(a.begin(), a.end());
    int x = min_val-1;
    if (x >= 1 && x <= 1e9) {
      cout << x << endl;
    } else {
      cout << "-1" << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
