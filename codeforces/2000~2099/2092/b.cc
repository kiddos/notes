#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string a, b;
  cin >> a >> b;

  int require1 = 0, require2 = 0;
  vector<int> c1(2), c2(2);
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      require1++;
      c1[a[i]-'0']++;
      c2[b[i]-'0']++;
    } else {
      require2++;
      c1[b[i]-'0']++;
      c2[a[i]-'0']++;
    }
  }

  if (c1[0] >= require1 && c2[0] >= require2) {
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
