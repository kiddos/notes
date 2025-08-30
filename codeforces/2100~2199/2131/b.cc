#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  if (n == 2) {
    cout << "-1 2" << endl;
    return;
  }

  if (n == 3) {
    cout << "-1 3 -1" << endl;
    return;
  }

  vector<int> a;
  if (n % 2 == 0) {
    for (int i = 0; i < n-2; ++i) {
      if (i % 2 == 0) {
        a.push_back(-1);
      } else {
        a.push_back(3);
      }
    }
    a.push_back(-1);
    a.push_back(2);
  } else {
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0) {
        a.push_back(-1);
      } else {
        a.push_back(3);
      }
    }
  }

  for (int i = 0; i < n; ++i) {
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
