///
/// @file trajectory_evaluator.h
/// @copyright Copyright (c) 2020. All Rights Reserved.
///
#ifndef MOTION_PLANNING_TRAJECTORY_EVALUATOR_H_
#define MOTION_PLANNING_TRAJECTORY_EVALUATOR_H_

#include <algorithm>
#include <memory>

#include "motion_planning/domain_model/sensor_fusion.h"
#include "motion_planning/i_data_source.h"
#include "motion_planning/i_trajectory_evaluator.h"
#include "motion_planning/lane_evaluator/lane_evaluator.h"

namespace motion_planning
{
/// @brief Trajectory Evaluator
class TrajectoryEvaluator : public ITrajectoryEvaluator
{
  public:
    /// @brief Constructor. Initializes with provided DataSource
    explicit TrajectoryEvaluator(std::shared_ptr<IDataSource>& data_source);

    /// @brief Get Rated Trajectories for provided optimized trajectories.
    virtual Trajectories GetRatedTrajectories(const Trajectories& optimized_trajectories) const override;

  private:
    /// @brief Lane Evaluator
    std::unique_ptr<LaneEvaluator> lane_evaluator_;
};
}  // namespace motion_planning

#endif  /// MOTION_PLANNING_TRAJECTORY_EVALUATOR_H_
