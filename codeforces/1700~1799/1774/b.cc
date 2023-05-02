#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    ll n = 0, m = 0, k = 0;
    cin >> n >> m >> k;
    int less_than = (n + k - 1) / k;
    int max_count = 0;
    bool good = true;
    for (int i = 0; i < m; ++i) {
      ll a = 0;
      cin >> a;
      if (a > less_than) {
        good = false;
      }
      if (a == less_than) max_count++;
    }
    if (good && max_count <= (n-1) % k + 1) cout << "YES" << endl;
    else cout << "NO"<< endl;
  }
  return 0;
}
