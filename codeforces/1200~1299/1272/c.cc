#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<char> c(k);
  for (int i = 0; i < k; ++i) {
    cin >> c[i];
  }

  vector<bool> can_use(26);
  for (int i = 0; i < k; ++i) {
    can_use[c[i]-'a'] = true;
  }

  i64 ans = 0;
  int i = 0;
  while (i < n) {
    if (!can_use[s[i]-'a']) {
      i++;
    } else {
      int j = i;
      ans++;
      while (j+1 < n && can_use[s[j+1]-'a']) {
        j++;
        ans += j-i+1;
      }
      i = j + 1;
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
