#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& a) {
  int n = a.size();
  int max_val = *max_element(a.begin(), a.end());
  vector<vector<int>> index(max_val+1);
  for (int i = 0; i < n; ++i) {
    index[a[i]].push_back(i);
  }
  int ans = -1;
  for (int a = 0; a <= max_val; ++a) {
    if (index[a].size() <= 1) continue;
    vector<int> back(index[a].size());
    for (int j = 0; j < index[a].size()-1; ++j) {
      int front = index[a][j];
      int back = n-index[a][j+1] - 1;
      int len = front + back + 1;
      ans = max(ans, len);
    }
  }
  return ans;
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

    int ans = solve(a);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}
