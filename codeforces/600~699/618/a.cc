#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> ans;
  for (int i = 30; i >= 0; --i) {
    if (n & (1<<i)) {
      ans.push_back(i+1);
    }
  }
  for (int b : ans) {
    cout << b << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
