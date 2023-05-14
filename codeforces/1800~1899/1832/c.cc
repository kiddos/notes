#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  if (n == 1) {
    cout << "1" << endl;
    return;
  }

  int ans = 1;
  int i = 0;
  while (i < n) {
    int j = i;
    while (j < n && a[j] == a[i]) {
      j++;
    }

    if (j < n && a[j] > a[i]) {
      int k = j;
      while (k+1 < n && a[k+1] >= a[k]) {
        k++;
      }
      ans++;
      i = k;
    } else if (j < n && a[j] < a[i]) {
      int k = j;
      while (k+1 < n && a[k+1] <= a[k]) {
        k++;
      }
      ans++;
      i = k;
    } else {
      i = j+1;
    }
  }

  cout << ans << endl;
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
