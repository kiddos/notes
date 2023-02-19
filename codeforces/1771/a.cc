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

    int max_val = *max_element(a.begin(), a.end());
    int min_val = *min_element(a.begin(), a.end());
    ll max_count = 0, min_count = 0;
    for (int num : a) {
      max_count += num == max_val;
      min_count += num == min_val;
    }
    ll ans = max_count * min_count * 2;
    if (max_val == min_val) {
      ans = max_count * (max_count-1);
    }
    cout << ans << endl;
  }
  return 0;
}
