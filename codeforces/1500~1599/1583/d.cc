#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  auto query1 = [&](int x) -> int {
    cout << "? ";
    for (int i = 0; i < n-1; ++i) {
      cout << x << " ";
    }
    cout << n << endl;
    int index = 0;
    cin >> index;
    return index;
  };

  vector<int> ans(n+1);
  ans.back() = n;
  for (int x = 1; x < n; ++x) {
    int result = query1(x);
    if (result > 0) {
      ans.back() = x;
      break;
    }
  }

  auto query2 = [&](int x, int last) -> int {
    cout << "? ";
    for (int i = 0; i < n-1; ++i) {
      cout << x << " ";
    }
    cout << last << endl;
    int index = 0;
    cin >> index;
    return index;
  };

  for (int x = 1; x <= n; ++x) {
    if (x != ans.back()) {
      int idx = query2(ans.back(), x);
      ans[idx] = x;
    }
  }

  auto answer = [&]() {
    cout << "! ";
    for (int i = 1; i <= n; ++i) {
      cout << ans[i] << " ";
    }
    cout << endl;
  };

  answer();
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
