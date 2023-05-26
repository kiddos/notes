#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i];

  if (n == 1) {
    cout << "1" << endl;
    return;
  }

  int target = n;
  if (p[0] == n) {
    target = n-1;
  }

  int index = 0;
  for  (int i = 0; i < n-1; ++i) {
    if (p[i+1] == target) {
      index = i;
      break;
    }
  }

  if (index == n-2) {
    index++;
  }

  vector<int> ans;
  for (int i = index+1; i < n; ++i) ans.push_back(p[i]);

  int j = index;
  ans.push_back(p[j]);
  for (; j >= 1 && p[j-1] > p[0];) {
    --j;
    ans.push_back(p[j]);
  }
  for (int i = 0; i < j; ++i) ans.push_back(p[i]);

  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << " ";
  }
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
