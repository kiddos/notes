#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int type2 = 0;
  for (int i = 0; i < n; ++i) {
    type2 += s[i] == '2';
  }
  if (type2 > 0 && type2 < 3) {
    cout << "NO" << endl;
    return;
  }


  vector<string> ans(n, string(n, ' '));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) {
        ans[i][j] = 'X';
      } else {
        if (s[i] == '1' || s[j] == '1') {
          ans[i][j] = '=';
        } else {
          ans[i][j] = '-';
        }
      }
    }
  }

  int last = s.find_last_of('2');
  for (int i = 0; i < n; ++i) {
    if (s[i] == '2')  {
      ans[last][i] = '+';
      last = i;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (ans[i][j] == '-' && ans[j][i] == '-') {
        ans[i][j] = '+';
      }
    }
  }

  cout << "YES" << endl;
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << endl;
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
