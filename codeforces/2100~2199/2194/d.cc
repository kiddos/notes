#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  int total_one = 0;
  vector<int> row_ones(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      total_one += a[i][j];
      row_ones[i] += a[i][j];
    }
  }

  if (total_one == 0) {
    cout << "0" << endl;
    cout << string(n, 'D') + string(m, 'R') << endl;
    return;
  }

  i64 top_right = total_one / 2;
  i64 bot_left = total_one - top_right;
  i64 ans1 = top_right * bot_left;

  string ans2;
  int current = 0;
  for (int i = 0; i < n; ++i) {
    if (current + row_ones[i] <= top_right) {
      current += row_ones[i];
      ans2.push_back('D');
    } else {
      for (int j = m-1; j >= 0; --j) {
        if (current + a[i][j] <= top_right) {
          current += a[i][j];
        } else {
          // exclude this to bot_right
          ans2 += string(j+1, 'R');
          ans2.push_back('D');
          ans2 += string(m-j-1, 'R');
          ans2 += string(n-i-1, 'D');
          break;
        }
      }
      break;
    }
  }
  cout << ans1 << endl;
  cout << ans2 << endl;
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
