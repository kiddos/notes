#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  string s;
  cin >> s;
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    if  (s[i] == '1') {
      q.push(i);
    }
  }

  while (!q.empty() && m-- > 0) {
    vector<int> change;
    for (int size = q.size(); size > 0; --size) {
      int idx = q.front();
      q.pop();

      if (idx+1 < n && s[idx+1] == '0') {
        if (idx+2 >= n || s[idx+2] == '0') {
          q.push(idx+1);
          change.push_back(idx+1);
        }
      }
      if (idx > 0 && s[idx-1] == '0') {
        if (idx-2 < 0 || s[idx-2] == '0') {
          q.push(idx-1);
          change.push_back(idx-1);
        }
      }
    }
    for (int idx : change) {
      s[idx] = '1';
    }
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
