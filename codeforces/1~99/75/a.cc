#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 remove_zero(i64 x) {
  string s = to_string(x);
  string s2;
  for (char ch : s) {
    if (ch != '0') {
      s2.push_back(ch);
    }
  }
  return stoll(s2);
}

void solve() {
  i64 a = 0, b = 0;
  cin >> a >> b;
  i64 c = a + b;
  i64 a2 = remove_zero(a);
  i64 b2 = remove_zero(b);
  i64 c2 = remove_zero(c);
  if (c2 == a2 + b2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
