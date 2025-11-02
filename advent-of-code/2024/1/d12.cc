#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string line;
  vector<int> left, right;
  while (getline(cin, line) && !line.empty()) {
    stringstream ss;
    ss << line;
    int l = 0, r = 0;
    ss >> l >> r;
    left.push_back(l);
    right.push_back(r);
  }
  assert(left.size() == right.size());

  int size = left.size();
  map<int, int> right_count;
  for (int i = 0; i < size; ++i) {
    right_count[right[i]]++;
  }

  i64 ans = 0;
  for (int i = 0; i < size; ++i) {
    i64 c = right_count.count(left[i]) ? right_count[left[i]] : 0;
    ans += c * left[i];
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
