#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s, t;
  cin >> s >> t;
  vector<int> c1(26);
  for (char ch : t) {
    c1[ch-'A']++;
  }
  vector<int> c2(26);
  for (char ch : s) {
    c2[ch-'A']++;
  }

  string ans;
  for (char ch : s) {
    if (c2[ch-'A'] == c1[ch-'A']) {
      ans.push_back(ch);
    } else {
      c2[ch-'A']--;
    }
  }

  if (ans == t) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
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
