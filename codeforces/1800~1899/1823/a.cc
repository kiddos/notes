#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> p = {0, 0};

void precompute() {
  ll total = 0;
  for (int i = 1; i <= 100; ++i) {
    total += i;
    p.push_back(total);
  }
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  for (int i = 0; i <= n; ++i) {
    int pos = i, neg = n-i;
    ll total = p[pos] + p[neg];
    if (total == k) {
      cout << "YES" << endl;
      for (int i = 0; i < pos; ++i) {
        cout << "1 ";
      }
      for (int i = 0; i < neg; ++i) {
        cout << "-1 ";
      }
      cout << endl;
      return;
    }
  }

  cout << "NO" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
