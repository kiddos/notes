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

  int special_index = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i] != 1 && a[i] != -1) {
      special_index = i;
      break;
    }
  }

  auto find_max_sums = [&](int l, int r) -> pair<int,int> {
    set<int> prefix = {0};
    int pos = 0, neg = 0;
    int p = 0;
    for (int i = l; i <= r; ++i) {
      p += a[i];
      pos = max(pos, p - *prefix.begin());
      neg = min(neg, p - *prefix.rbegin());
      prefix.insert(p);
    }
    return {pos, -neg};
  };

  vector<int> ans;
  if (special_index < 0) {
    auto [pos, neg] = find_max_sums(0, n-1);
    for (int i = -neg; i <= pos; ++i) {
      ans.push_back(i);
    }
  } else{
    auto [p1, n1] = find_max_sums(0, special_index-1);
    auto [p2, n2] = find_max_sums(special_index+1, n-1);
    int pos = max(p1, p2), neg = max(n1, n2);
    for (int i = -neg; i <= pos; ++i) {
      ans.push_back(i);
    }

    i64 sum = 0;
    i64 min_val1 = 0, max_val1 = 0;
    for (int i = special_index-1; i >= 0; --i) {
      sum += a[i];
      max_val1 = max(max_val1, sum);
      min_val1 = min(min_val1, sum);
    }

    sum = 0;
    i64 min_val2 = 0, max_val2 = 0;
    for (int i = special_index+1; i < n; ++i) {
      sum += a[i];
      max_val2 = max(max_val2, sum);
      min_val2 = min(min_val2, sum);
    }
    i64 min_val = a[special_index] + min_val1 + min_val2;
    i64 max_val = a[special_index] + max_val1 + max_val2;
    // cout << "minval=" << min_val << "max_val=" << max_val << endl;
    for (i64 x = min_val; x <= max_val; ++x) {
      ans.push_back(x);
    }
  }
  sort(ans.begin(), ans.end());
  ans.resize(unique(ans.begin(), ans.end()) - ans.begin());

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
