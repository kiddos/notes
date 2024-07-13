#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  auto all_one = [&]() {
    for (int i = 1; i <= n; ++i) {
      if (a[i] != 1) {
        return false;
      }
    }
    return true;
  };

  vector<int> ans;
  if (all_one()) {
    ans.push_back(n+1);
    for (int x = 1; x <= n; ++x) {
      ans.push_back(x);
    }
  } else {
    for (int i = 1; i <= n; ++i) {
      if (i+1 <= n && a[i] == 0 && a[i+1] == 1) {
        for (int x = 1; x <= i; ++x) {
          ans.push_back(x);
        }
        ans.push_back(n+1);
        for (int x = i+1; x <= n; ++x) {
          ans.push_back(x);
        }
        break;
      } else if (i == n && a[i] == 0) {
        for (int x = 1; x <= n; ++x) {
          ans.push_back(x);
        }
        ans.push_back(n+1);
        break;
      }
    }
  }

  if (ans.empty()) {
    cout << "-1" << endl;
    return;
  }

  for (int node : ans) {
    cout << node << " ";
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
