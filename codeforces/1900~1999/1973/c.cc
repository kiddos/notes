#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 2 1 5 3 4
// 2 1 6 3 5 4

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n);
  for (int i = 0;i < n; ++i) cin >> p[i];

  auto construct = [&](int offset) -> vector<int> {
    vector<int> ans(n);
    vector<pair<int,int>> peeks;
    for (int i = offset; i < n-1; i += 2) {
      peeks.emplace_back(p[i], i);
    }
    sort(peeks.begin(), peeks.end());
    int r = n;
    for (int i = 0; i < (int) peeks.size(); ++i) {
      ans[peeks[i].second] = r--;
    }

    vector<pair<int,int>> cave;
    for (int i = 0; i < n; ++i) if (ans[i] == 0) {
      cave.emplace_back(p[i], i);
    }
    sort(cave.begin(), cave.end());
    for (int i = 0; i < (int) cave.size(); ++i) {
      ans[cave[i].second] = r--;
    }
    return ans;
  };

  auto count_peek = [&](vector<int>& a) -> int {
    int count = 0;
    for (int i = 1; i < n-1; ++i) {
      int l = a[i-1] + p[i-1];
      int r = a[i+1] + p[i+1];
      int c = a[i] + p[i];
      if (c > l && c > r) {
        count++;
      }
    }
    return count;
  };

  vector<int> ans1 = construct(1);
  vector<int> ans2 = construct(2);
  int count1 = count_peek(ans1);
  int count2 = count_peek(ans2);
  vector<int> ans = ans1;
  if (count2 > count1) {
    ans = ans2;
  }

  for (int i = 0; i < n; ++i) {
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
