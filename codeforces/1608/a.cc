#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int n) {
  vector<int> ans(n);
  iota(ans.begin(), ans.end(), 2);
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int n = 0;
    cin >> n;
    vector<int> ans = solve(n);
    for (int aa : ans) cout << aa << ' ';
    cout << '\n';
  }
  cout.flush();
  return 0;
}
