#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 1e6 + 3;

vector<i64> f(MOD, 1);
vector<i64> inv_f(MOD, 1);

i64 power(i64 x, i64 n) {
  i64 ans = 1;
  x %= MOD;
  while (n > 0) {
    if (n % 2 == 1) {
      ans = (ans * x) % MOD;
    }
    x = (x * x) % MOD;
    n /= 2;
  }
  return ans;
}

void precompute() {
  for (int i = 1; i < MOD; ++i) {
    f[i] = f[i-1] * i;
    f[i] %= MOD;
  }

  inv_f[MOD-1] = power(f[MOD-1], MOD-2);
  for (int i = MOD - 2; i >= 0; --i) {
    inv_f[i] = inv_f[i+1] * (i+1);
    inv_f[i] %= MOD;
  }
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  vector<int> doubles(n);
  for (int i = 0; i < n; ++i) {
    int current = a[i];
    while (current*2 <= b[i]) {
      current *= 2;
      doubles[i]++;
    }
  }
  int common_double = *min_element(doubles.begin(), doubles.end());

  i64 min_ops = common_double;
  vector<vector<int>> sequences(n);
  int seq_len = 0;
  for (int i = 0; i < n; ++i) {
    int current = b[i];
    int d = common_double;
    vector<int> seq = {0};
    while (current > a[i] && d > 0) {
      if (current % 2 == 0 && current / 2 >= a[i] && d > 0) {
        current /= 2;
        d--;
        seq.push_back(0);
      } else {
        current--;
        seq.back()++;
      }
    }
    seq.back() += current - a[i];
    reverse(seq.begin(), seq.end());

    i64 sum = accumulate(seq.begin(), seq.end(), 0LL);
    min_ops += sum;

    sequences[i] = seq;
    seq_len = max(seq_len, (int)seq.size());
  }

  i64 min_count = 1;
  for (int k = 0; k < seq_len; ++k) {
    i64 sum = 0;
    for (int i = 0; i < n; ++i) {
      vector<int>& s = sequences[i];
      int add = k < (int)s.size() ? s[k] : 0;
      sum += add;
      min_count *= inv_f[add];
      min_count %= MOD;
      // cout << "inv_f[" << add << "]=" << inv_f[add] << endl;
    }
    // cout << "sum=" << sum << endl;
    // when looking for factorial of x!
    // if x >= MOD, the modular will be 0
    if (sum >= MOD) {
      min_count = 0;
      break;
    }

    min_count *= f[sum];
    min_count %= MOD;
  }

  cout << min_ops << " " << min_count << endl;
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
