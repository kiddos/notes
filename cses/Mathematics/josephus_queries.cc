#include <bits/stdc++.h>

using namespace std;

using i64 = long long;


// 1 2 3 4 5 6 7
// 1 3 5 7
// 3 7
// 7

int josephus(int n, int k) {
  if (n == 1) {
    return 1;
  }
  if (k * 2 <= n) {
    // cout << "f(" << n << "," << k << ")=" << k * 2 << endl;
    return k * 2;
  }
  int result = josephus(n - n / 2, k - n / 2);
  if (n % 2 == 1) {
    result = (result-1) * 2 - 1;
  } else {
    result = result * 2 - 1;
  }
  if (result < 0) {
    result += n + 1;
  }
  // cout << "f(" << n << "," << k << ")=" << result << endl;
  return result;
}

void solve() {
  int q = 0;
  cin >> q;

  vector<int> ans;
  for (int i = 0; i < q; ++i) {
    int n = 0, k = 0;
    cin >> n >> k;
    int result = josephus(n, k);
    ans.push_back(result);
  }
  for (int c : ans) {
    cout << c << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
