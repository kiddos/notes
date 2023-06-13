#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int power(int x, int n, int mod) {
  int ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
      ans %= mod;
    }

    x = x * x;
    x %= mod;
    n >>= 1;
  }
  return ans;
}

void solve() {
  string s;
  cin >> s;
  
  int w = 0, m = 0;
  cin >> w >> m;

  vector<array<int, 3>> queries;
  for (int i = 0; i < m; ++i) {
    int l = 0, r = 0, k = 0;
    cin >> l >> r >> k;
    queries.push_back({l, r, k});
  }

  int n = s.length();
  vector<int> p(n);
  constexpr int mod = 9;
  for (int i = 0; i < n; ++i) {
    p[i] = (i > 0 ? p[i-1] : 0) * 10 + s[i] - '0';
    p[i] %= mod;
  }

  vector<pair<int,int>> index(9, {-1, -1});
  for (int i = w-1; i < n; ++i) {
    int val = p[i];
    if (i >= w) {
      val -= p[i-w];
      val = (val+ mod) % mod;
    }

    if (index[val].first < 0) {
      index[val].first = i-w+2;
    } else if (index[val].second < 0) {
      index[val].second = i-w+2;
    }
  }

  auto find = [&](int a, int k) -> pair<int,int> {
    vector<pair<int,int>> ans;
    for (int x = 0; x < mod; ++x) {
      for (int y = 0; y < mod; ++y) {
        int val = x * a + y;
        val %= mod;
        if (val == k) {
          if (x == y) {
            if (index[x].first > 0 && index[y].second > 0) {
              ans.emplace_back(index[x].first, index[y].second);
            }
          } else {
            if (index[x].first > 0 && index[y].first > 0) {
              ans.emplace_back(index[x].first, index[y].first);
            }
          }
        }
      }
    }
    if (ans.empty()) {
      return {-1, -1};
    }
    sort(ans.begin(), ans.end());
    return ans[0];
  };

  vector<pair<int, int>> ans;
  for (auto& [l, r, k] : queries) {
    int a = p[r-1];
    if (l >= 2) {
      a -= p[l-2];
      a = (a + mod) % mod;
    }
    ans.push_back(find(a, k));
  }

  for (auto& [L1, L2] : ans) {
    cout << L1 << " " << L2 << endl;
  }
}

// a * x + y = k

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
