#include <bits/stdc++.h>

using namespace std;

using i64 = long long;


void solve() {
  int n = 0;
  cin >> n;
  int m = n * 2;
  vector<int> st;
  int ans = 0;
  int to_remove = 1;
  for (int i = 0; i < m; ++i) {
    string command;
    cin >> command;
    if (command == "add") {
      int x = 0;
      cin >> x;
      st.push_back(x);
    } else if (command == "remove") {
      if (!st.empty()) {
        if (st.back() == to_remove) {
          st.pop_back();
        } else {
          ans++;
          st.clear();
        }
      }
      to_remove++;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
