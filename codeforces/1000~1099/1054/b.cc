#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  int mex = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] > mex) {
      cout << i << endl;
      return;
    }

    if (a[i] == mex) {
      mex++;
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
