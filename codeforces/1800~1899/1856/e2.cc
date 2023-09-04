#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 1e6;

template <int L = 8>
int subset_sum(vector<int>& a, int sum) {
  if (sum == 0) return 0;

  if (sum >= L) {
    return subset_sum<min(L*2, MAX_N)>(a, sum);
  }

  map<int,int> freq;
  for (int x : a) freq[x]++;

  // this optimization is important
  int largest = freq.rbegin()->first;
  if (largest * 2 >= sum) return largest;

  vector<int> b;
  for (auto& [x, count] : freq) {
    int y = count;
    for (int bit = 1; bit < y; bit <<= 1) {
      b.push_back(bit * x);
      y -= bit;
    }

    b.push_back(y * x);
  }

  bitset<L> dp;
  dp[0] = 1;
  for (int x : b) {
    dp = dp | dp << x;
  }

  int x = sum;
  int ans = 0;
  for (int i = 0; i <= sum; ++i) {
    if (dp[i] && abs(i - (sum-i)) < x) {
      ans = i;
      x = abs(i - (sum-i));
    }
  }
  return ans;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> parent(n+1, -1);
  for (int i = 2; i <= n; ++i) cin >> parent[i];

  vector<vector<int>> adj(n+1);
  for (int i = 2; i <= n; ++i) {
    adj[parent[i]].push_back(i);
  }

  i64 ans = 0;
  function<int(int,int)> dfs = [&](int node, int p) -> int {
    vector<int> counts;
    for (int next_node : adj[node]) if (next_node != p) {
      counts.push_back(dfs(next_node, node));
    }
    i64 total = accumulate(counts.begin(), counts.end(), 0LL);

    i64 ss = subset_sum(counts, total);
    ans += ss * (total - ss);
    return total + 1;
  };

  dfs(1, -1);

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
