#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 00001111 max = 6 = n-2
// 01010101 min = 0

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  int max_same = n-2;
  if (k > max_same) {
    cout << "-1" << endl;
    return;
  }
  int zeros = (n+1) / 2;
  int ones = n / 2;
  int remove = max_same - k;
  int zeros2 = 0, ones2 = 0;
  while (remove >= 2) {
    zeros--;
    ones--;
    zeros2++;
    ones2++;
    remove -= 2;
  }
  if (remove) {
    zeros--;
    zeros2++;
  }
  string ans;
  ans += string(zeros, '0');
  ans += string(ones, '1');

  while (zeros2 && ones2) {
    ans.push_back('0');
    ans.push_back('1');
    zeros2--;
    ones2--;
  }
  if (zeros2) {
    ans.push_back('0');
  }

  cout << ans << endl;
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
