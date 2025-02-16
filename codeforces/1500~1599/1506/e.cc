#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> min_p(vector<int>& q) {
  int n = q.size();
  set<int> s;
  for (int i = 1; i <= n; ++i) {
    s.insert(i);
  }
  vector<int> ans(n);
  ans[0] = q[0];
  s.erase(q[0]);
  for (int i = 1; i < n ; ++i) {
    if (q[i] > q[i-1]) {
      s.erase(q[i]);
      ans[i] = q[i];
    } else {
      int smallest = *s.begin();
      s.erase(smallest);
      ans[i] = smallest;
    }
  }
  return ans;
}

vector<int> max_p(vector<int>& q) {
  int n = q.size();
  set<int> s;
  for (int i = 1; i <= n; ++i) {
    s.insert(i);
  }
  vector<int> ans(n);
  ans[0] = q[0];
  s.erase(q[0]);
  for (int i = 1; i < n ; ++i) {
    if (q[i] > q[i-1]) {
      s.erase(q[i]);
      ans[i] = q[i];
    } else {
      auto it = s.upper_bound(q[i]);
      --it;
      ans[i] = *it;
      s.erase(it);
    }
  }
  return ans;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> q(n);
  for (int i = 0; i < n; ++i) {
    cin >> q[i];
  }

  vector<int> p1 = min_p(q);
  vector<int> p2 = max_p(q);
  for (int x : p1) {
    cout << x << " ";
  }
  cout << endl;
  for (int x : p2) {
    cout << x << " ";
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
