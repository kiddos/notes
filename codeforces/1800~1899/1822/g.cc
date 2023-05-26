#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  map<ll, ll> freq;
  for (int i = 0; i < n; ++i) {
    freq[a[i]]++;
  }

  ll ans = 0;
  for (auto& [ai, count] : freq) {
    if (count >= 3) {
      ans += count * (count-1) * (count-2);
    }
  }

  ll max_val = *max_element(a.begin(), a.end());
  ll limit = pow(max_val, 2.0 / 3);
  // cout << "limit: " << limit << endl;
  for (auto it = freq.begin(); it != freq.end(); ++it) {
    ll aj = it->first;
    ll a_count = it->second;

    if (aj > limit) {
      for (int b = 2; aj * b <= max_val; ++b) {
        if (aj * b > max_val) break;
        if (aj % b != 0) continue;

        if (freq.count(aj * b) && freq.count(aj / b)) {
          ans += a_count * freq[aj*b] * freq[aj / b];
        }
      }
    } else {
      vector<int> divisors;
      ll x = aj;
      for (int d = 1; d*d <= x; ++d) {
        if (x % d == 0) {
          divisors.push_back(d);
          divisors.push_back(x/d);
        }
      }
      sort(divisors.begin(), divisors.end());
      divisors.erase(unique(divisors.begin(), divisors.end()), divisors.end());

      for (int d : divisors) if (d != 1) {
        if (freq.count(aj / d) && freq.count(aj * d)) {
          ans += a_count * freq[aj / d] * freq[aj * d];
        }
      }
    }
  }

  cout << ans << endl;
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
