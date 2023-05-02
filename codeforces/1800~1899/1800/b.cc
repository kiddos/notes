#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<int> count(256);
  int ans = 0;
  for (char ch : s) {
    char ch2 = isupper(ch) ? tolower(ch) : toupper(ch);
    if (count[ch2]) {
      ans++;
      count[ch2]--;
    } else {
      count[ch]++;
    }
  }

  for (int i = 0; i < 256 && k > 0; ++i) {
    int most_burl = count[i] / 2;
    int can_add = min(most_burl, k);
    ans += can_add;
    k -= can_add;
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
