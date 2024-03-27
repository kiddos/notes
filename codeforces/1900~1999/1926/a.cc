#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;    
  int a = 0, b = 0;
  for (int i = 0; i < (int)s.length(); ++i) {
    a += s[i] == 'A';
    b += s[i] == 'B';
  }
  if (a > b) {
    cout << "A" << endl;
  } else {
    cout << "B" << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}