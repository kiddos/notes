#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int>& a) {
  map<int, int> count;
  for (int aa : a) count[aa]++;

  int n = a.size();
  int total = count.size();
  vector<int> ans;
  for (int k = 1; k <= n; ++k) {
    ans.push_back(max(k, total));
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
    vector<int> ans = solve(a);
    for (int aa : ans) cout << aa << ' ';
    cout << '\n';
  }
  cout << flush;
  return 0;
}
