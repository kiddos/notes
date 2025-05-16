#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int query(int i, int j, int k) {
  cout << "? " << i << " " << j << " " << k << endl;
  int result = 0;
  cin >> result;
  return result;
}

void answer(vector<int>& index) {
  cout << "! " << index[0] << " " << index[1] << endl;
}

array<int, 2> find_non_zero(array<int,4>& s) {
  array<int,4> result = {
    query(s[1], s[2], s[3]),
    query(s[0], s[2], s[3]),
    query(s[0], s[1], s[3]),
    query(s[0], s[1], s[2]),
  };
  array<int,4> indices = {0, 1, 2, 3};
  sort(indices.begin(), indices.end(), [&](int i1, int i2) {
    return result[i1] > result[i2];
  });
  return {indices[0], indices[1]};
}

void solve() {
  int n = 0;
  cin >> n;

  array<int,4> s = {1, 2, 3, 4};
  array<int, 2> remove = {0, 0};
  if (n % 2 == 0) {
    remove = find_non_zero(s);
    for (int i = 5; i <= n; i += 2) {
      s[remove[0]] = i;
      s[remove[1]] = i+1;
      remove = find_non_zero(s);
    }

  } else {
    remove = find_non_zero(s);
    for (int i = 5; i <= n-1; i += 2) {
      s[remove[0]] = i;
      s[remove[1]] = i+1;
      remove = find_non_zero(s);
    }
    s[remove[0]] = n;
    remove = find_non_zero(s);
  }

  vector<int> index;
  for (int k = 0; k < 4; ++k) {
    if (k != remove[0] && k != remove[1]) {
      index.push_back(s[k]);
    }
  }
  answer(index);
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
