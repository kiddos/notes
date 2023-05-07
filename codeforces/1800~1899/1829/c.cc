#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;

  constexpr int MAX_VAL = 500000;
  vector<int> first = {MAX_VAL}, second = {MAX_VAL}, both = {MAX_VAL};
  for (int i = 0; i < n; ++i) {
    int m = 0;
    cin >> m;
    string s;
    cin >> s;
    if (s == "11") {
      both.push_back(m);
    } else if (s == "10") {
      first.push_back(m);
    } else if (s == "01") {
      second.push_back(m);
    }
  }

  int ans = *min_element(both.begin(), both.end());
  ans = min(ans, *min_element(first.begin(), first.end()) + *min_element(second.begin(), second.end()));
  if (ans >= MAX_VAL) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
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
