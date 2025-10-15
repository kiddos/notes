#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  vector<string> ans;
  sort(s.begin(), s.end());
  do {
    ans.push_back(s);
  } while (next_permutation(s.begin(), s.end()));

  cout << ans.size() << endl;
  for (string& a : ans) {
    cout << a << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
