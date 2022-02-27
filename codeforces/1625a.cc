#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& x, int l) {
  vector<int> bits(l);
  for (int xi : x) {
    for (int b = 0; b < l ; ++b) {
      if (xi & (1 << b)) bits[b]++;
    }
  }

  int n = x.size();
  int ans = 0;
  for (int b = 0; b < l; ++b) {
    if (bits[b] > n - bits[b]) {
      ans |= (1<<b);
    }
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0, l = 0;
    cin >> n >> l;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    int ans = solve(x, l);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}
