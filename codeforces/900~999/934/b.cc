#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int k = 0;
  cin >> k;
  int max_k = 18 * 2;
  if (k > max_k) {
    cout << "-1" << endl;
    return;
  }
  string ans;
  while (k >= 2) {
    ans.push_back('8');
    k -= 2;
  }
  if (k > 0) {
    ans.push_back('6');
    k--;
  }
  if (ans.empty()) {
    ans.push_back('1');
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
