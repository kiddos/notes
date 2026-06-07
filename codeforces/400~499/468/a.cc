#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// n = 4
// 4 * 3 * 2 * 1
// n = 5
// 5 * 4 + 3 + 2 -1
// n = 6
// 4 * 3 * 2 + 6 - 5 - 1
// n = 8
// 4 * 3 * 2 * 1 + 8 + 5 - 6 - 7
// n = 7
// 4 * 7 + 6 - 2 * 3 - 5 + 1

enum Operation {
  ADD, SUB, MUL
};

struct Entry {
  int a, b, c;
  Operation op;
};

void solve() {
  int n = 0;
  cin >> n;
  if (n < 4) {
    cout << "NO" << endl;
    return;
  }

  vector<Entry> ans;
  int mod = n % 4;
  if (mod == 0) {
    ans.push_back({4, 3, 12, MUL});
    ans.push_back({12, 2, 24, MUL});
    ans.push_back({24, 1, 24, MUL});
  } else if (mod == 1) {
    ans.push_back({5, 4, 20, MUL});
    ans.push_back({20, 3, 23, ADD});
    ans.push_back({23, 2, 25, ADD});
    ans.push_back({25, 1, 24, SUB});
  } else if (mod == 2) {
    ans.push_back({4, 3, 12, MUL});
    ans.push_back({12, 2, 24, MUL});
    ans.push_back({24, 6, 30, ADD});
    ans.push_back({30, 5, 25, SUB});
    ans.push_back({25, 1, 24, SUB});
  } else if (mod == 3) {
    ans.push_back({4, 7, 28, MUL});
    ans.push_back({28, 6, 34, ADD});
    ans.push_back({2, 3, 6, MUL});
    ans.push_back({34, 6, 28, SUB});
    ans.push_back({28, 5, 23, SUB});
    ans.push_back({23, 1, 24, ADD});
  }

  for (int k = 5 + mod; k <= n; k += 4) {
    ans.push_back({24, k, 24 + k, ADD});
    ans.push_back({24 + k, k + 3, 24 + k + k + 3, ADD});
    ans.push_back({24 + k + k + 3, k + 1, 24 + k + 2, SUB});
    ans.push_back({24 + k + 2, k + 2, 24, SUB});
  }

  cout << "YES" << endl;
  for (auto [a, b, c, op] : ans) {
    if (op == ADD) {
      cout << a << " + " << b << " = " << c << endl;
    } else if (op== SUB) {
      cout << a << " - " << b << " = " << c << endl;
    } else if (op == MUL) {
      cout << a << " * " << b << " = " << c << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
