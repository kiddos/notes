#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string n1, n2;
  cin >> n1 >> n2;
  int n = n1.length();
  string ans;
  for (int i = 0; i < n; ++i) {
    int x = n1[i] - '0', y = n2[i] - '0';
    ans.push_back((x ^ y) + '0');
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
