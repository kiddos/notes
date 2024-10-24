#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int min_val = *min_element(a.begin(), a.end());

  vector<bool> can_be_swap(n);
  vector<int> group;
  for (int i = 0; i < n; ++i) {
    if (gcd(min_val, a[i]) == min_val) {
      can_be_swap[i] = true;
      group.push_back(a[i]);
    }
  }
  sort(group.begin(), group.end());
  for (int i = 0, j = 0; i < n; ++i) {
    if (can_be_swap[i]) {
      a[i] = group[j++];
    }
  }
  for (int i = 1; i < n; ++i) {
    if (a[i-1] > a[i]) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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
