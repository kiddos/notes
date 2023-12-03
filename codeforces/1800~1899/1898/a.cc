#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;
  int b = 0;
  for (char ch : s) {
    b += ch == 'B';
  }

  if (b == k) {
    cout << "0" << endl;
  } else {
    cout << "1" << endl;
    if (b > k) {
      for (int i = 0; i < n; ++i) {
        if (s[i] == 'B') {
          b--;
        }

        if (b == k) {
          cout << i+1 << " A" << endl;
          return;
        }
      }
    } else {
      for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') {
          b++;
        }

        if (b == k) {
          cout << i+1 << " B" << endl;
          return;
        }
      }
    }
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
