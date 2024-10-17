#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(2 * n + 1);
  for (int i = 1; i <= n * 2; ++i) {
    cin >> a[i];
  }

  vector<int> even, odd;
  for (int i = 1; i <= n * 2; ++i) {
    if (a[i] % 2 == 0) {
      even.push_back(i);
    } else {
      odd.push_back(i);
    }
  }

  vector<pair<int,int>> ans;
  for (int i = 0; i+1 < (int)even.size(); i += 2) {
    ans.emplace_back(even[i], even[i+1]);
  }
  for (int i = 0; i+1 < (int)odd.size(); i += 2) {
    ans.emplace_back(odd[i], odd[i+1]);
  }
  while ((int) ans.size() > n-1) {
    ans.pop_back();
  }
  for (auto [i1, i2] : ans) {
    cout << i1 << " " << i2 << endl;
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
