#include <bits/stdc++.h>

using namespace std;

// Single-Threaded CPU
//
// basiclly simulate the process
//
// 1. sort the task by their queue_time
// 2. push the first task into priority_queue
// 3. current time t will be max of current t and the task's queue_time
// 4. push in any task that has queue_time before current time t
// 5. execute the first task(minimum processing_time) from priority_queue
// 6. repeat until all tasks are consumed

struct Task {
  int index;
  int queue_time;
  int processing_time;
  Task(int index, int queue_time, int processing_time)
      : index(index),
        queue_time(queue_time),
        processing_time(processing_time) {}
};

struct Compare {
  bool operator()(const Task& t1, const Task& t2) {
    if (t1.processing_time == t2.processing_time) {
      return t1.index > t2.index;
    }
    return t1.processing_time > t2.processing_time;
  }
};

class Solution {
 public:
  vector<int> getOrder(vector<vector<int>>& tasks) {
    int n = tasks.size();
    vector<Task> all;
    for (int i = 0; i < n; ++i) {
      all.push_back(Task(i, tasks[i][0], tasks[i][1]));
    }

    sort(all.begin(), all.end(), [&](auto t1, auto t2) {
      if (t1.queue_time == t2.queue_time) {
        return t1.processing_time > t2.processing_time;
      }
      return t1.queue_time > t2.queue_time;
    });

    vector<int> ans;
    priority_queue<Task, vector<Task>, Compare> pq;
    long t = 0;
    while (!all.empty() || !pq.empty()) {
      if (pq.empty()) {
        t = max(t, (long)all.back().queue_time);
      }
      while (!all.empty() && all.back().queue_time <= t) {
        pq.push(all.back());
        all.pop_back();
      }

      auto task = pq.top();
      pq.pop();
      t += task.processing_time;
      ans.push_back(task.index);
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int>> tasks = {{1, 2}, {2, 4}, {3, 2}, {4, 1}};
  vector<int> ans = Solution().getOrder(tasks);
  vector<int> target = {0, 2, 3, 1};
  for (int i = 0; i < target.size(); ++i) assert(ans[i] == ans[i]);
  return 0;
}
