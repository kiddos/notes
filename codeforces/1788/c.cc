#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  if (n % 2 == 0) {
    cout << "NO" << endl;
    return;
  }

  int m = n * 2;
  vector<int> a(m);
  iota(a.begin(), a.end(), 1);
  vector<pair<int,int>> pairs;
  int mid = a[0] + a.back();
  int start = mid - n / 2;
  for (int i = 0; i < n; i += 2) {
    pairs.push_back({a[i], start - a[i]});
    start++;
  }
  for (int i = 1; i < n; i += 2) {
    pairs.push_back({a[i], start - a[i]});
    start++;
  }

  cout << "YES" << endl;
  for (auto& [i, j] : pairs) {
    cout << i << " " << j << endl;
  }
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
