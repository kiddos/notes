#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  if (s == string(n, '?')) {
    for (int i = 0; i < n; ++i) {
      s[i] = i % 2 == 0 ? 'R' : 'B';
    }
    cout << s << endl;
    return;
  }

  queue<int> q;
  vector<bool> visited(n);
  for (int i = 0; i < n; ++i) {
    if (s[i] != '?') {
      q.push(i);
      visited[i] = true;
    }
  }

  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      int idx = q.front();
      q.pop();

      for (int j : {idx-1, idx+1}) {
        if (j < 0 || j >= n) continue;
        if (visited[j]) continue;
        if (s[j] != '?') continue;
        visited[j] = true;
        s[j] = s[idx] == 'R' ? 'B' : 'R';
        q.push(j);
      }
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
