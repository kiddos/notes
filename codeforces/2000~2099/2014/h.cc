#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 1000000;
vector<int> h(MAX_N + 1);

void precompute() {
  mt19937 gen(chrono::system_clock::now().time_since_epoch().count());;
  for (int i = 1; i <= MAX_N; ++i) {
    h[i] = gen();
  }
}

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> p(n+1);
  for (int i = 1; i <= n; ++i) {
    p[i] = h[a[i]] ^ p[i-1];
  }

  for (int i = 0; i < q; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    if (p[l-1] == p[r]) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
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
