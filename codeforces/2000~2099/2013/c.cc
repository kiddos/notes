#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool query(const string& s) {
  cout << "? " << s << endl;
  int ans = 0;
  cin >> ans;
  return ans;
}

void answer(const string& s) {
  cout << "! " << s << endl;
}

void solve() {
  int n = 0;
  cin >> n;

  string s;
  while ((int) s.length() < n) {
    if (query(s + "1")) {
      s.push_back('1');
    } else if (query(s + "0")) {
      s.push_back('0');
    } else {
      break;
    }
  }

  if ((int) s.length() == n) {
    answer(s);
    return;
  }

  while ((int) s.length() < n) {
    if (query("1" + s)) {
      s = "1" + s;
    } else {
      s = "0" + s;
    }
  }

  answer(s);
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
