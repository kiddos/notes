#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int>& a) {
  int n = a.size();
  vector<bool> found(n+1);
  sort(a.rbegin(), a.rend());
  for (int aa : a) {
    while (aa > n || (found[aa] && aa > 0)) {
      aa /= 2;
    }
    found[aa] = true;
  }
  for (int i = 1; i <= n; ++i) {
    if (!found[i]) return false;
  }
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t--) {
    int n = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    bool ans = solve(a);
    if (ans) cout << "YES\n";
    else cout << "NO\n";
  }
  cout << flush;
  return 0;
}
