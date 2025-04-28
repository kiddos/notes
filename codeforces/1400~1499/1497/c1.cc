#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a;
  if (n % 2 == 1) {
    a = {1, n/2, n/2};
  } else {
    if (n % 4 == 0) {
      a = {n/2, n/4, n/4};
    } else {
      a = {2, (n-2)/2, (n-2)/2};
    }
  }

  for (int i = 0; i < 3; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
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
