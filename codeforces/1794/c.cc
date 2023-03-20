#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];

  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    int l = 0, r = i;
    int index = r;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (s[mid] >= (i-mid+1)) {
        index = mid;
        r = mid-1;
      } else {
        l = mid+1;
      }
    }
    ans.push_back(i-index+1);
  }

  for (int a : ans) cout << a << " ";
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
