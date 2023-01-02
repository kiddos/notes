#include <bits/stdc++.h>

using namespace std;

long swap(vector<int> a, vector<int> b)  {
  int n = a.size();
  for (int i = 0; i < n; ++i) {
    if (a[i] > b[i]) {
      swap(a[i], b[i]);
    }
  }
  long aa = *max_element(a.begin(), a.end());
  long bb = *max_element(b.begin(), b.end());
  return aa * bb;
}

int solve(vector<int>&a, vector<int>& b) {
  return swap(a, b);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    int ans = solve(a, b);
    cout << ans << '\n';
  }
  cout << flush;

  return 0;
}
