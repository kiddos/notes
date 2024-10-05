#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int sum1 = 0, sum2 = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] != '4' && s[i] != '7') {
      cout << "NO" << endl;
      return;
    }
    if (i < n / 2) {
      sum1 += s[i] - '0';
    } else {
      sum2 += s[i] - '0';
    }
  }
  if (sum1 != sum2) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
