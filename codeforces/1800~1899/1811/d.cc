#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> F = {1, 1};

void precompute() {
  for (int i = 2; i <= 45; ++i) {
    F.push_back(F[i-2] + F[i-1]);
  }
  // for (int i = 0; i <= 45; ++i) cout << F[i] << " ";
  // cout << endl;
}

void solve() {
  int n = 0;
  ll x = 0, y = 0;
  cin >> n >> x >> y;

  bool b = true;
  for (int c = n; c >= 1; --c) {
    if (b) {
      ll w1 = F[c], w2 = F[c-1];
      if (y > w2 && y <= w1) {
        cout << "NO" << endl;
        return;
      }
      if (y > w1) {
        y -= w1;
      }
    } else {
      ll h1 = F[c], h2 = F[c-1];
      if (x > h2 && x <= h1) {
        cout << "NO" << endl;
        return;
      }
      if (x > h1) {
        x -= h1;
      }
    }
    // cout << "x=" << x << ", y=" << y << endl; 
    b = !b;
  }
  cout << "YES" << endl;
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
