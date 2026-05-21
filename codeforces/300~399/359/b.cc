#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  int size = n * 2;
  vector<int> p(n * 2);
  iota(p.begin(), p.end(), 1);
  int t = k;
  for (int i = 1; i < size && t > 0; i += 4) {
    swap(p[i], p[i-1]);
    t--;
  }
  for (int i = 0; i < size; ++i) {
    cout << p[i] << " ";
  }
  cout << endl;

  // int a = 0, b = 0;
  // for (int i = 0; i < n; ++i) {
  //   a += abs(p[i*2] - p[i*2+1]);
  //   b += p[i*2] - p[i*2+1];
  // }
  // int sum = a - abs(b);
  // cout << "sum=" << sum << ", 2k=" << 2 * k << endl;
  // assert(sum == k * 2);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
