#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> suffix_min = a;
  for (int i = n-2; i >= 0; --i) {
    suffix_min[i] = min(suffix_min[i], suffix_min[i+1]);
  }

  vector<int> ans;
  multiset<int> s;
  for (int i = 0; i < n; ++i) {
    if (!s.empty() && suffix_min[i] > *s.begin()) {
      for (int j = i; j < n; ++j) {
        s.insert(a[j]+1);
      }
      break;
    }
    if (a[i] == suffix_min[i]) {
      ans.push_back(a[i]);
    } else {
      s.insert(a[i]+1);
    }
  }

  for (int x : s) {
    ans.push_back(x);
  }
  for (int x : ans) {
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
