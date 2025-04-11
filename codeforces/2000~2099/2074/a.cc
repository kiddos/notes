#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  vector<int> len(4);
  for (int i = 0; i < 4; ++i) {
    cin >> len[i];
  }
  set<int> s(len.begin(), len.end());
  if (s.size() == 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
