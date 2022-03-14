#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int n) {
  const int max_val = 1e9;
  vector<int> ans;
  int i = 1;
  while (i <= max_val && ans.size() < n) {
    ans.push_back(i);
    i *= 3;
  }
  if (ans.size() == n) return ans;
  return {};
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
    if (ans.size() == 0) cout << "NO\n";
    else {
      cout << "YES\n";
      for (int a : ans) cout << a << ' ';
      cout << '\n';
    }
  }
  cout << flush;
  return 0;
}
