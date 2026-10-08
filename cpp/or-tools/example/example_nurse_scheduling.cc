#include <vector>

#include "ortools/sat/cp_model.h"

using namespace operations_research::sat;

void SolveNurseScheduling() {
  const int num_nurses = 10;
  const int num_days = 30;
  // 0: Shift A (Day), 1: Shift B (Evening), 2: (Night)
  const int num_shifts = 3;

  // Required nurses per shift each day
  // (e.g., 1 nurse for Shift 0, 1 for Shift 1)
  std::vector<std::vector<int>> shift_requirements;
  for (int i = 0; i < num_days; ++i) {
    shift_requirements.push_back({5, 3, 2});
  }

  CpModelBuilder cp_model;

  // Decision Variables
  // shifts[n][d][s] is a boolean variable: 1 if nurse n works shift s on day d
  std::vector<std::vector<std::vector<BoolVar>>> shifts(
      num_nurses, std::vector<std::vector<BoolVar>>(
                      num_days, std::vector<BoolVar>(num_shifts)));

  for (int n = 0; n < num_nurses; ++n) {
    for (int d = 0; d < num_days; ++d) {
      for (int s = 0; s < num_shifts; ++s) {
        shifts[n][d][s] = cp_model.NewBoolVar().WithName(
            "shift_n" + std::to_string(n) + "_d" + std::to_string(d) + "_s" +
            std::to_string(s));
      }
    }
  }

  // Constraint A: Shift Coverage Requirements
  // Sum of nurses working shift s on day d must equal requirements
  for (int d = 0; d < num_days; ++d) {
    for (int s = 0; s < num_shifts; ++s) {
      LinearExpr worker_count;
      for (int n = 0; n < num_nurses; ++n) {
        worker_count += shifts[n][d][s];
      }
      cp_model.AddEquality(worker_count, shift_requirements[d][s]);
    }
  }

  // Constraint B: At most one shift per nurse per day
  for (int n = 0; n < num_nurses; ++n) {
    for (int d = 0; d < num_days; ++d) {
      LinearExpr daily_shifts;
      for (int s = 0; s < num_shifts; ++s) {
        daily_shifts += shifts[n][d][s];
      }
      cp_model.AddAtMostOne({shifts[n][d][0], shifts[n][d][1]});
    }
  }

  // Constraint C: Rest Rule — No back-to-back Night (s=1) to Day (s=0)
  // transition
  for (int n = 0; n < num_nurses; ++n) {
    for (int d = 0; d < num_days - 1; ++d) {
      // Cannot work Night on day d AND Day on day d+1
      cp_model.AddBoolOr({shifts[n][d][1].Not(), shifts[n][d + 1][0].Not()});
    }
  }

  // Soft Constraints / Objective Optimization
  // Goal: Evenly distribute shifts so no single nurse gets overloaded.
  // Minimize the sum of squared shift counts per nurse (Fairness Objective)
  LinearExpr objective;
  for (int n = 0; n < num_nurses; ++n) {
    for (int d = 0; d < num_days; ++d) {
      for (int s = 0; s < num_shifts; ++s) {
        // Night shifts (s=1) add a higher penalty cost weight
        int weight = (s == 1) ? 3 : 1;
        objective += shifts[n][d][s] * weight;
      }
    }
  }
  cp_model.Minimize(objective);

  // Solve via CP-SAT Engine
  const CpSolverResponse response = Solve(cp_model.Build());

  if (response.status() == CpSolverStatus::OPTIMAL ||
      response.status() == CpSolverStatus::FEASIBLE) {
    std::cout << "Solution Found! Status: "
              << CpSolverStatus_Name(response.status()) << "\n\n";

    for (int d = 0; d < num_days; ++d) {
      std::cout << "--- Day " << d + 1 << " ---\n";
      for (int s = 0; s < num_shifts; ++s) {
        std::string shift_name = (s == 0) ? "Day Shift  " : "Night Shift";
        std::cout << "  " << shift_name << ": ";
        for (int n = 0; n < num_nurses; ++n) {
          if (SolutionBooleanValue(response, shifts[n][d][s])) {
            std::cout << "Nurse " << n << " ";
          }
        }
        std::cout << "\n";
      }
    }
  } else {
    std::cout << "No feasible solution found.\n";
  }
}

int main(void) {
  SolveNurseScheduling();
  return 0;
}
