#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int sum = 0;
  vector<int> mods(3);
  for (int i = 0; i < n; ++i) {
    sum += a[i];
    sum %= 3;
    mods[a[i] % 3]++;
  }
  if (sum == 0) {
    cout << "0" << endl;
  } else if (sum == 1) {
    if (mods[1]) {
      cout << "1" << endl;
    } else {
      cout << "2" << endl;
    }
  } else if (sum == 2) {
    cout << "1" << endl;
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
