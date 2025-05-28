#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool check(string& s) {
  int n = s.length();
  int b = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      b++;
    } else {
      b--;
    }
    if (b < 0) {
      return false;
    }
  }
  return b == 0;
}

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  vector<int> same, not_same;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      same.push_back(i);
    } else {
      not_same.push_back(i);
    }
  }
  if (same.size() % 2 == 1) {
    cout << "NO" << endl;
    return;
  }

  int size = same.size();
  string a(n, ' '), b(n, ' ');
  for (int i = 0; i < size / 2; ++i) {
    a[same[i]] = '(';
    b[same[i]] = '(';
  }
  for (int i = size/2 ; i < size; ++i) {
    a[same[i]] = ')';
    b[same[i]] = ')';
  }
  size = not_same.size();
  for (int i = 0; i < size; i += 2) {
    a[not_same[i]] = '(';
    a[not_same[i+1]] = ')';
    b[not_same[i]] = ')';
    b[not_same[i+1]] = '(';
  }

  if (check(a) && check(b)) {
    cout << "YES" << endl;
    cout << a << endl;
    cout << b << endl;
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
