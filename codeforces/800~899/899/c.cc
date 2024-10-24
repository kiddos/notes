#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  vector<int> first, second;
  if (n % 2 == 1) {
    int r = n, l = 2;
    while (r-l+1 >= 4) {
      first.push_back(r--);
      first.push_back(l++);
      second.push_back(r--);
      second.push_back(l++);
    }
    if (l < r) {
      first.push_back(r--);
      second.push_back(l++);
    }
    second.push_back(1);
  } else {
    int r = n, l = 1;
    while (r-l+1 >= 4) {
      first.push_back(r--);
      first.push_back(l++);
      second.push_back(r--);
      second.push_back(l++);
    }
    if (l < r) {
      first.push_back(r--);
      second.push_back(l++);
    }
  }

  i64 x = accumulate(first.begin(), first.end(), 0LL);
  i64 y = accumulate(second.begin(), second.end(), 0LL);
  i64 diff = abs(x - y);
  cout << diff << endl;
  cout << first.size() << " ";
  for (int z : first) {
    cout << z << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
