#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool divisable(const string& s, int t) {
  vector<int> digits;
  for (char ch : s) {
    digits.push_back(ch - '0');
  }
  int n = s.length();
  for (int i = 0; i < n-1; ++i) {
    digits[i] %= t;
    digits[i+1] += digits[i] * 10;
  }
  return digits.back() % t == 0;
}

void solve() {
  int n = 0, t = 0;
  cin >> n >> t;
  string s(n, '0');
  s[0] = '1';
  while (!divisable(s, t) && s.back() < '9') {
    s.back()++;
  }
  if (divisable(s, t)) {
    cout << s << endl;
  } else {
    cout << "-1" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
