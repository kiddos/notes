#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s, c;
  cin >> s >> c;
  int n = s.length();

  vector<vector<int>> indices(26);
  for (int i = 0; i < n; ++i) {
    int ch = s[i] - 'A';
    indices[ch].push_back(i);
  }

  for (int i = 0; i < n; ++i) {
    bool found = false;
    int ch = s[i] - 'A';
    for (int c2 = 0; c2 < ch; ++c2) {
      if (!indices[c2].empty() && indices[c2].back() > i) {
        int idx = indices[c2].back();
        swap(s[i], s[idx]);
        found = true;
        break;
      }
    }
    if (found) {
      break;
    }
  }

  if (s < c) {
    cout << s << endl;
  } else {
    cout << "---" << endl;
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
