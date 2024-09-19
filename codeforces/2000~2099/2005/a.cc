#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
  string ans;
  int size = n / 5;
  int left = n - size * 5;
  for (int i = 0; i < 5; ++i) {
    int s = size;
    if (left > 0) {
      left--;
      s++;
    }
    ans += string(s, vowels[i]);
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
