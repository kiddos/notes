#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL solve(vector<int>& a) {
  int n = a.size();
  vector<int> zeros = {0};
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) zeros.push_back(zeros.back()+1);
    else zeros.push_back(zeros.back());
  }

  LL ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      LL mex = zeros[j+1] - zeros[i];
      LL cost = mex + j-i+1;
      // cout << i << " - " << j << ": mex: " << mex << ", len = " << j-i+1 << endl;
      ans += cost;
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
    int n = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    LL ans = solve(a);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}
