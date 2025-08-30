#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> S(n);
  for (int i = 0; i < n; ++i) {
    cin >> S[i];
  }
  vector<int> T(n);
  for (int i = 0; i < n; ++i) {
    cin >> T[i];
  }
  map<int,int> need;
  for (int i = 0; i < n; ++i) {
    int mod_k = T[i] % k;
    need[mod_k]++;
  }

  for (int i = 0; i < n; ++i) {
    int mod_k = S[i] % k;
    int mod_k_prime = (k - mod_k) % k;
    if (need.count(mod_k)) {
      if (--need[mod_k] == 0) {
        need.erase(mod_k);
      }
    } else if (need.count(mod_k_prime)) {
      if (--need[mod_k_prime] == 0) {
        need.erase(mod_k_prime);
      }
    } else {
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
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
