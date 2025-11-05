#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

mt19937 gen(static_cast<unsigned int>(std::time(0)));

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> b = a;
  sort(b.begin(), b.end());
  b.resize(unique(b.begin(), b.end()) - b.begin());

  int id = 0;
  map<int,int> ids;
  for (int val : b) {
    ids[val] = id++;
  }

  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    c[i] = ids[a[i]];
  }

  vector<vector<int>> index_group(id);
  for (int i = 0; i < n; ++i) {
    index_group[c[i]].push_back(i);
  }

  auto query_count = [&](int x, int left, int right) -> int {
    vector<int>& idx = index_group[x];
    int size = idx.size();
    int l = 0, r = size-1;
    int i1 = -1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (idx[mid] >= left) {
        i1 = mid;
        r = mid-1;
      } else {
        l = mid+1;
      }
    }

    l = 0, r = size-1;
    int i2 = -1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (idx[mid] <= right) {
        i2 = mid;
        l = mid+1;
      } else {
        r = mid-1;
      }
    }
    return i2- i1+1;
  };

  vector<vector<int>> ans;
  for (int i = 0; i < q; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    l--;
    r--;

    int len = r-l+1;
    vector<int> candidates;
    int target_size = len / 3;
    for (int k = 0; k < 50; ++k) {
      int offset = gen() % len;
      int idx = offset + l;
      int x = c[idx];
      int count = query_count(x, l, r);
      if (count > target_size) {
        if (candidates.empty() || find(candidates.begin(), candidates.end(), a[idx]) == candidates.end()) {
          candidates.push_back(a[idx]);
        }
      }
    }

    if (candidates.empty()) {
      candidates.push_back(-1);
    } else {
      if (candidates.size() == 2 && candidates[0] > candidates[1]) {
        swap(candidates[0], candidates[1]);
      }
    }
    ans.push_back(candidates);
  }

  for (vector<int>& candidates : ans) {
    for (int val : candidates) {
      cout << val << " ";
    }
    cout << '\n';
  }

  cout << flush;
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
