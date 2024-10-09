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
  int missing = 0;
  for (int i = 0; i < n; ++i) {
    missing += 5 - a[i];
  }
  // missing needs to be <= n/2
  int target = n / 2;
  if (missing <= target) {
    cout << "0" << endl;
    return;
  }

  sort(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    missing -= 5 - a[i];
    if (missing <= target) {
      cout << i+1 << endl;
      return;
    }
  }
  cout << n << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
