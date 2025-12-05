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

  vector<int> even;
  for (int i = 0; i < n; ++i) {
    if (a[i] % 2 == 0) {
      even.push_back(a[i]);
    }
  }

  if (even.size() >= 2) {
    cout << even[0] << " " << even[1] << endl;
    return;
  }

  for (int i = 0; i < n; ++i) {
    if (a[i] % 2 == 1) {
      for (int j = i+1; j < n; ++j) {
        int mod = a[j] % a[i];
        if (mod % 2 == 0) {
          cout << a[i] << " " << a[j] << endl;
          return;
        }
      }
    }
  }
  cout << "-1" << endl;
  return;
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
