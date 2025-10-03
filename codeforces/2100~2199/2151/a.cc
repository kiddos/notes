#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }

  int max_val = *max_element(a.begin(), a.end());
  bool increasing = true;
  for (int j = 1; j < m; ++j) {
    if (a[j-1] +1 != a[j]) {
      increasing = false;
      break;
    }
  }
  if (increasing) {
    cout << n-max_val+1 << endl;
  } else {
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
