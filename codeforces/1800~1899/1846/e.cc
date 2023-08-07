#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr int MAX_VAL = 1000000;
vector<bool> possible(MAX_VAL+1);

void precompute() {
  for (int k = 2; k*k <= MAX_VAL; ++k) {
    ll sum = 1 + k + k * k;
    ll p = k * k * k;
    while (sum < MAX_VAL) {
      possible[sum] = true;
      sum += p;
      p *= k;
    }
  }
}

void solve() {
  int n = 0;
  cin >> n;
  if (possible[n]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
