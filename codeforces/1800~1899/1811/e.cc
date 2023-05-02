#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  ll k = 0;
  cin >> k;

  vector<int> digits;
  while (k > 0) {
    digits.push_back(k % 9);
    k /= 9;
  }
  
  reverse(digits.begin(), digits.end());

  string ans;
  for (int d : digits) {
    ans.push_back(d < 4 ? d + '0' : d + '1');
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
