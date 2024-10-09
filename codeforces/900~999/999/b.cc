#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 2; i <= n; ++i) {
    if (n % i == 0) {
      reverse(s.begin(), s.begin() + i);
    }
  }
  cout << s << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
