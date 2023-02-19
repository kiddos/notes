#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& a) {
  int n = a.size();
  int g = a[0];
  for (int i = 1; i < n; ++i) {
    g = gcd(g, a[i]);
  }

  cout << a.back() / g << endl;
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
