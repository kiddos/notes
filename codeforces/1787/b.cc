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

    int x = n;
    unordered_map<int, int> factors;
    for (int d = 2; d * d <= x; ++d) {
      while (x % d == 0) {
        factors[d]++;
        x /= d;
      }
    }
    if (x > 1) factors[x]++;

    // cout << "factors: " << endl;
    // for (auto& [f, count] : factors) cout << f << " : " << count << endl;

    ll ans = 0;
    while (factors.size() > 0) {
      vector<int> remove;
      ll a = 1;
      for (auto& [f, count] : factors) {
        a *= f;
        if (--count == 0) remove.push_back(f);
      }
      for (int f : remove) factors.erase(f);
      ans += a;
    }
    cout << ans << endl;
  }
  return 0;
}
