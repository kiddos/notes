#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> p10 = {0, 1, 10, 100, 1000, 10000, 100000, 1000000, 1000000};

void solve() {
  int A = 0, B = 0, C = 0;
  i64 k = 0;
  cin >> A >> B >> C >> k;
  int low_a = p10[A], high_a = p10[A+1]-1;
  int low_b = p10[B], high_b = p10[B+1]-1;
  int low_c = p10[C], high_c = p10[C+1]-1;
  for (int a = low_a; a <= high_a; ++a) {
    int largest_b = min(high_c - a, high_b);
    int smallest_b = max(low_c - a, low_b);
    if (largest_b >= smallest_b) {
      int count = largest_b - smallest_b + 1;
      if (k <= count) {
        int b = smallest_b + k - 1;
        int c = a + b;
        cout << a << " + " << b << " = " << c << endl;
        return;
      } else {
        k -= count;
      }
    }
  }
  cout << "-1" << endl;
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
