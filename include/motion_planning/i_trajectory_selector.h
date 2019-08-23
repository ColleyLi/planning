///
/// @file
///
#ifndef MOTION_PLANNING_I_TRAJECTORY_SELECTOR_H_
#define MOTION_PLANNING_I_TRAJECTORY_SELECTOR_H_
namespace motion_planning
{
class ITrajectorySelector
{
  public:
    virtual ~ITrajectorySelector() = 0;
};
}  // namespace motion_planning
#endif  /// MOTION_PLANNING_I_TRAJECTORY_SELECTOR_H_