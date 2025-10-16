#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 1~9 9
// 10~99 90 * 2 
// 100~999 900 * 3
// 1000~9999 9000 * 4
// ...

vector<i64> c = {0};
vector<i64> pc;
vector<i64> start = {0};

void precompute() {
  i64 p10 = 1;
  for (int i = 1; i <= 18; ++i) {
    start.push_back(p10);
    i64 next_p10 = p10 * 10;
    c.push_back((next_p10 - p10) * i);
    p10 = next_p10;
  }
  pc = c;
  for (int i = 1; i <= 18; ++i) {
    pc[i] += pc[i-1];
  }
}

void solve() {
  i64 n = 0;
  cin >> n;
  int l = 0, r = pc.size()-1;
  int pi = 0;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (pc[mid] < n) {
      l = mid + 1;
      pi = mid;
    } else {
      r = mid - 1;
    }
  }

  n--;
  n -= pc[pi];
  pi++;
  i64 num = start[pi] + n / pi;
  string digits = to_string(num);
  int index = n % pi;
  cout << digits[index] << endl;
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
