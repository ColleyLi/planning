///
/// @file
/// @copyright Copyright (c) 2021. All Rights Reserved.
///
#include "planning/motion_planning/data_source.h"

namespace planning
{
using namespace units::literals;

constexpr units::velocity::meters_per_second_t kDefaultSpeedLimit{48.5_mph};

namespace
{
/// @brief Validate value to be in given bounds (exclusively)
///
/// @tparam value type
///
/// @return True if given value is inside the provided bounds (exclusively), otherwise False.
template <typename T>
inline constexpr bool IsInRangeExclusive(const T& value, const T& lower, const T& upper) noexcept
{
    return ((value > lower) && (value < upper));
}

}  // namespace

DataSource::DataSource()
    : vehicle_dynamics_{},
      map_coordinates_{},
      previous_path_global_{},
      previous_path_end_frenet_{},
      sensor_fusion_{},
      speed_limit_{kDefaultSpeedLimit}
{
}

void DataSource::SetVehicleDynamics(const VehicleDynamics& vehicle_dynamics)
{
    vehicle_dynamics_ = vehicle_dynamics;
}

void DataSource::SetMapCoordinates(const MapCoordinatesList& map_coordinates)
{
    map_coordinates_ = map_coordinates;
}

void DataSource::SetPreviousPath(const PreviousPathGlobal& previous_path_global)
{
    previous_path_global_ = previous_path_global;
}

void DataSource::SetPreviousPathEnd(const FrenetCoordinates& coords)
{
    previous_path_end_frenet_ = coords;
}

void DataSource::SetSensorFusion(const SensorFusion& sensor_fusion)
{
    sensor_fusion_ = sensor_fusion;
}

void DataSource::SetSpeedLimit(const units::velocity::meters_per_second_t speed_limit)
{
    speed_limit_ = speed_limit;
}

GlobalLaneId DataSource::GetGlobalLaneId(const FrenetCoordinates& coords) const
{
    GlobalLaneId global_lane_id{GlobalLaneId::kInvalid};
    if (IsLeftLane(coords))
    {
        global_lane_id = GlobalLaneId::kLeft;
    }
    else if (IsCenterLane(coords))
    {
        global_lane_id = GlobalLaneId::kCenter;
    }
    else if (IsRightLane(coords))
    {
        global_lane_id = GlobalLaneId::kRight;
    }
    else
    {
        global_lane_id = GlobalLaneId::kInvalid;
    }
    return global_lane_id;
}

GlobalLaneId DataSource::GetGlobalLaneId() const
{
    return GetGlobalLaneId(vehicle_dynamics_.frenet_coords);
}

FrenetCoordinates DataSource::GetPreviousPathEnd() const
{
    return previous_path_end_frenet_;
}

VehicleDynamics DataSource::GetVehicleDynamics() const
{
    return vehicle_dynamics_;
}

MapCoordinatesList DataSource::GetMapCoordinates() const
{
    return map_coordinates_;
}

PreviousPathGlobal DataSource::GetPreviousPathInGlobalCoords() const
{
    return previous_path_global_;
}

SensorFusion DataSource::GetSensorFusion() const
{
    return sensor_fusion_;
}

units::velocity::meters_per_second_t DataSource::GetSpeedLimit() const
{
    return speed_limit_;
}

bool DataSource::IsLeftLane(const FrenetCoordinates& coords)
{
    return IsInRangeExclusive(coords.d, 0.0, 4.0);
}

bool DataSource::IsCenterLane(const FrenetCoordinates& coords)
{
    return IsInRangeExclusive(coords.d, 4.0, 8.0);
}

bool DataSource::IsRightLane(const FrenetCoordinates& coords)
{
    return IsInRangeExclusive(coords.d, 8.0, 12.0);
}

}  // namespace planning
