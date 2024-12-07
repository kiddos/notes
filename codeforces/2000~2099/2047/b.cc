#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  vector<int> c(26);
  for (char ch : s) {
    c[ch-'a']++;
  }

  vector<pair<int,int>> p;
  for (int ch = 0; ch < 26; ++ch) {
    if (c[ch]) {
      p.push_back({c[ch], ch});
    }
  }
  sort(p.rbegin(), p.rend());
  if (p.size() > 1) {
    char ch1 = p[0].second + 'a';
    char ch2 = p.back().second + 'a';
    int i1 = s.find(ch1), i2 = s.find(ch2);
    s[i2] = s[i1];
  }
  cout << s << endl;
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
