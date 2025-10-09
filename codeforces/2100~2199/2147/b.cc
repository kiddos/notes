#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n * 2);
  a[0] = a[n] = n;

  for (int l = n+1, r = n*2-2, x = n-3; l < r && x > 1; ++l, --r, x -= 2) {
    a[l] = a[r] = x;
  }
  // a[n-1] = a[n-1+n-1] = n-1;
  for (int l = 1, r = n-1, x = n-2; l < r && x > 1; ++l, --r, x -= 2) {
    a[l] = a[r] = x;
  }
  if (n-1 > 1) {
    int mid = (n+1) / 2;
    a[mid] = a[mid+n-1] = n-1;
  }

  int size = n*2;
  for (int i = 0; i < size; ++i) {
    if (!a[i]) {
      a[i] = 1;
    }
  }

  for (int i = 0; i < size; ++i) {
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
