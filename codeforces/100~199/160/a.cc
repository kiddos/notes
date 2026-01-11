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
  sort(a.rbegin(), a.rend());
  int sum = accumulate(a.begin(), a.end(), 0);
  int take = 0;
  for (int i = 0; i < n; ++i) {
    take += a[i];
    if (take > sum - take) {
      cout << i+1 << endl;
      return;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
