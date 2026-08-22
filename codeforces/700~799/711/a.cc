#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void answer(vector<string>& s) {
  cout << "YES" << endl;
  for (string& row : s) {
    cout << row << endl;
  }
}

void solve() {
  int n = 0;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j : {1, 4}) {
      if (s[i][j-1] == 'O' && s[i][j] == 'O') {
        s[i][j-1] = '+';
        s[i][j] = '+';
        answer(s);
        return;
      }
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
