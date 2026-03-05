#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  for (int i = 0; i < n; ++i) {
    int t = n-i;
    if (p[i] != t) {
      int index = i;
      for (int j = i+1; j < n; ++j) {
        if (p[j] == t) {
          index = j;
        }
      }
      reverse(p.begin() + i, p.begin() + index + 1);
      break;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << p[i] << " ";
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
