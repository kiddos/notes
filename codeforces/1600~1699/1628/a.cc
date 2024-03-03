#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int max_val = *max_element(a.begin(), a.end());
  set<int> s;
  for (int i = 0; i <= max_val+1; ++i) s.insert(i);

  vector<int> suffix(n+1);
  for (int i = n-1; i >= 0; --i) {
    s.erase(a[i]);
    suffix[i] = *s.begin();
  }

  vector<int> ans;
  int i = 0;
  while (i < n) {
    int mex = suffix[i];
    vector<int> counts(max_val+1);
    int collected = 0;
    int j = i;
    do {
      counts[a[j]]++;
      if (a[j] <= mex && counts[a[j]] == 1) {
        collected++;
      }
      j++;
    } while (j < n && collected < mex);

    i = j;
    ans.push_back(mex);
  }

  cout << ans.size() << endl;
  for (int a : ans) {
    cout << a << " ";
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
