#include <bits/stdc++.h>

using namespace std;

void output(vector<int>& p) {
  int n = p.size();
  for (int i = 0; i < n; ++i) {
    cout << p[i] << ' ';
  }
  cout << '\n';
}

void solve(int n) {
  vector<int> p(n);
  for (int i = 0; i < n; ++i) p[i] = n-i;
  output(p);
  for (int i = 1; i < n; ++i) {
    swap(p[i], p[i-1]);
    output(p);
    swap(p[i], p[i-1]);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    solve(n);
  }
  cout << flush;
  return 0;
}
