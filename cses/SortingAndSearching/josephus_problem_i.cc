#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  deque<int> d;
  for (int i = 1; i <= n; ++i) {
    d.push_back(i);
  }

  vector<int> ans;
  while (!d.empty()) {
    int i1 = d.front();
    d.pop_front();
    d.push_back(i1);

    ans.push_back(d.front());
    d.pop_front();
  }
  for (int idx : ans) {
    cout << idx << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
