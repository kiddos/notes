#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int inversion(vector<int>& a) {
  int n = a.size();
  int total = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      total += a[j] > a[i];
    }
  }
  return total;
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n+1);
  for (int i = 1; i <= k; ++i) {
    a[i] = i;
  }
  for (int i = k+1, j = k-1; i <= n; ++i, --j) {
    a[i] = j;
  }

  // for (int i = 1; i <= n; ++i) {
  //   cout << a[i] << " ";
  // }
  // cout << endl;

  vector<int> p(k+1);
  for (int i = 1; i <= k; ++i) {
    if (a[i] == a.back()) {
      for (int j = i, x = k; j <= k; ++j) {
        p[j] = x--;
      }
      break;
    } else {
      p[i] = i;
    }
  }
  for (int i = 1; i <= k; ++i) {
    cout << p[i] << " ";
  }
  cout << endl;

  // cout << "inversion(a)=" << inversion(a) << endl;
  // vector<int> b(n+1);
  // for (int i = 1; i <= n; ++i) {
  //   b[i] = p[a[i]];
  // }
  // cout << "inversion(b)=" << inversion(b) << endl;
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
