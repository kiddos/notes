#include <bits/stdc++.h>

using namespace std;

using i64 = long long;


constexpr int MAX_A = 10000000;

vector<int> min_prime_div(MAX_A+1);
vector<int> prime_index(MAX_A+1);

void precompute() {
  min_prime_div[1] = 1;
  for (int i = 2; i <= MAX_A; ++i) {
    if (min_prime_div[i] == 0) {
      for (int j = i+i; j <= MAX_A; j += i) {
        if (min_prime_div[j] == 0) {
          min_prime_div[j] = i;
        }
      }
    }
  }

  for (int i = 2, idx = 1; i <= MAX_A; ++i) {
    if (min_prime_div[i] == 0) {
      prime_index[i] = idx++;
    }
  }
}

vector<int> memo(MAX_A+1, -1);
int grundy(int x) {
  if (x == 0) {
    return 0;
  }

  if (x == 1) {
    return 1;
  }

  if (x % 2 == 0) {
    return 0;
  }
  if (memo[x] >= 0) {
    return memo[x];
  }

  if (min_prime_div[x] == 0) {
    return prime_index[x];
  }
  return grundy(min_prime_div[x]);
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  // vector<int> mem(1001, -1);
  // auto grundy = [&](const auto& self, int x) -> int {
  //   if (x == 0) {
  //     return 0;
  //   }
  //   if (mem[x] >= 0) {
  //     return mem[x];
  //   }
  //
  //   vector<int> s;
  //   for (int y = 1; y <= x; ++y) {
  //     if (gcd(y, x) == 1) {
  //       s.push_back(self(self, x - y));
  //     }
  //   }
  //
  //   set<int> mex;
  //   for (int j = 0; j <= x; ++j) {
  //     mex.insert(j);
  //   }
  //   for (int si : s) {
  //     mex.erase(si);
  //   }
  //   // cout << "i=" << i << ",x=" << x << ": ";
  //   // for (int si : s) {
  //   //   cout << si << " ";
  //   // }
  //   // cout << endl;
  //   // cout << "mex=" << *mex.begin() << endl;
  //   return mem[x] = *mex.begin();
  // };
  //
  // for (int x = 1; x <= 1000; ++x) {
  //   int g = grundy(grundy, x);
  //   cout << "x=" << x << ",g=" << g << endl;
  // }
  // cout << endl;

  // for (int x = 1; x <= 1000; ++x) {
  //   cout << "x=" << x << ",g=" << grundy(x) << endl;
  // }
  // cout << endl;

  int nim_total = 0;
  for (int i = 0; i < n; ++i) {
    // nim_total ^= grundy(grundy, a[i]);
    nim_total ^= grundy(a[i]);
  }

  if (nim_total == 0) {
    cout << "Bob" << endl;
  } else {
    cout << "Alice" << endl;
  }
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
