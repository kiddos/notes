#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> u(n);
  for (int i = 0; i < n; ++i) {
    cin >> u[i];
  }
  vector<int> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  vector<vector<int>> students(n+1);
  for (int i = 0; i < n; ++i) {
    students[u[i]].push_back(s[i]);
  }

  vector<i64> ans(n+1);
  for (vector<int>& skills : students) {
    sort(skills.rbegin(), skills.rend());
    vector<i64> prefix = {0};
    int size = skills.size();
    for (int i = 0; i < size; ++i) {
      prefix.push_back(prefix.back() + skills[i]);
    }
    for (int k = 1; k <= size; ++k) {
      int remove = size % k;
      ans[k] += prefix[size-remove];
    }
  }

  for (int k = 1; k <= n; ++k) {
    cout << ans[k] << " ";
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
