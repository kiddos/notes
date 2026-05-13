#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string line;
  vector<string> logs;
  while (getline(cin, line)) {
    if (line.empty()) {
      break;
    }
    logs.push_back(line);
  }

  int ans = 0;
  set<string> users;
  for (string l : logs) {
    if (l[0] == '+') {
      string user = l.substr(1);
      users.insert(user);
    } else if (l[0] == '-') {
      string user = l.substr(1);
      users.erase(user);
    } else {
      auto idx = l.find(':');
      string message = l.substr(idx+1);
      int len = message.length();
      int total = len * users.size();
      ans += total;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
