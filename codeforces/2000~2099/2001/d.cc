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
  set<int> s;
  map<int, int> last_occur;
  for (int i = n-1; i >= 0; --i) {
    s.insert(a[i]);
    if (!last_occur.count(a[i])) {
      last_occur[a[i]] = i;
    }
  }

  set<pair<int,int>> max_pool, min_pool;
  vector<bool> used(n+1);
  set<int> right_bound;
  for (int i = 0; i < n; ++i) {
    right_bound.insert(last_occur[a[i]]);
  }

  auto remove_before = [&](int i) {
    while (!min_pool.empty() && (min_pool.begin()->second <= i || used[min_pool.begin()->first])) {
      min_pool.erase(min_pool.begin());
    }
    while (!max_pool.empty() && (max_pool.begin()->second <= i || used[-max_pool.begin()->first])) {
      max_pool.erase(max_pool.begin());
    }
  };

  auto add_more = [&]() {
    while (!right_bound.empty() && used[a[*right_bound.begin()]]) {
      int start = *right_bound.begin();
      right_bound.erase(right_bound.begin());
      int end = (right_bound.empty() ? n-1 : *right_bound.begin());
      for (int i = start; i <= end; ++i) {
        if (!used[a[i]]) {
          max_pool.insert({-a[i], i});
          min_pool.insert({a[i], i});
        }
      }
    }
    // cout << "right bound=";
    // for (int r : right_bound) {
    //   cout << r << " ";
    // }
    // cout << endl;
    // cout << "afteR: right bound=";
    // for (int r : right_bound) {
    //   cout << r << " ";
    // }
    // cout << endl;
  };

  for (int i = 0; i <= *right_bound.begin(); ++i) {
    max_pool.insert({-a[i], i});
    min_pool.insert({a[i], i});
  }

  int size = s.size();
  vector<int> ans;
  for (int j = 0; j < size; ++j) {
    // cout << "max pool: ";
    // for (auto& [val, idx] : max_pool) {
    //   cout << -val << ":" << idx << " ";
    // }
    // cout << endl;
    // cout << "min pool: ";
    // for (auto& [val, idx] : min_pool) {
    //   cout << val << ":" << idx << " ";
    // }
    // cout << endl;

    if (j % 2 == 0) {
      // find max
      auto [val, idx] = *max_pool.begin();
      ans.push_back(a[idx]);
      used[a[idx]] = true;
      // cout << "remove1 " << last_occur[a[idx]] << endl;
      add_more();
      remove_before(idx);
    } else {
      // find min
      auto [val, idx] = *min_pool.begin();
      ans.push_back(a[idx]);
      used[a[idx]] = true;
      // cout << "remove2 " << last_occur[a[idx]] << endl;
      add_more();
      remove_before(idx);
    }
  }

  cout << ans.size() << endl;
  for (int i = 0; i < (int) ans.size(); ++i) {
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
