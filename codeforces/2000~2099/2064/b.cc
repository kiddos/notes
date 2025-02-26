#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  map<int,int> count;
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }

  int i = 0;
  array<int,3> ans = {0, 0, 0};
  while (i < n) {
    if (count[a[i]] != 1) {
      i++;
    } else {
      int j = i;
      while (j+1 < n && count[a[j+1]] == 1) {
        j++;
      }
      
      int remove = j-i+1;
      ans = max(ans, {remove, i, j});
      i = j+1;
    }
  }

  if (ans[0] == 0) {
    cout << "0" << endl;
  } else {
    cout << ans[1]+1 << " " << ans[2]+1 << endl;
  }
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
