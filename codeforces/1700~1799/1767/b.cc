#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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
    sort(a.begin()+1, a.end());
    ll ans = a[0];
    for (int i = 1; i < n; ++i) {
      if (a[i] > ans) {
        int diff = a[i] - ans;
        ans += (diff+1) / 2;
      }
    }
    cout << ans <<  endl;
  }
  return 0;
}
