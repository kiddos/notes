#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 100001
// 111110
// 000001
// 111110

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<int> ops(n);
  for (int i = 0; i < n; ++i) {
    int c = s[i] - '0';
    if (c == k % 2) {
      ops[i] = 1;
    }
  }
  int total = accumulate(ops.begin(), ops.end(), 0);

  if (total < k) {
    int left = k - total;
    if (left % 2 == 0) {
      cout << string(n, '1') << endl;;
    } else {
      cout << string(n-1, '1') << '0' << endl;;
    }
    ops.back() += left;
  } else if (total == k) {
    cout << string(n, '1') << endl;;
  } else {
    string ans(n, '0');
    int x = k;
    ops = vector<int>(n);
    for (int i = 0; i < n; ++i) {
      int c = s[i] - '0';
      if (x > 0) {
        if (c == k % 2) {
          ops[i] = 1;
          ans[i] = '1';
          x--;
        } else {
          ans[i] = '1';
        }
      } else {
        if (k % 2 == 1) {
          ans[i] = s[i] == '1' ? '0' : '1';
        } else {
          ans[i] = s[i];
        }
      }
    }
    cout << ans << endl;
  }

  for (int i = 0; i < n; ++i) {
    cout << ops[i] << " ";
  }
  cout << endl;
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
