#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool is_valid(const string& s, int a, int b, int c) {
  int balance = 0;
  for (char ch : s) {
    if (ch == 'A') {
      balance += a;
    } else if (ch == 'B') {
      balance += b;
    } else if (ch == 'C') {
      balance += c;
    }
    if (balance < 0) {
      return false;
    }
  }
  return balance == 0;
}

void solve() {
  string s;
  cin >> s;
  if (is_valid(s, 1, 1, 1) ||
      is_valid(s, 1, -1, 1) ||
      is_valid(s, 1, 1, -1) ||
      is_valid(s, 1, -1, -1) ||
      is_valid(s, -1, 1, 1) ||
      is_valid(s, -1, 1, -1) ||
      is_valid(s, -1, -1, 1) ||
      is_valid(s, -1, -1, -1)) {
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
