#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  string s;
  cin >> s;
  int size = n * m;
  deque<int> d;
  for (int i = 0; i < m; ++i) {
    d.push_back(0);
  }
  vector<int> row(m);
  vector<int> ans(size);
  int col = 0;
  int last = -size;
  for (int i = 0; i < size; ++i) {
    int back = d.back();
    d.pop_back();
    if (s[i] == '1') {
      last = i;
      if (back == 0) {
        col++;
      }
      d.push_front(back + 1);
    } else {
      d.push_front(back);
    }
    if (i - last < m) {
      row[i % m]++;
    }

    ans[i] = row[i % m] + col;
  }

  for (int i = 0; i < size; ++i) {
    cout << ans[i] << " ";
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
