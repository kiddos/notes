#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;

  auto query1 = [&](i64 x, i64 y) -> i64 {
    i64 p = 1LL << (2 * (n-1));
    i64 o = 1 << (n-1);
    i64 d = 0;
    while (o > 0) {
      i64 c = 0;
      i64 px = x >= o ? 1 : 0, py = y >= o ? 1 : 0;
      if (px == 0 && py == 0) {
        c = 0;
      } else if (px == 0 && py == 1) {
        c = 3;
      } else if (px == 1 && py == 0) {
        c = 2;
      } else if (px == 1 && py == 1) {
        c = 1;
      }
      d += c * p;
      x %= o;
      y %= o;
      p /= 4;
      o /= 2;
    }
    return d+1;
  };

  auto query2 = [&](i64 d) -> pair<i64,i64> {
    i64 p = 1LL << (2 * (n-1));
    i64 o = 1 << (n-1);
    pair<i64,i64> ans = {0, 0};
    while (d > 0) {
      i64 c = d / p; 
      if (c == 1) {
        ans.first += o;
        ans.second += o;
      } else if (c == 2) {
        ans.first += o;
      } else if (c == 3) {
        ans.second += o;
      }
      d %= p;
      p /= 4;
      o /= 2;
    }
    return ans;
  };

  for (int i = 0; i < q; ++i) {
    string op;
    cin >> op;
    if (op == "->") {
      i64 x = 0, y = 0;
      cin >> x >> y;
      i64 ans = query1(x-1, y-1);
      cout << ans << endl;
    } else if (op == "<-") {
      i64 d = 0;
      cin >> d;
      auto ans = query2(d-1);
      cout << ans.first+1 << " " << ans.second+1 << endl;
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
