#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> get_prime_factors(i64 x) {
  vector<int> f;
  for (int d = 2; d*d <= x; ++d) {
    while (x % d == 0) {
      x /= d;
      f.push_back(d);
    }
  }
  if (x > 1) {
    f.push_back(x);
  }
  sort(f.begin(), f.end());
  return f;
}

vector<int> get_factors(i64 x) {
  vector<int> f;
  for (int d = 2; d*d <= x; ++d) {
    if (x % d == 0) {
      f.push_back(x / d);
      f.push_back(d);
    }
  }
  sort(f.begin(), f.end());
  f.resize(unique(f.begin(), f.end()) - f.begin());
  return f;
}

void solve() {
  i64 x = 0, d = 0;
  cin >> x >> d;

  i64 y = x;
  int d_count = 0;
  while (y % d == 0) {
    y /= d;
    d_count ++;
  }

  if (d_count <= 1) {
    cout << "NO" << endl;
    return;
  }

  vector<int> rest = get_prime_factors(y);
  // cout << "y=" << y << endl;
  // cout << "rest size=" << rest.size() << endl;
  if (rest.size() >= 2) {
    // if y is not a prime number
    // there are at least 2 ways:
    // 1. y can be put into 1 d
    // 2. y can be divide into 2 numbers and put into 2 ds
    cout << "YES" << endl;
    return;
  }

  vector<int> d_factors = get_factors(d);
  if (d_factors.size() == 0) {
    cout << "NO" << endl;
  } else {
    if (d_count >= 4) {
      // divide 1 d into f1, and f2
      // put f1 of d for 1 d,
      // put f2 for 1 d,
      // put y for 1 d
      cout << "YES" << endl;
    } else if (d_count == 3) {
      // need to divide 1 d into 2 numbers
      // and try to distribute into the 2 ds

      // cout << "d factors: ";
      // for (int f : d_factors) {
      //   cout << f << " ";
      // }
      // cout << endl;
      for (int f1 : d_factors) {
        if ((f1 * y) % d != 0) {
          cout << "YES" << endl;
          return;
        }
      }
      cout << "NO" << endl;
    } else {
      // if there are only 2 ds
      // we cannot cut 1 d and distribute
      cout << "NO" << endl;
    }
  }
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
