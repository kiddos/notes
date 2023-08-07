#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr int MAX_VAL = 200000;
vector<int> f = {0, 1};

void precompute() {
  while (true) {
    int s = f.size();
    int sum = f[s-1] + f[s-2];
    if (sum > MAX_VAL) {
      break;
    }

    f.push_back(sum);
  }
}

void solve() {
  ll n = 0, k = 0;
  cin >> n >> k;

  if (k > f.size()) {
    cout << "0" << endl;
    return;
  }

  int min_reachable = f[k-1];
  if (n < min_reachable) {
    cout << "0" << endl;
    return;
  }

  if (n == min_reachable) {
    cout << "1" << endl;
    return;
  }

  // fk = a * f1 + b * f2 = n
  // f2 = (n - a * f1) / b
  int a = f[k-2];
  int b = f[k-1];
  int ans = 0;
  // cout << "a=" << a << ",b=" << b << endl;
  for (int f1 = 0; f1 <= n; ++f1) {
    int val = n - a * f1;
    if (val >= 0 && val % b == 0 && val / b >= f1) {
      // cout << "f1=" << f1 << ", f2=" << val / b << endl;
      ans++;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  // cout << "size=" << f.size() << endl;
  // for (int i = 0; i < f.size(); ++i) {
  //   cout << f[i] << " ";
  // }
  // cout << endl;

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
