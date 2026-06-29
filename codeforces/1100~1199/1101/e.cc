#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int max_x = 0, max_y = 0;

  auto insert = [&](int x, int y) -> void {
    int a = min(x, y);
    int b = max(x, y);
    max_x = max(max_x, a);
    max_y = max(max_y, b);
  };

  auto check = [&](int w, int h) -> bool {
    int a = min(w, h);
    int b = max(w, h);
    return a >= max_x && b >= max_y;
  };

  for (int i = 0; i < n; ++i) {
    char ch = '\0';
    cin >> ch;
    if (ch == '+') {
      int x = 0, y = 0;
      cin >> x >> y;
      insert(x, y);
    } else if (ch == '?') {
      int w = 0, h = 0;
      cin >> w >> h;
      if (check(w, h)) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
