#include <bits/stdc++.h>

using namespace std;

class LRUCache {
 public:
  LRUCache(int n) : capacity_(n) {
    for (int i = n; i >= 1; --i) {
      put(i);
    }
  }

  int put(int x) {
    if (cache_.count(x)) {
      auto p = cache_[x];
      data_.erase(p);
      data_.push_back(x);
      cache_[x] = prev(data_.end());
      return -1;
    } else {
      int to_remove = -1;
      if (data_.size() >= capacity_) {
        to_remove = data_.front();
        data_.pop_front();
        cache_.erase(to_remove);
      }

      data_.push_back(x);
      cache_[x] = prev(data_.end());
      return to_remove;
    }
  }

 private:
  int capacity_;
  map<int, list<int>::iterator> cache_;
  list<int> data_;
};

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;

  vector<int> ans(n+1, -1);
  LRUCache cache(n);
  for (int i = 0; i < m; ++i) {
    int p = 0;
    cin >> p;
    int to_remove = cache.put(p);
    if (to_remove > 0) {
      if (to_remove <= n) {
        ans[to_remove] = i+1;
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
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
