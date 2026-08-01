#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, p = 0, q = 0;
  cin >> n >> p >> q;
  string s;
  cin >> s;

  auto split = [&](int ps) -> vector<string> {
    vector<string> ans;
    for (int i = 0; i < ps*p; i += p) {
      ans.push_back(s.substr(i, p));
    }
    for (int i = ps * p; i < n; i += q) {
      ans.push_back(s.substr(i, q));
    }
    return ans;
  };

  for (int i = 0; p*i <= n; ++i) {
    if ((n-i*p) % q == 0) {
      vector<string> ans = split(i);
      cout << ans.size() << endl;
      for (string& a : ans) {
        cout << a << endl;
      }
      return;
    }
  }
  cout << "-1" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
