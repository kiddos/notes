#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool solve(vector<int>& a) {
  sort(a.begin(), a.end());
  int n = a.size();
  ll right = a.back(), left = a[0] + a[1];
  int r = n-2, l = 2;
  while (right <= left && l < r) {
    right += a[r--];
    left += a[l++];
  }
  return right > left;
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
