#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> max_prime(n+1);
  for (int i = 2; i <= n; ++i) {
    if (!max_prime[i]) {
      max_prime[i] = i;
      for (int j = i+i; j <= n; j += i) {
        max_prime[j] = i;
      }
    }
  }

  map<int, vector<int>> by_prime;
  for (int i = 2; i <= n; ++i) {
    by_prime[max_prime[i]].push_back(i);
  }
  vector<vector<int>> group;
  for (auto [p, values] : by_prime) {
    group.push_back(values);
  }
  vector<int> single = {1};
  for (vector<int>& g : group) {
    if (g.size() == 1) {
      single.push_back(g[0]);
    }
  }

  vector<int> ans;
  for (vector<int>& g : group) {
    int size = g.size();
    if (size > 1) {
      if (size >= 4) {
        vector<int> chain;
        for (int i = 0; i < size; ++i) {
          chain.push_back(g[i]);
          if ((i+1) % 2 == 0 && i+2 < size && !single.empty()) {
            chain.push_back(single.back());
            single.pop_back();
          }
        }
        ans.insert(ans.end(), chain.begin(), chain.end());
      } else {
        ans.insert(ans.end(), g.begin(), g.end());
      }
    }
  }

  while (!single.empty()) {
    ans.push_back(single.back());
    single.pop_back();
  }

  for (int pi : ans) {
    cout << pi << " ";
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
