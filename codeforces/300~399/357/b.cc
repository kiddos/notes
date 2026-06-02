#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> colors(n+1);
  for (int i = 0; i < m; ++i) {
    vector<int> dancer(3);
    for (int j = 0; j < 3; ++j) {
      cin >> dancer[j];
    }
    vector<int> assigned(4);
    for (int j = 0; j < 3; ++j) {
      if (colors[dancer[j]]) {
        assigned[colors[dancer[j]]]++;
      }
    }
    for (int j = 0, c = 1; j < 3; ++j) {
      while (c <= 3 && assigned[c]) {
        c++;
      }
      if (!colors[dancer[j]]) {
        colors[dancer[j]] = c;
        c++;
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << colors[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
