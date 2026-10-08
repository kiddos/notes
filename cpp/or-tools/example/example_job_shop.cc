#include <ortools/sat/cp_model.h>

#include <iostream>
#include <vector>

using namespace operations_research::sat;

void SolveJobShop() {
  // 1. Data Setup (2 Jobs, 2 Machines)
  // Format: {Machine Index, Duration}
  struct TaskSpec {
    int machine;
    int duration;
  };

  // Job 0: Task 0 on Mach 0 (dur 3), then Task 1 on Mach 1 (dur 2)
  // Job 1: Task 0 on Mach 1 (dur 1), then Task 1 on Mach 0 (dur 4)
  std::vector<std::vector<TaskSpec>> jobs_data = {{{0, 3}, {1, 2}},
                                                  {{1, 1}, {0, 4}}};

  int num_jobs = jobs_data.size();
  int num_machines = 2;

  CpModelBuilder cp_model;

  // Calculate maximum possible horizon (sum of all task durations)
  int horizon = 0;
  for (const auto& job : jobs_data) {
    for (const auto& task : job) {
      horizon += task.duration;
    }
  }

  // 2. Decision Variables & Interval Creation
  std::vector<std::vector<IntervalVar>> machine_intervals(num_machines);
  std::vector<IntVar> job_ends;

  for (int job_id = 0; job_id < num_jobs; ++job_id) {
    IntVar previous_end = cp_model.NewConstant(0);

    for (int task_id = 0; task_id < jobs_data[job_id].size(); ++task_id) {
      const auto& task_spec = jobs_data[job_id][task_id];
      std::string suffix =
          "_j" + std::to_string(job_id) + "_t" + std::to_string(task_id);

      // Start, End, and Interval Variables for this task
      IntVar start =
          cp_model.NewIntVar({0, horizon}).WithName("start" + suffix);
      IntVar end = cp_model.NewIntVar({0, horizon}).WithName("end" + suffix);
      IntervalVar interval =
          cp_model.NewIntervalVar(start, task_spec.duration, end)
              .WithName("interval" + suffix);

      // Hard Constraint A: Job Precedence (Task N must start after Task N-1
      // ends)
      cp_model.AddGreaterOrEqual(start, previous_end);

      // Group intervals by machine for resource contention tracking
      machine_intervals[task_spec.machine].push_back(interval);
      previous_end = end;
    }
    job_ends.push_back(previous_end);
  }

  // 3. Machine Disjunctive Constraints
  // Hard Constraint B: No two tasks can overlap on the same machine
  for (int m = 0; m < num_machines; ++m) {
    cp_model.AddNoOverlap(machine_intervals[m]);
  }

  // 4. Objective: Minimize Makespan
  IntVar makespan = cp_model.NewIntVar({0, horizon}).WithName("makespan");
  cp_model.AddMaxEquality(makespan, job_ends);
  cp_model.Minimize(makespan);

  // 5. Solve via CP-SAT Engine
  const CpSolverResponse response = Solve(cp_model.Build());

  if (response.status() == CpSolverStatus::OPTIMAL ||
      response.status() == CpSolverStatus::FEASIBLE) {
    std::cout << "Solution Found! Optimal Makespan: "
              << response.objective_value() << "\n\n";

    for (int job_id = 0; job_id < num_jobs; ++job_id) {
      std::cout << "Job " << job_id << " completed at time: "
                << SolutionIntegerValue(response, job_ends[job_id]) << "\n";
    }
  } else {
    std::cout << "No solution found.\n";
  }
}

int main() {
  SolveJobShop();
  return 0;
}
