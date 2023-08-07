#include <bits/stdc++.h>

using namespace std;

void solve() {
  int x = 0;
  cin >> x;
  vector<int> a(4);
  cin >> a[1] >> a[2] >> a[3];

  int key = x;
  int open = 0;
  while (key != 0) {
    open++;
    key = a[key];
  }

  if (open == 3) {
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
