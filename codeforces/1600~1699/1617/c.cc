#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& a) {
  int n = a.size();
  set<int> required;
  for (int i = 1; i <= n; ++i) required.insert(i);

  vector<int> left_over;
  for (int aa : a) {
    if (required.count(aa)) {
      required.erase(aa);
    } else {
      left_over.push_back(aa);
    }
  }

  sort(left_over.rbegin(), left_over.rend());
  int ans = 0;
  for (int i = 0; i < left_over.size(); ++i) {
    int can_cover = (left_over[i] + 1) / 2 - 1;
    auto p = required.upper_bound(can_cover);
    if (p == required.begin()) return -1;
    required.erase(prev(p));
    ans++;
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
    int ans = solve(a);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}
