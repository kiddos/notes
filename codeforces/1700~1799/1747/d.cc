#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<i64> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<pair<int,int>> queries;
  for (int i = 0; i < q; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    queries.emplace_back(l, r);
  }

  vector<i64> xor_prefix = a;
  vector<i64> sum_prefix = a;
  vector<int> zero_prefix(n+1);
  for (int i = 1; i <= n; ++i) {
    xor_prefix[i] ^= xor_prefix[i-1];
    sum_prefix[i] += sum_prefix[i-1];
    zero_prefix[i] = (a[i] == 0 ? 1 : 0) + zero_prefix[i-1];
  }

  vector<map<i64,vector<int>>> x(2);
  for (int i = 0; i <= n; ++i) {
    x[i%2][xor_prefix[i]].push_back(i);
  }

  auto perform_query = [&](int l, int r) -> int {
    if (sum_prefix[r] - sum_prefix[l-1] == 0) {
      return 0;
    }
    int z = xor_prefix[r] ^ xor_prefix[l-1];
    if (z != 0) {
      return -1;
    }

    int len = r-l+1;
    if (len % 2 == 1) {
      return 1;
    } else {
      if (a[l] == 0 || a[r] == 0) {
        // reduce to odd length case
        return 1;
      } else {
        vector<int>& indices = x[1-(r%2)][xor_prefix[r]];
        auto it = lower_bound(indices.begin(), indices.end(), l-1);
        if (it != indices.end() && *it < r) {
          return 2;
        } else {
          return -1;
        }
      }
    }
  };

  vector<int> ans;
  for (auto [l, r] : queries) {
    int result = perform_query(l, r);
    ans.push_back(result);
  }

  for (int i = 0; i < (int)ans.size(); ++i) {
    cout << ans[i] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
