#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> primes;
constexpr int MAX_N = 1e5;
void precompute() {
  vector<bool> is_prime(MAX_N+1, true);
  for (int i = 2; i <= MAX_N; ++i) {
    if (is_prime[i]) {
      for (int j = i+i; j <= MAX_N; j += i)  {
        is_prime[j] = false;
      }
    }
  }

  for (int i = 2; i <= MAX_N; ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }
}

int find_largest_prime(int n) {
  auto it = upper_bound(primes.begin(), primes.end(), n);
  --it;
  return it - primes.begin();
}

void solve() {
  int n = 0;
  cin >> n;
  set<int> s;
  for (int i = 1; i <= n; ++i) {
    s.insert(i);
  }

  int idx = find_largest_prime(n);
  vector<vector<int>> groups(n+1);
  for (int i = idx; i >= 0; --i) {
    int p = primes[i];
    while (p <= n) {
      if (s.count(p)) {
        groups[primes[i]].push_back(p);
        s.erase(p);
      }
      p += primes[i];
    }
  }

  vector<int> ans(n+1);
  ans[1] = 1;
  for (int g = 2; g <= n; ++g) {
    vector<int>& p = groups[g];
    int size = p.size();
    for (int i = 0; i < size; ++i) {
      int j = p[i];
      int val = p[(i+1)%size];
      ans[j] = val;
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

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
