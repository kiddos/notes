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

  int group_count = 0;
  map<int, vector<int>> indices;
  for (int i = 0; i < n; ++i) {
    indices[a[i]].push_back(i);
    group_count = max(group_count, (int)indices[a[i]].size());
  }

  for (int g = 0; g < group_count; ++g) {
    vector<int> list;
    vector<int> to_remove;
    for (auto& [ai, idx] : indices) {
      list.push_back(idx.back());
      idx.pop_back();
      if (idx.empty()) {
        to_remove.push_back(ai);
      }
    }
    for (int ai : to_remove) {
      indices.erase(ai);
    }

    int size = list.size();
    int first = a[list[0]];
    for (int i = 1; i < size; ++i) {
      int i1 = list[i], i2 = list[i-1];
      a[i2] = a[i1];
    }
    a[list.back()] = first;
  }

  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
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
