#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> A(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }
  i64 total = accumulate(A.begin(), A.end(), 0LL);
  i64 max_size = *max_element(A.begin(), A.end());
  i64 rest = total - max_size;
  if (rest * 2 < max_size) {
    cout << rest << endl;
  } else {
    cout << total / 3 << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
