#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  vector<int> t_index, m_index;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'T') {
      t_index.push_back(i);
    } else if (s[i] == 'M') {
      m_index.push_back(i);
    }
  }

  if (t_index.size() != m_index.size() * 2) {
    cout << "NO" << endl;
    return;
  }

  int m = m_index.size();
  for (int i = 0; i < m; ++i) {
    int i1 = t_index[i], i3 = t_index[i + m];
    int i2 = m_index[i];
    if (i1 > i2 || i2 > i3) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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
