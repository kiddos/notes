#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int query(set<int>& s) {
  cout << "? " << s.size() << " ";
  for (int x : s) {
    cout << x << " ";
  }
  cout << endl;
  int result = 0;
  cin >> result;
  return result;
}

void solve() {
  int n = 0;
  cin >> n;
  set<int> s;
  int m = n * 2;
  vector<int> ans(m + 1);
  for (int i = 1; i <= m; ++i) {
    s.insert(i);
    int result = query(s);
    if (result > 0) {
      ans[i] = result;
      s.erase(i);
    }
  }

  set<int> s2;
  vector<int> left;
  for (int i = 1; i <= m; ++i) {
    if (ans[i]) {
      s2.insert(i);
    } else {
      left.push_back(i);
    }
  }

  for (int idx : left) {
    s2.insert(idx);
    int result = query(s2);
    s2.erase(idx);
    ans[idx] = result;
  }

  cout << "! ";
  for (int i = 1; i <= m; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
