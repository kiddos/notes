#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  vector<string> months = {"January",   "February", "March",    "April",
                           "May",       "June",     "July",     "August",
                           "September", "October",  "November", "December"};
  string month;
  cin >> month;
  int k = 0;
  cin >> k;

  auto it = find(months.begin(), months.end(), month);
  int index = it - months.begin();
  int new_index = (index + k) % 12;
  cout << months[new_index] << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
