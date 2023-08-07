#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  string s;
  cin >> s;

  int n = s.length();
  int open = 0, close = 0;
  vector<int> unknown;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      open++;
    } else if (s[i] == ')') {
      close++;
    } else {
      unknown.push_back(i);
    }
  }

  int missing_open = n / 2 - open;
  int missing_close = n / 2 - close;
  for (int i = 0; i < unknown.size(); ++i) {
    if (i < missing_open) {
      s[unknown[i]] = '(';
    } else {
      s[unknown[i]] = ')';
    }
  }

  auto is_rbs = [&](const string& t) -> bool {
    int balance = 0;
    for (char ch : t) {
      if (ch == '(') balance++;
      else if (ch == ')') balance--;
      if (balance  < 0) return false;
    }
    return balance == 0;
  };

  bool only_way = true;
  if (missing_open > 0 && missing_close > 0) {
    swap(s[unknown[missing_open-1]], s[unknown[missing_open]]);

    if (is_rbs(s)) {
      only_way = false;
    }
  }

  if (only_way) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
