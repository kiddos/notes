#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, k = 0, x = 0;
  cin >> n >> k >> x;

  vector<int> ans;
  if (x == 1) {
    if (k == 1) {
      cout << "NO" << endl;
      return;
    } else if (k == 2) {
      if (n % 2 == 1) {
        cout << "NO" << endl;
        return;
      } else {
        for (int i = 0; i < n; i += 2) {
          ans.push_back(2);
        }
      }
    } else {
      if (n == 1) {
        cout << "NO" << endl;
        return;
      } else {
        int r = n;
        if (n % 2 == 1) {
          ans.push_back(3);
          r -= 3;
        }
        while (r > 0) {
          ans.push_back(2);
          r-= 2;
        }
      }
    }
  } else {
    for (int i = 0; i < n; ++i) {
      ans.push_back(1);
    }
  }

  cout << "YES" << endl;
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) {
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
