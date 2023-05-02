#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& a) {
  sort(a.begin(), a.end());

  map<int, int> count;
  int n = a.size();
  for (int i = 0; i < n; ++i) count[a[i]]++;

  int ans = 0;
  if (a[0] != 0) ans++;

  for (int i = 0; i < n; ++i) {
    count[a[i]]--;
    if (count[a[i]] == 0) {
      count.erase(a[i]);
    }

    if (a[i] <= i && count.upper_bound(i+1) == count.begin()) {
      ans++;
    }
  }
  cout << ans << endl;
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
