#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n+1);
  for (int i = 2; i <= n; ++i) {
    cin >> p[i];
  }
  vector<int> path;
  int current = n;
  while (current >= 1) {
    path.push_back(current);
    current = p[current];
  }

  reverse(path.begin(), path.end());
  for (int node : path) {
    cout << node << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}  
