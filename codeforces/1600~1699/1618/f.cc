#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 0100010
// 1010001
// 
// 0100010
// 1100010
// 100010

void solve() {
  i64 x = 0, y = 0;
  cin >> x >> y;

  auto to_binary = [&](i64 num) -> string {
    string s;
    while (num) {
      s.push_back(num % 2 + '0');
      num >>= 1;
    }
    reverse(s.begin(), s.end());
    return s;
  };

  string sx = to_binary(x), sy = to_binary(y);
  set<string> visited;
  queue<string> q;
  q.push(sx);
  visited.insert(sx);
  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      string s = q.front();
      q.pop();
      // cout << s << endl;

      if (s.length() > 64) {
        cout << "NO" << endl;
        return;
      }

      if (s == sy) {
        cout << "YES" << endl;
        return;
      }

      s.push_back('1');
      reverse(s.begin(), s.end());
      if (!visited.count(s)) {
        q.push(s);
        visited.insert(s);
      }
      reverse(s.begin(), s.end());
      s.pop_back();


      while (!s.empty() && s.back() == '0') {
        s.pop_back();
      }
      reverse(s.begin(), s.end());
      if (!visited.count(s)) {
        q.push(s);
        visited.insert(s);
      }
    }
  }

  cout << "NO" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
