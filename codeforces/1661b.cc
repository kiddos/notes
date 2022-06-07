#include <bits/stdc++.h>

using namespace std;


int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> steps(32769, numeric_limits<int>::max());
  queue<int> q;
  q.push(32768);
  steps[32768] = 0;
  int step = 1;
  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      int num = q.front();
      q.pop();
      if (num-1 >= 0 && step < steps[num-1]) {
        steps[num-1] = step;
        q.push(num-1);
      }
      if (num % 2 == 0 && step < steps[num / 2]) {
        steps[num/2] = step;
        q.push(num / 2);
      }
      if (num % 2 == 0 && (num + 32768) / 2 < 32768 && step < steps[(num + 32768) / 2]) {
        steps[(num + 32768) / 2] = step;
        q.push((num + 32768) / 2);
      }
    }
    step++;
  }
  steps[0] = 0;

  int n = 0;
  cin >> n;
  while (n-- > 0) {
    int a = 0;
    cin >> a;
    cout << steps[a] << ' ';
  }
  cout << '\n';
  cout.flush();
  return 0;
}
