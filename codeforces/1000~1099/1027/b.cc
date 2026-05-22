#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0;
  int q = 0;
  cin >> n >> q;
  vector<i64> ans;
  for (int i = 0; i < q; ++i) {
    i64 x = 0, y = 0;
    cin >> x >> y;
    if ((x + y) % 2 == 0) {
      i64 prev = (x-1) * (n / 2);
      if (n % 2 == 1) {
        prev += x / 2;
      }
      prev += (y+1) / 2;
      ans.push_back(prev);
    } else {
      i64 prev = (x-1) * (n / 2);
      if (n % 2 == 1) {
        prev += (x-1) / 2;
      }
      prev += (y+1) / 2;
      prev += (n * n + 1) / 2;
      ans.push_back(prev);
    }
  }

  for (i64 x : ans) {
    cout << x << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
