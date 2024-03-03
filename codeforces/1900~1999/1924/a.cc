#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0, m = 0;
  cin >> n >> k >> m;
  string s;
  cin >> s;

  auto completed = [&](vector<int>& chars) -> bool {
    for (int& c : chars) if (c == 0) {
      return false;
    }
    return true;
  };

  int complete_set = 0;
  vector<int> chars(k);
  string e;
  for (int i = 0; i < m; ++i) {
    int c = s[i] - 'a';
    chars[c]++;
    if (completed(chars)) {
      e.push_back(s[i]);
      fill(chars.begin(), chars.end(), 0);
      complete_set++;
    }
  }

  if (complete_set >= n) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
    int c = find(chars.begin(), chars.end(), 0) - chars.begin();
    e.push_back(c + 'a');
    e += string(n - e.length(), 'a');
    cout << e << endl;
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
