#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = (2<<20);
vector<bool> is_prime(MAX_N, true);
vector<int> colors(MAX_N, 1);

void precompute() {
  is_prime[1] = false;
  for (int i = 2; i < MAX_N; ++i) {
    if (is_prime[i]) {
      for (int j = i+i; j < MAX_N; j += i) {
        is_prime[j] = false;
      }
    }
  }

  for (int i = 2; i < MAX_N; ++i) {
    for (int j = i-1; j >= 1; --j) {
      if (is_prime[i ^ j]) {
        colors[i] = colors[j] + 1;
        break;
      }
    }
  }
}

void solve() {
  int n = 0;
  cin >> n;

  if (n == 1) {
    cout << "1" << endl;
    cout << "1" << endl;
  } else if (n == 2) {
    cout << "2" << endl;
    cout << "1 2" << endl;
  } else if (n == 3) {
    cout << "2" << endl;
    cout << "1 2 2" << endl;
  } else if (n == 4) {
    cout << "3" << endl;
    cout << "1 2 2 3" << endl;
  } else if (n == 5) {
    cout << "3" << endl;
    cout << "1 2 2 3 3" << endl;
  } else {
    cout << "4" << endl;
    int color = 2;
    for (int i = 1; i <= n; ++i) {
      cout << color << " ";
      color++;
      if (color > 4) {
        color = 1;
      }
    }
    cout << endl;
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
