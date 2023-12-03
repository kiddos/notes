#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int sum = accumulate(a.begin(), a.end(), 0);
  if (sum == 0) {
    cout << "0" << endl;
    return;
  }

  vector<pair<int,int>> ans;
  int x = accumulate(a.begin(), a.end(), 0, [](int a, int b) { return a ^ b; });
  ans.push_back({1, n});

  if (x > 0) {
    // array are all x
    if (n % 2 == 0) {
      ans.push_back({1, n}); // all zero
    } else {
      ans.push_back({2, n}); // 2~n is 0
      ans.push_back({1, 2}); // 1~2 is x
      ans.push_back({1, 2}); // all zero
    }
  }

  cout << ans.size() << endl;
  for (auto& [l, r] : ans) {
    cout << l << " " << r << endl;
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
