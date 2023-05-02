#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  int l = 0, r = n-1;
  while (l < n && a[l] == b[l]) l++;
  while (r >= 0 && a[r] == b[r]) r--;
  int max_val = *max_element(a.begin()+l, a.begin()+r+1);
  int min_val = *min_element(a.begin()+l, a.begin()+r+1);

  while (l-1 >= 0 && a[l-1] <= min_val) {
    min_val = a[l-1];
    l--;
  }
  while (r+1 < n && a[r+1] >= max_val) {
    max_val = a[r+1];
    r++;
  }

  cout << l+1 << " " << r+1 << endl;
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
