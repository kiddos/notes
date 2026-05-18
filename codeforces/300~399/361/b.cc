#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  if (n == k) {
    cout << "-1" << endl;
    return;
  }

  vector<int> a(n+1);
  iota(a.begin(), a.end(), 0);
  for (int i = n-k; i >= 2; --i) {
    a[i] = i-1;
  }
  a[1] = n-k;

  for (int i = 1; i <= n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
