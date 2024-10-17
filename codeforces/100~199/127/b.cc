#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> count(101);
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }

  int pairs = 0;
  for (int i = 1; i <= 100; ++i) {
    pairs += count[i] / 2;
  }
  int ans = pairs / 2;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
