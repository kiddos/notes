#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int k = 0;
  cin >> k;
  vector<int> a(12);
  for (int i = 0; i < 12; ++i) {
    cin >> a[i];
  }
  if (k == 0) {
    cout << "0" << endl;
    return;
  }

  sort(a.rbegin(), a.rend());
  int total = 0;
  for (int i = 0; i < 12; ++i) {
    total += a[i];
    if (total >= k) {
      cout << i+1 << endl;
      return;
    }
  }
  cout << "-1" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
