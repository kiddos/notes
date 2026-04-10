#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  i64 sum = accumulate(a.begin(), a.end(), 0LL);
  if (sum % 3 != 0) {
    cout << "0" << endl;
    return;
  }
  i64 part = sum / 3;
  i64 current = 0;
  map<i64,int> prefix_count;
  i64 ans = 0;
  for (int i = 0; i < n-1; ++i) {
    current += a[i];
    if (current == part * 2) {
      ans += prefix_count[part];
    }
    prefix_count[current]++;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
