#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// select n+m-1 numbers
// such that we select n from a, m-1 from b
// and the numbers are unique
i64 greedy(vector<int>& a, vector<int>& b, int n, int m) {
  int x = a.size();
  int y = b.size();
  set<int> sa, sb;
  int i = x-1, j = y-1;
  for (int take = 0; i >= 0 && take < n; --i, ++take) {
    sa.insert(a[i]);
  }
  for (int take = 0; j >= 0 && take < m-1; --j, ++take) {
    sb.insert(b[j]);
  }
  vector<int> dup;
  for (int e : sa) {
    if (sb.count(e)) {
      dup.push_back(e);
    }
  }
  reverse(dup.begin(), dup.end());

  for (int e : dup) {
    while (i >= 0 && sb.count(a[i])) {
      i--;
    }
    while (j >= 0 && sa.count(b[j])) {
      j--;
    }

    if (i >= 0 && j >= 0) {
      int next_a = a[i], next_b = b[j];
      if (next_a >= next_b) {
        sa.erase(e);
        sa.insert(next_a);
        i--;
      } else {
        sb.erase(e);
        sb.insert(next_b);
        j--;
      }
    } else if (i >= 0) {
      sa.erase(e);
      sa.insert(a[i]);
      i--;
    } else if (j >= 0) {
      sb.erase(e);
      sb.insert(b[j]);
      j--;
    } else {
      sa.erase(e);
    }
  }

  i64 ans = 0;
  for (int e : sa) {
    ans += e;
  }
  for (int e : sb) {
    ans += e;
  }
  // cout << "ans=" << ans << endl;
  return ans;
}

void solve() {
  int n = 0, m = 0, x = 0, y = 0;
  cin >> n >> m >> x >> y;
  vector<int> a(x);
  for (int i = 0; i < x; ++i) {
    cin >> a[i];
  }
  vector<int> b(y);
  for (int i = 0; i < y; ++i) {
    cin >> b[i];
  }

  i64 ans1 = greedy(a, b, n, m);
  i64 ans2 = greedy(b, a, m, n);
  i64 ans = max(ans1, ans2);
  cout << ans << endl;
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
