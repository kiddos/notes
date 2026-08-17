#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_DIGIT = 7;

string encode(int x) {
  vector<int> digits(MAX_DIGIT);
  for (int d = 0; d < MAX_DIGIT; ++d) {
    digits[d] = x % 26;
    x /= 26;
  }
  string s;
  for (int d = 0; d < MAX_DIGIT; ++d) {
    s.push_back(digits[d] + 'a');
  }
  return s;
}

int decode(string& s, int idx) {
  vector<int> digits(MAX_DIGIT);
  for (int i = 0; i < MAX_DIGIT; ++i) {
    digits[i] = s[i+idx]-'a';
  }
  int x = 0;
  for (int d = MAX_DIGIT-1; d >= 0; --d) {
    x = x * 26 + digits[d];
  }
  return x;
}

void first() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  string ans;
  for (int i = 0; i < n; ++i) {
    string digits = encode(a[i]);
    ans += digits;
  }
  cout << ans << endl;
}

void second() {
  string s;
  cin >> s;
  int m = s.length();
  int n = s.length() / MAX_DIGIT;
  vector<int> a(n);
  for (int i = 0, k = 0; i < m; i += MAX_DIGIT, ++k) {
    a[k] = decode(s, i);
  }

  cout << n << endl;
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void solve() {
  string s;
  cin >> s;
  if (s == "first") {
    first();
  } else if (s == "second") {
    second();
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
