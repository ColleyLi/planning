///
/// @file
/// @copyright Copyright (c) 2021. All Rights Reserved.
///
#ifndef PLANNING_MOTION_PLANNING_VELOCITY_PLANNER_H
#define PLANNING_MOTION_PLANNING_VELOCITY_PLANNER_H

#include "planning/motion_planning/data_source.h"
#include "planning/motion_planning/i_velocity_planner.h"

#include <units.h>

#include <algorithm>
#include <iterator>
#include <memory>

namespace planning
{
/// @brief Velocity Planner
class VelocityPlanner : public IVelocityPlanner
{
  public:
    /// @brief Constructor. Initialize with DataSource.
    explicit VelocityPlanner(const IDataSource& data_source);

    /// @brief Constructor. Initialize with DataSource for given target velocity.
    explicit VelocityPlanner(const IDataSource& data_source,
                             const units::velocity::meters_per_second_t& target_velocity);

    /// @brief Calculate Target Velocity based on DataSource.
    void CalculateTargetVelocity() override;

    /// @brief Get calculated target velocity.
    units::velocity::meters_per_second_t GetTargetVelocity() const override;

  private:
    /// @brief Validate if vehicle/object in front (in same lane) within safe distance?
    bool IsClosestInPathVehicleInFront(const ObjectFusion& object_fusion) const;

    /// @brief Get Delta Velocity between Ego and Object Velocity.
    units::velocity::meters_per_second_t GetDeltaVelocity() const;

    /// @brief Vehicle Dynamics Refresh rate
    const units::frequency::hertz_t frequency_;

    /// @brief Jerk free deceleration rate
    const units::acceleration::meters_per_second_squared_t deceleration_;

    /// @brief Jerk free acceleration rate
    const units::acceleration::meters_per_second_squared_t acceleration_;

    /// @brief Target Velocity
    units::velocity::meters_per_second_t target_velocity_;

    /// @brief DataSource (contains information on VehicleDynamics, SensorFusion, Map Points etc.)
    const IDataSource& data_source_;
};
}  // namespace planning

#endif  // PLANNING_MOTION_PLANNING_VELOCITY_PLANNER_H
