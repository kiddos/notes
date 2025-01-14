#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int compute_min_diff(vector<int>& a, vector<int>& b, int n) {
  vector<pair<int,int>> stores;
  for (int i = 0; i < n; ++i) {
    stores.emplace_back(a[i], b[i]);
  }

  sort(stores.begin(), stores.end(), [&](auto& s1, auto& s2) {
    if (s1.first == s2.first) {
      return s1.second > s2.second;
    }
    return s1.first < s2.first;
  });
  multiset<int> s;
  vector<int> largest_a_bs;
  for (int i = 0; i < n; ++i) {
    s.insert(stores[i].second);
    if (stores[i].first == stores.back().first) {
      largest_a_bs.push_back(stores[i].second);
    }
  }

  int largest_a = stores.back().first;
  int ans = numeric_limits<int>::max();
  for (int b1 : largest_a_bs) {
    auto it = s.find(b1);
    s.erase(it);
    auto l = s.lower_bound(largest_a);
    if (l != s.end()) {
      ans = min(ans, *l - largest_a);
    }
    auto u = s.upper_bound(largest_a);
    if (u != s.begin()) {
      ans = min(ans, largest_a - *(--u));
    }
    s.insert(b1);
  }

  multiset<int> s2;
  for (int i = 0; i < n; ++i) {
    s.erase(s.find(stores[i].second));
    if (!s.empty()) {
      int current_largest_b = *s.rbegin();
      int diff = abs(current_largest_b - stores[i].first);
      ans = min(ans, diff);

      auto it = s2.lower_bound(stores[i].first);
      if (it != s2.end() && *it >= current_largest_b) {
        ans = min(ans, abs(*it - stores[i].first));
      }
      it = s2.upper_bound(stores[i].first);
      if (it != s2.begin() && *(--it) >= current_largest_b) {
        ans = min(ans, abs(*it - stores[i].first));
      }
    }

    s2.insert(stores[i].second);
  }
  return ans;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }

  int ans = compute_min_diff(a, b, n);
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
