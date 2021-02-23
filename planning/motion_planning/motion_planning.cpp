///
/// @file
/// @copyright Copyright (c) 2021. All Rights Reserved.
///
#include "planning/motion_planning/motion_planning.h"

#include "planning/common/logging.h"
#include "planning/motion_planning/maneuver.h"
#include "planning/motion_planning/maneuver_generator.h"
#include "planning/motion_planning/trajectory_evaluator.h"
#include "planning/motion_planning/trajectory_optimizer.h"
#include "planning/motion_planning/trajectory_planner.h"
#include "planning/motion_planning/trajectory_prioritizer.h"
#include "planning/motion_planning/trajectory_selector.h"
#include "planning/motion_planning/velocity_planner.h"

namespace planning
{
MotionPlanning::MotionPlanning(const IDataSource& data_source)
    : velocity_planner_{std::make_unique<VelocityPlanner>(data_source)},
      maneuver_generator_{std::make_unique<ManeuverGenerator>()},
      trajectory_planner_{std::make_unique<TrajectoryPlanner>(data_source)},
      trajectory_optimizer_{std::make_unique<TrajectoryOptimizer>(data_source)},
      trajectory_evaluator_{std::make_unique<TrajectoryEvaluator>(data_source)},
      trajectory_prioritizer_{std::make_unique<TrajectoryPrioritizer>()},
      trajectory_selector_{std::make_unique<TrajectorySelector>()},
      selected_trajectory_{}
{
}

void MotionPlanning::GenerateTrajectories()
{
    velocity_planner_->CalculateTargetVelocity();

    const auto target_velocity = velocity_planner_->GetTargetVelocity();

    const auto maneuvers = maneuver_generator_->Generate(target_velocity);

    const auto planned_trajectories = trajectory_planner_->GetPlannedTrajectories(maneuvers);

    const auto optimized_trajectories = trajectory_optimizer_->GetOptimizedTrajectories(planned_trajectories);

    const auto rated_trajectories = trajectory_evaluator_->GetRatedTrajectories(optimized_trajectories);

    const auto prioritized_trajectories = trajectory_prioritizer_->GetPrioritizedTrajectories(rated_trajectories);

    selected_trajectory_ = trajectory_selector_->GetSelectedTrajectory(prioritized_trajectories);
}

Trajectory MotionPlanning::GetSelectedTrajectory() const
{
    return selected_trajectory_;
}

}  // namespace planning
