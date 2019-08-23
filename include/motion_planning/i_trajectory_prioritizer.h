///
/// @file
///
#ifndef MOTION_PLANNING_I_TRAJECTORY_PRIORITIZER_H_
#define MOTION_PLANNING_I_TRAJECTORY_PRIORITIZER_H_
namespace motion_planning
{
class ITrajectoryPrioritizer
{
  public:
    virtual ~ITrajectoryPrioritizer() = 0;
};
}  // namespace motion_planning
#endif  /// MOTION_PLANNING_I_TRAJECTORY_PRIORITIZER_H_