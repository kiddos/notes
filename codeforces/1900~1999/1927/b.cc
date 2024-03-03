#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  map<int, deque<char>> chars;
  for (char ch = 'a'; ch <= 'z'; ++ch) {
    chars[0].push_back(ch);
  }

  string ans;
  for (int i = 0; i < n; ++i) {
    char c = chars[a[i]].front();
    chars[a[i]].pop_front();
    chars[a[i]+1].push_back(c);
    ans.push_back(c);
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
