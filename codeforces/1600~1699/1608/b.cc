#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, a = 0, b = 0;
  cin >> n >> a >> b;

  int most = (n-1) / 2;
  if (max(a, b) > most) {
    cout << "-1" << endl;
    return;
  }
  if (abs(a- b) > 1) {
    cout << "-1" << endl;
    return;
  }
  if (n % 2 == 1 && most == max(a, b) && a == b) {
    cout << "-1" << endl;
    return;
  }

  int x = 1, y = n;
  vector<int> ans;
  if (a >= b) {
    int z = a;
    while (z > 0) {
      ans.push_back(x++);
      ans.push_back(y--);
      z--;
    }
    if (a == b) {
      while (x <= y) {
        ans.push_back(x++);
      }
    } else {
      while (y >= x) {
        ans.push_back(y--);
      }
    }
  } else {
    int z = b;
    while (z > 0) {
      ans.push_back(y--);
      ans.push_back(x++);
      z--;
    }
    while (x <= y) {
      ans.push_back(x++);
    }
  }

  for (int i = 0; i < (int)ans.size(); ++i) cout << ans[i] << " ";
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
