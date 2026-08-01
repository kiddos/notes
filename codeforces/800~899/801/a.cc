#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int count_vk(const string& s) {
  int n = s.length();
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    if (s[i] == 'K' && s[i-1] == 'V') {
      ans++;
    }
  }
  return ans;
}

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  int ans = count_vk(s);
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'V') {
      s[i] = 'K';
      ans = max(ans, count_vk(s));
      s[i] = 'V';
    } else {
      s[i] = 'V';
      ans = max(ans, count_vk(s));
      s[i] = 'K';
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
