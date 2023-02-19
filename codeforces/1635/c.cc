#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool solve(vector<int>& a, vector<vector<int>>& indices) {
  int n = a.size();
  vector<int> largest(n);
  for (int i = n-1, index = n-1, value = numeric_limits<int>::min(); i >= 0; --i) {
    if (a[i] > value) {
      index = i;
      value = a[i];
    }
    largest[i] = index;
  }

  vector<tuple<ll,int,int>> best(n);
  best.back() = {numeric_limits<ll>::max(), n, n};
  map<int, int> m;
  m[a.back()] = n-1;
  for (int i = n-2; i >= 0; --i) {
    m[a[i]] = i;
    ll smallest = m.begin()->first;
    int smallest_index = m.begin()->second;
    if (smallest_index + 1 < n) {
      ll largest_index = largest[smallest_index+1];
      ll b = smallest - a[largest_index];
      best[i] = {b, smallest_index, largest_index};
    }
  }

  for (int i = n-2; i >= 0; --i) {
    if (a[i] > a[i+1]) {
      auto [b, i1, i2] = best[i+1];
      // cout << "checking" << b << ", " << i1 << ", " << i2 << endl;
      if (b > a[i+1]) return false;
      a[i] = b;
      indices.push_back({i+1, i1+1, i2+1});
    }
  }
  reverse(indices.begin(), indices.end());
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<int>> indices;
    bool result = solve(a, indices);
    if (result) {
      cout << indices.size() << '\n';
      for (vector<int>& idx : indices) {
        cout << idx[0] << ' ' << idx[1] << ' ' << idx[2] << '\n';
      }
    } else {
      cout << -1 << '\n';
    }
  }
  cout << flush;
  return 0;
}
