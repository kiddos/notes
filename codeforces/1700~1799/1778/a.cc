#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& a) {
  int n = a.size();
  int sum = accumulate(a.begin(), a.end(), 0);
  for (int i = 1; i < n; ++i) {
    if (a[i-1] < 0  && a[i] < 0) {
      cout << sum + 4 << endl;
      return;
    }
  }
  for (int i = 1; i < n; ++i) {
    if (a[i-1] != a[i]) {
      cout << sum << endl;
      return;
    }
  }
  cout << sum - 4 << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    solve(a);
  }
  return 0;
}
