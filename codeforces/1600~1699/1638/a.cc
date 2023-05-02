#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int>& p) {
  int n = p.size();
  for (int i = 0; i < n; ++i) {
    if (p[i] == i+1) continue;
    for (int j = i+1; j < n; ++j) {
      if (p[j] == i+1) {
        reverse(p.begin()+i, p.begin()+j+1);
        return p;
      }
    }
  }
  return p;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    vector<int> ans = solve(p);
    for (int a : ans) cout << a << ' ';
    cout << '\n';
  }
  cout << flush;
  return 0;
}
