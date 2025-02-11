#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

string solve(int n, int m, int k, char c1, char c2) {
  string ans;
  ans += string(k, c1);
  n -= k;
  while (n > 0 && m > 0) {
    ans.push_back(c2);
    ans.push_back(c1);
    n--;
    m--;
  }
  int balance = k;
  while (m > 0) {
    ans.push_back(c2);
    m--;
    balance--;
  }
  while (n > 0) {
    ans.push_back(c1);
    n--;
    balance++;
  }
  if (abs(balance) > k) {
    return "-1";
  }
  return ans;
}

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;

  if (k > max(n, m)) {
    cout << "-1" << endl;
    return;
  }

  if (n > m) {
    string ans = solve(n, m, k, '0', '1');
    cout << ans << endl;
  } else {
    string ans = solve(m, n, k, '1', '0');
    cout << ans << endl;
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
