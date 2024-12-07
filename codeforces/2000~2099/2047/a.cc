#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> sizes = {1};
vector<i64> prefix = {0};

void precompute() {
  for (int i = 1; i <= 100; ++i) {
    sizes.push_back(i * 2 * 4);
  }
  for (int s : sizes) {
    prefix.push_back(prefix.back() + s);
  }
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int sum = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i];
    bool found = binary_search(prefix.begin(), prefix.end(), sum);
    if (found) {
      ans++;
    }
  }

  cout << ans << endl;
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
