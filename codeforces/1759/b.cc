#include <bits/stdc++.h>

using namespace std;

vector<int> sums(1001);

void precompute() {
  for (int i = 1; i <= 1000; ++i) {
    sums[i] = sums[i-1] + i;
  }
}

void solve() {
  int m = 0, s = 0;
  cin >> m >> s;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) cin >> b[i];

  int sum = accumulate(b.begin(), b.end(), 0);
  auto p = find(sums.begin(), sums.end(), sum + s);
  if (p == sums.end()) {
    cout << "NO" << endl;
    return;
  }

  int size = p - sums.begin();
  vector<bool> perm(size+1);
  for (int i = 0; i < m; ++i) {
    if (b[i] > size) {
      cout << "NO" << endl;
      return;
    }
    perm[b[i]] = true;
  }

  int rest = 0;
  for (int i = 1; i <= size; ++i) {
    if (!perm[i]) rest += i;
  }

  if (rest != s) {
    cout << "NO" << endl;
    return;
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
