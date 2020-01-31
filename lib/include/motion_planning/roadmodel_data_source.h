///
/// @file roadmodel_data_source.h
/// @copyright Copyright (c) 2020. All Rights Reserved.
///

#ifndef MOTION_PLANNING_ROADMODEL_DATA_SOURCE_H_
#define MOTION_PLANNING_ROADMODEL_DATA_SOURCE_H_

#include "motion_planning/i_data_source.h"

namespace motion_planning
{
class RoadModelDataSource : public IDataSource
{
  public:
    RoadModelDataSource();

    virtual void SetVehicleDynamics(const VehicleDynamics& vehicle_dynamics) override;
    virtual void SetMapCoordinates(const MapCoordinatesList& map_coordinates) override;
    virtual void SetPreviousPath(const PreviousPathGlobal& previous_path_global) override;
    virtual void SetPreviousPathEnd(const FrenetCoordinates& coords) override;
    virtual void SetSensorFusion(const SensorFusion& sensor_fusion) override;
    virtual void SetSpeedLimit(const units::velocity::meters_per_second_t& speed_limit) override;

    virtual GlobalLaneId GetGlobalLaneId(const FrenetCoordinates& coords) const override;
    virtual GlobalLaneId GetGlobalLaneId() const override;
    virtual FrenetCoordinates GetPreviousPathEnd() const override;
    virtual VehicleDynamics GetVehicleDynamics() const override;
    virtual MapCoordinatesList GetMapCoordinates() const override;
    virtual PreviousPathGlobal GetPreviousPathInGlobalCoords() const override;
    virtual SensorFusion GetSensorFusion() const override;
    virtual units::velocity::meters_per_second_t GetSpeedLimit() const override;

  private:
    virtual bool IsLeftLane(const FrenetCoordinates& coords) const;
    virtual bool IsCenterLane(const FrenetCoordinates& coords) const;
    virtual bool IsRightLane(const FrenetCoordinates& coords) const;

    GlobalLaneId global_lane_id_{GlobalLaneId::kInvalid};
    VehicleDynamics vehicle_dynamics_{};
    MapCoordinatesList map_coordinates_{};
    PreviousPathGlobal previous_path_global_{};
    FrenetCoordinates previous_path_end_frenet_{};
    SensorFusion sensor_fusion_{};
    units::velocity::meters_per_second_t speed_limit_{};
};
}  // namespace motion_planning

#endif  /// MOTION_PLANNING_ROADMODEL_DATA_SOURCE_H_
