///
/// @file
///
#include "motion_planning/trajectory_prioritizer.h"
#include "logging/logging.h"

namespace motion_planning
{
template <typename T>
void PrintQueue(T q)
{
    std::stringstream log_stream;
    log_stream << "Prioritized trajectories: " << q.size() << std::endl;
    std::int32_t idx = 1;
    while (!q.empty())
    {
        log_stream << "  " << (idx++) << ". " << q.top() << std::endl;
        q.pop();
    }
    LOG_DEBUG("TrajectoryPrioritizer", log_stream.str());
}

PrioritizedTrajectories TrajectoryPrioritizer::GetPrioritizedTrajectories(const PlannedTrajectories& trajectories) const
{
    PrioritizedTrajectories prioritized_trajectories;
    for (auto& trajectory : trajectories)
    {
        prioritized_trajectories.push(trajectory);
    }
    PrintQueue(prioritized_trajectories);
    return prioritized_trajectories;
}

}  // namespace motion_planning
