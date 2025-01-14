#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> p(n+1);
  for (int i = 0; i < n; ++i) {
    int add = i % 2 == 0 ? 1 : -1;
    if (s[i] == '+') {
      p[i+1] += add;
    } else if (s[i] == '-') {
      p[i+1] -= add;
    }
  }
  for (int i = 1; i <= n; ++i) {
    p[i] += p[i-1];
  }
  for (int i = 0; i < q; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    int sum = p[r] - p[l-1];
    int len = r - l + 1;
    if (sum == 0) {
      cout << "0" << endl;
    } else if (len % 2 == 0) {
      cout << "2" << endl;
    } else if (len % 2 == 1) {
      cout << "1" << endl;
    }
  }
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
