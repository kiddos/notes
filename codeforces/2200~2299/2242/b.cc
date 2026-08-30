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

  vector<int> d1(n), d2(n);
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      d1[i]++;
    } else {
      d1[i]--;
    }
    if (a[i] == 1 || a[i] == 2) {
      d2[i]++;
    } else {
      d2[i]--;
    }
  }

  for (int i = 1; i < n; ++i) {
    d1[i] += d1[i-1];
    d2[i] += d2[i-1];
  }

  // for (int i = 0; i < n; ++i) {
  //   cout << d1[i] << " ";
  // }
  // cout << endl;
  // for (int i = 0; i < n; ++i) {
  //   cout << d2[i] << " ";
  // }
  // cout << endl;

  int idx1 = -1, idx2 = -1;
  for (int i = 0; i < n; ++i) {
    if (d1[i] == 0) {
      if (idx1 < 0) {
        idx1 = i;
      }
    }
    if (d1[i] == 1) {
      if (idx2 < 0) {
        idx2 = i;
      }
    }
  }

  if (idx1 >= 0) {
    for (int i = idx1+1; i < n-1; ++i) {
      if (d2[i] >= d2[idx1]) {
        cout << "YES" << endl;
        return;
      }
    }
  }

  if (idx2 >= 0) {
    for (int i = idx2+1; i < n-1; ++i) {
      if (d2[i] >= d2[idx2]) {
        cout << "YES" << endl;
        return;
      }
    }
  }

  cout << "NO" << endl;
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
