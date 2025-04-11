#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int query(int i, int j) {
  cout << "? " << i << " " << j << endl;
  int result = 0;
  cin >> result;
  return result;
}

bool has_imposter(int i1, int i2) {
  int result1 = query(i1, i2);
  int result2 = query(i2, i1);
  return result1 != result2;
}

void answer(int i) {
  cout << "! " << i << endl;
}

void solve() {
  int n = 0;
  cin >> n;
  pair<int, int> candidate;
  for (int i = 1; i <= n; i += 2) {
    int i2 = i+1 > n ? 1 : i+1;
    if (has_imposter(i, i2)) {
      candidate = {i, i2};
      break;
    }
  }

  auto find_other = [&](int i1, int i2) -> int {
    for (int i = 1; i <= n; ++i) {
      if (i != i1 && i != i2) {
        return i;
      }
    }
    return -1;
  };

  int other = find_other(candidate.first, candidate.second);
  if (has_imposter(candidate.first, other)) {
    answer(candidate.first);
  } else {
    answer(candidate.second);
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
