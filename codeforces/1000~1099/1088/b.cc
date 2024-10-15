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
  a.resize(unique(a.begin(), a.end()) - a.begin());
  int m = a.size();
  int size = min(m, k);
  for (int i = 0; i < size; ++i) {
    if (i == 0) {
      cout << a[i] << endl;
    } else {
      cout << a[i] - a[i-1] << endl;
    }
  }
  for (int i = size; i < k; ++i) {
    cout << "0" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
