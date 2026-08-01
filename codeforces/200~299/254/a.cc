#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  ifstream input("input.txt");
  ofstream output("output.txt");
  int n = 0;
  input >> n;
  int m = 2*n;
  vector<int> a(m+1);
  for (int i = 1; i <= m; ++i) {
    input >> a[i];
  }
  map<int,vector<int>> indices;
  for (int i = 1; i <= m; ++i) {
    indices[a[i]].push_back(i);
  }

  vector<pair<int,int>> ans;
  for (auto [x, idx] : indices) {
    if (idx.size()  % 2 != 0) {
      output << "-1" << endl;
      return;
    }
    int size = idx.size();
    for (int i = 0; i < size; i += 2) {
      ans.push_back({idx[i], idx[i+1]});
    }
  }

  for (auto [i1, i2] : ans) {
    output << i1 << " " << i2 << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
