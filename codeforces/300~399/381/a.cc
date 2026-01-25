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
  int l = 0, r = n-1;
  int sereja = 0, dima = 0;
  for (int i = 0; i < n; ++i) {
    int val = 0;
    if (a[l] > a[r]) {
      val = a[l++];
    } else {
      val = a[r--];
    }
    if (i% 2 == 0) {
      sereja += val;
    } else {
      dima += val;
    }
  }
  cout << sereja << " " << dima << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
