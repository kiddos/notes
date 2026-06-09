#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> next_peak(n);
  int idx = 0;
  while (idx < n) {
    int j = idx;
    while (j+1 < n && a[j+1] >= a[j]) {
      j++;
    }
    for (int i = idx; i <= j; ++i) {
      next_peak[i] = j;
    }
    idx = j+1;
  }

  vector<int> next_vally(n);
  idx = 0;
  while (idx < n) {
    int j = idx;
    while (j+1 < n && a[j+1] <= a[j]) {
      j++;
    }
    for (int i = idx; i <= j; ++i) {
      next_vally[i] = j;
    }
    idx = j+1;
  }


  vector<bool> ans;
  for (int i = 0; i < m; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    l--;
    r--;
    int current = l;
    current = next_peak[current];
    current = next_vally[current];
    ans.push_back(current >= r);
  }

  for (int i = 0; i < m; ++i) {
    if (ans[i]) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
