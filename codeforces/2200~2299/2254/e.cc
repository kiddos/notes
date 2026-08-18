#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  i64 sum = accumulate(b.begin(), b.end(), 0LL);
  if (sum <= 0) {
    cout << "-1" << endl;
    return;
  }

  vector<i64> pos;
  multiset<i64> neg;
  for (int i = 0; i < n; ++i) {
    if (b[i] > 0) {
      pos.push_back(b[i]);
    } else {
      neg.insert(b[i]);
    }
  }
  sort(pos.begin(), pos.end());

  i64 current_val = 0;
  vector<i64> ans;
  for (i64 pos_change : pos) {
    current_val += pos_change;
    ans.push_back(current_val);

    while (!neg.empty()) {
      auto it = neg.upper_bound(-current_val);
      if (it == neg.end()) {
        break;
      }
      current_val += *it;
      ans.push_back(current_val);
      neg.erase(it);
    }
  }

  if ((int)ans.size() != n) {
    cout << "-1" << endl;
    return;
  }

  for (int i = 0; i < n; ++i) {
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
