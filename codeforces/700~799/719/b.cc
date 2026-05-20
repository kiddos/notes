#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int make_same(const string& s, const string& t) {
  int n = s.length();
  vector<int> incorrect(2);
  for (int i = 0; i < n; ++i) {
    if (s[i] != t[i]) {
      if (s[i] == 'r') {
        incorrect[0]++;
      } else if (s[i] == 'b') {
        incorrect[1]++;
      }
    }
  }
  int ans = 0;
  while (incorrect[0] > 0 && incorrect[1] > 0) {
    ans++;
    incorrect[0]--;
    incorrect[1]--;
  }
  ans += max(incorrect[0], incorrect[1]);
  return ans;
}

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  string s1, s2;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      s1.push_back('r');
      s2.push_back('b');
    } else {
      s1.push_back('b');
      s2.push_back('r');
    }
  }

  int ans = min(make_same(s, s1), make_same(s, s2));
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
