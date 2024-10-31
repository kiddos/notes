#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void validate(vector<i64>& a, vector<i64>& ans) {
  vector<i64> b = a;
  for (i64 x : ans) {
    b.push_back(x);
  }
  i64 sum = 0, x = 0;
  for (i64 bi : b) {
    sum += bi;
    x ^= bi;
  }
  assert(sum == x * 2);
}

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  i64 x = 0, sum = 0;
  for (int i = 0; i < n; ++i) {
    x ^= a[i];
    sum += a[i];
  }

  vector<i64> ans = {x, x + sum};
  cout << ans.size() << endl;
  for (i64 x : ans){
    cout << x << " ";
  }
  cout << endl;
  
  // validate(a, ans);
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
