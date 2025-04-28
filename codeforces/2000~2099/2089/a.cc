#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 100000;
vector<bool> is_prime(MAX_N+1, true);
vector<int> primes;

void precompute() {
  for (int i = 2; i <= MAX_N; ++i) {
    if (is_prime[i]) {
      for (int j = i+i; j <= MAX_N; j += i) {
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

void solve() {
  int n = 0;
  cin >> n;
  set<int> p;
  for (int i = 1; i <= n; ++i) {
    p.insert(i);
  }
  vector<int> a(n);
  a[0] = 2;
  a[1] = 1;
  p.erase(2);
  p.erase(1);

  int j = 0;
  i64 sum = 3;
  for (int i = 2; i < n; ++i) {
    // (sum + p[i]) / (i+1) >= prime
    int prime = primes[j];
    i64 target = (prime-1) * (i+1) + 1 - sum;
    auto it = p.lower_bound(target);
    if (it == p.end()) {
      a[i] = *p.rbegin();
      p.erase(prev(p.end()));
    } else {
      int pi = *it;
      // cout << "pi=" << pi << endl;
      // cout << "prime=" << (pi + sum + i) / (i+1) << endl;
      if ((pi + sum + i) / (i+1) == prime) {
        a[i] = pi;
        p.erase(it);
      } else {
        j++;
        prime = primes[j];
        // cout << "next prime=" << prime << endl;
        target = (prime-1) * (i+1) + 1 - sum;
        it = p.lower_bound(target);
        if (it == p.end()) {
          a[i] = *p.begin();
          p.erase(p.begin());
        } else {
          pi = *it;
          if ((pi + sum + i) / (i+1) == prime) {
            a[i] = pi;
            p.erase(it);
          } else {
            a[i] = *p.rbegin();
            p.erase(prev(p.end()));
          }
        }
      }
    }
    sum += a[i];
  }

  vector<int> c(n);
  sum = 0;
  int count = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i];
    c[i] = (sum + i) / (i+1);
    if (is_prime[c[i]]) {
      count++;
    }
  }
  // for (int i = 0; i < n; ++i) {
  //   cout << c[i] << " ";
  // }
  // cout << endl;
  assert(count >= n/3-1);

  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
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
