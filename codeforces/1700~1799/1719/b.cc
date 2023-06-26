#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  ll n = 0, k = 0;
  cin >> n >> k;

  vector<pair<int,int>> ans;
  if (k % 2 == 1) {
    vector<int> b1, b2;
    for (int b = 2; b <= n; b += 2) {
      if (b % 4 == 0) {
        b2.push_back(b);
      } else {
        b1.push_back(b);
      }
    }

    reverse(b1.begin(), b1.end());
    reverse(b2.begin(), b2.end());
    vector<int> as;
    for (int a = 1; a <= n; a += 2) {
      if ((a + k) % 2 == 0 && !b1.empty()) {
        ans.push_back({a, b1.back()});
        b1.pop_back();
      } else {
        as.push_back(a);
      }
    }

    if (!b1.empty()) {
      cout << "NO" << endl;
      return;
    }

    for (int a : as) {
      ans.push_back({a, b2.back()});
      b2.pop_back();
    }
  } else {
    vector<int> as;
    for (int a = 2; a <= n; a += 2) {
      if (a % 4 == 0) {
        ans.push_back({a-1, a});
      } else {
        if ((a + k) % 4 != 0) {
          cout << "NO" << endl;
          return;
        } else {
          ans.push_back({a, a-1});
        }
      }
    }
  }

  cout << "YES" << endl;
  for (auto& [a, b] : ans) {
    cout << a << " " << b << endl;
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
