#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  sort(a.rbegin(), a.rend());

  map<int,vector<int>> indices;
  for (int i = 0; i < n; ++i) {
    vector<int> divs;
    for (int d = 1; d*d <= a[i]; ++d) {
      if (a[i] % d == 0) {
        divs.push_back(d);
        divs.push_back(a[i] / d);
      }
    }
    sort(divs.begin(), divs.end());
    divs.resize(unique(divs.begin(), divs.end()) - divs.begin());
    for (int d : divs) {
      indices[d].push_back(i);
    }
  }

  int min_a = a[0], max_a = a[0];
  for (int i = 1; i < n; ++i) {
    min_a &= a[i];
    max_a = max(max_a, a[i]);
  }

  constexpr int MAX_BIT = 20;
  vector<int> all_bits(MAX_BIT);
  for (int i = 0; i < n; ++i) {
    for (int b = 0; b < MAX_BIT; ++b) if (a[i] & (1<<b)) {
      all_bits[b]++;
    }
  }

  auto compute_and = [&](int p, int q) -> int {
    vector<int> bits = all_bits;
    for (int b = 0; b < MAX_BIT; ++b) {
      if (p & (1<<b)) bits[b]--;
      if (q & (1<<b)) bits[b]--;
    }
    int ans = 0;
    for (int b = 0; b < MAX_BIT; ++b) {
      if (bits[b] == n-2) {
        ans |= (1<<b);
      }
    }
    return ans;
  };

  auto answer_yes = [&](int p, int q) {
    cout << "YES" << endl;
    cout << 2 << " " << a[p] << " " << a[q] << endl;

    cout << n-2 << " ";
    for (int i = 0; i < n; ++i) if (i != p && i != q) {
      cout << a[i] << " ";
    }
    cout << endl;
  };

  for (int g = min_a+x+1; g <= max_a; ++g) {
    if (!indices.count(g)) continue;
    // cout << "g0 = " << g0 << endl;

    vector<int>& idx = indices[g];
    for (int i = 0; i < (int)idx.size(); ++i) {
      for (int j = i+1; j < (int)idx.size(); ++j) {
        int p = idx[i], q = idx[j];
        int and_val = compute_and(a[p], a[q]);
        // cout << a[i] << ", " << a[j] << ", and=" << and_val << endl;
        if (g > and_val + x) {
          answer_yes(p, q);
          return;
        }
      }
    }
  }

  cout << "NO" << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}