#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> w(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }
  int l = log2(n)+8;
  int max_w = *max_element(w.begin(), w.end()) + l;
  vector<int> count(max_w+1);
  for (int i = 0; i < n; ++i) {
    count[w[i]]++;
  }
  for (int i = 0; i <= max_w; ++i) {
    if (i+1 <= max_w) {
      count[i+1] += count[i] / 2;
    }
    count[i] %= 2;
  }
  int ans = 0;
  for (int i = 0; i <= max_w; ++i) {
    ans += count[i] % 2;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
