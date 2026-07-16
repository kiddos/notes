#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void increment(string& s) {
  reverse(s.begin(), s.end());
  int c = 1;
  int n = s.length();
  for (int i = 0; i < n; ++i) {
    int d = s[i]-'0';
    d += c;
    s[i] = (d % 10) + '0';
    c = d / 10;
  }
  if (c) {
    s.push_back('1');
  }
  reverse(s.begin(), s.end());
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string a;
  cin >> a;

  string prefix = a.substr(0, k);
  string b1 = prefix;
  for (int i = k; i < n; ++i) {
    b1.push_back(a[i%k]);
  }
  if (b1 >= a) {
    cout << b1.length() << endl;
    cout << b1 << endl;
    return;
  }

  string b2 = prefix;
  increment(b2);

  for (int i = k; i < n; ++i) {
    b2.push_back(b2[i%k]);
  }
  cout << b2.length() << endl;
  cout << b2 << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
