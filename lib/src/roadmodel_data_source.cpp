///
/// @file
///

#include <motion_planning/roadmodel_data_source.h>

namespace motion_planning
{
RoadModelDataSource::RoadModelDataSource() : global_lane_id_(LaneInformation::GlobalLaneId::kCenter) {}
RoadModelDataSource::RoadModelDataSource(const LaneInformation::GlobalLaneId& lane_id,
                                         const VehicleDynamics& vehicle_dynamics,
                                         const std::vector<MapCoordinates>& map_coords,
                                         const PreviousPathGlobal& previous_path_global,
                                         const SensorFusion& sensor_fusion)
    : global_lane_id_(lane_id),
      vehicle_dynamics_(vehicle_dynamics),
      map_coordinates_(map_coords),
      previous_path_global_(previous_path_global)
{
}
// void RoadModelDataSource::SetGlobalLaneId(const LaneInformation::GlobalLaneId& global_lane_id)
// {
//     global_lane_id_ = global_lane_id;
// };

void RoadModelDataSource::SetVehicleDynamics(const VehicleDynamics& vehicle_dynamics)
{
    vehicle_dynamics_ = vehicle_dynamics;
}
void RoadModelDataSource::SetMapCoordinates(const std::vector<MapCoordinates>& map_coordinates)
{
    map_coordinates_ = map_coordinates;
}
void RoadModelDataSource::SetPreviousPath(const std::vector<GlobalCoordinates>& previous_path_global)
{
    previous_path_global_ = previous_path_global;
}
void RoadModelDataSource::SetPreviousPathEnd(const FrenetCoordinates& frenet_coords)
{
    previous_path_end_frenet_ = frenet_coords;
}

void RoadModelDataSource::SetSensorFusion(const SensorFusion& sensor_fusion) { sensor_fusion_ = sensor_fusion; }

LaneInformation::GlobalLaneId RoadModelDataSource::GetGlobalLaneId() const
{
    const auto coords = vehicle_dynamics_.frenet_coords;
    if (coords.d > 0 && coords.d < 4)  // left lane (near to double solid lane marking)
    {
        return LaneInformation::GlobalLaneId::kLeft;
    }
    else if (coords.d > 4 && coords.d < 8)  // center lane
    {
        return LaneInformation::GlobalLaneId::kCenter;
    }
    else if (coords.d > 8 && coords.d < 12)  // right lane (near to the edge of the road)
    {
        return LaneInformation::GlobalLaneId::kRight;
    }
    else
    {
        return LaneInformation::GlobalLaneId::kInvalid;
    }
}
FrenetCoordinates RoadModelDataSource::GetPreviousPathEnd() const { return previous_path_end_frenet_; }
VehicleDynamics RoadModelDataSource::GetVehicleDynamics() const { return vehicle_dynamics_; }
std::vector<MapCoordinates> RoadModelDataSource::GetMapCoordinates() const { return map_coordinates_; }
PreviousPathGlobal RoadModelDataSource::GetPreviousPathInGlobalCoords() const { return previous_path_global_; }
SensorFusion RoadModelDataSource::GetSensorFusion() const { return sensor_fusion_; }

}  // namespace motion_planning
