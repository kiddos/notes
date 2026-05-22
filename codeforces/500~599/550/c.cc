#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool is_subseq(const string& s, const string& t) {
  int n = s.length(), m = t.length();
  for (int i = 0, j = 0; i < n; ++i) {
    if (s[i] == t[j]) {
      j++;
    }
    if (j == m) {
      return true;
    }
  }
  return false;
}

void solve() {
  string s;
  cin >> s;
  vector<string> possible;
  for (int x = 0; x < 1000; x += 8) {
    possible.push_back(to_string(x));
  }

  for (string& t : possible) {
    if (is_subseq(s, t)) {
      cout << "YES" << endl;
      cout << t << endl;
      return;
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
