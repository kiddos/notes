#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<array<int,2>> rect;
  for (int i = 0; i < n; ++i) {
    int w = 0, h = 0;
    cin >> w >> h;
    rect.push_back({w, h});
  }
  int h = max(rect[0][0], rect[0][1]);
  for (int i = 1; i < n; ++i) {
    if (min(rect[i][0], rect[i][1]) > h) {
      cout << "NO" << endl;
      return;
    }

    if (max(rect[i][0], rect[i][1]) <= h) {
      h = max(rect[i][0], rect[i][1]);
    } else {
      h = min(rect[i][0], rect[i][1]);
    }
  }
  cout << "YES" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
