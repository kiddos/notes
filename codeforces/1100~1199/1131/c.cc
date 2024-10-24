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
  sort(a.begin(), a.end());

  int mid = n / 2;
  vector<int> ans(n);
  ans[mid] = a.back();
  a.pop_back();
  int l = mid - 1, r = mid + 1;
  while (a.size() >= 2) {
    ans[l--] = a.back();
    a.pop_back();
    ans[r++] = a.back();
    a.pop_back();
  }

  if (!a.empty()) {
    ans[l--] = a.back();
    a.pop_back();
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
