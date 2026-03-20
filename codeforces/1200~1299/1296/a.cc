#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int sum = accumulate(a.begin(), a.end(), 0);
  if (sum % 2 == 1) {
    cout << "YES" << endl;
    return;
  }
  vector<int> count(2);
  for (int i = 0; i < n; ++i) {
    count[a[i]%2]++;
  }

  if (count[0] && count[1]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
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
