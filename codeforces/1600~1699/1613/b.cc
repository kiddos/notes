#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> solve(vector<int>& a) {
  constexpr int MAX_VAL = 1e6;
  int n = a.size();
  sort(a.begin(), a.end());
  vector<bool> s(MAX_VAL+1);
  for (int aa : a) s[aa] = true;

  vector<pair<int, int>> ans;
  for (int i = 0; i < n && ans.size() < n / 2; ++i) {
    for (int j = i+1; j < n && ans.size() < n / 2; ++j) {
      if (!s[a[j] % a[i]]) {
        ans.emplace_back(a[j], a[i]);
      }
    }
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int n = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<pair<int, int>> ans = solve(a);
    for (auto [p, q] : ans) {
      cout << p << ' ' << q << '\n';
    }
  }
  cout.flush();
  return 0;
}
