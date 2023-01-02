#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int>& a) {
  int n = a.size();
  if (n == 1) return a[0] <= 1;
  sort(a.rbegin(), a.rend());

  if (a[0] - a[1] > 1) return false;
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int n = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    bool ans = solve(a);
    if (ans) cout << "YES\n";
    else cout << "NO\n";
  }
  cout.flush();
  return 0;
}
