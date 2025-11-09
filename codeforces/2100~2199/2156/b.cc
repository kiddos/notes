#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  string s;
  cin >> s;
  bool has_b = false;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'B') {
      has_b = true;
      break;
    }
  }

  auto process_query = [&](int x) -> int {
    int ans = 0;
    while (x > 0) {
      if (s[ans%n] == 'B') {
        x /= 2;
      } else if (s[ans%n] == 'A') {
        x--;
      }
      ans++;
    }
    return ans;
  };

  vector<int> ans;
  for (int i = 0; i < q; ++i) {
    int a = 0;
    cin >> a;
    if (has_b) {
      ans.push_back(process_query(a));
    } else {
      ans.push_back(a);
    }
  }

  for (int op : ans) {
    cout << op << endl;
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
