#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  ifstream input("input.txt");
  ofstream output("output.txt");

  int n = 0, k = 0;
  input >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    input >> a[i];
  }
  vector<pair<int,int>> p;
  for (int i = 0; i < n; ++i) {
    p.push_back({a[i], i+1});
  }
  sort(p.rbegin(), p.rend());
  output << p[k-1].first << endl;
  for (int i = 0; i < k; ++i) {
    output << p[i].second << " ";
  }
  output << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
