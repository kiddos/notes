#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int dot = s.find('.');
  if (s[dot-1] == '9') {
    cout << "GOTO Vasilisa." << endl;
    return;
  }
  string integer = s.substr(0, dot);
  if (s[dot+1] >= '5') {
    int c = 1;
    int n = integer.length();
    for (int i = n-1; i >= 0; --i) {
      int d0 = integer[i]-'0';
      int d = d0+c;
      integer[i] = (d%10)+'0';
      c = d / 10;
    }
    if (c) {
      integer = "1" + integer;
    }
  }
  cout << integer << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
