///
/// @file
/// @copyright Copyright (c) 2021. All Rights Reserved.
///
#ifndef PLANNING_DATATYPES_VEHICLE_DYNAMICS_H
#define PLANNING_DATATYPES_VEHICLE_DYNAMICS_H

#include "planning/datatypes/lane.h"

#include <units.h>

#include <cstdint>
#include <vector>

namespace planning
{
/// @brief Global Coordinates
struct GlobalCoordinates
{
    /// @brief x axis value
    double x;

    /// @brief y axis value
    double y;
};

/// @brief List of Previous Path Nodes in Global Coordinates
using PreviousPathGlobal = std::vector<GlobalCoordinates>;

/// @brief Frenet Coordinates
struct FrenetCoordinates
{
    /// @brief Longitudinal Value
    double s;

    /// @brief Latitudinal Value
    double d;

    /// @brief Latitudinal unit normal vector (x component)
    /// @note used to store map waypoints
    double dx{0.0};

    /// @brief Latitudinal unit normal vector (y component)
    /// @note used to store map waypoints
    double dy{0.0};
};

/// @brief List of Previous Path Nodes in Frenet Coordinates
using PreviousPathFrenet = std::vector<FrenetCoordinates>;

/// @brief Map Points
struct MapCoordinates
{
    /// @brief Map Point (Global Coordinates)
    GlobalCoordinates global_coords;

    /// @brief Map Point (Frenet Coordinates)
    FrenetCoordinates frenet_coords;
};

/// @brief List of Map Coordinates
using MapCoordinatesList = std::vector<MapCoordinates>;

/// @brief VehicleDynamics (Ego Vehicle localization information)
struct VehicleDynamics
{
    /// @brief Current Velocity
    units::velocity::meters_per_second_t velocity;

    /// @brief Current Position (Global Coordinates)
    GlobalCoordinates global_coords;

    /// @brief Current Position (Frenet Coordinates)
    FrenetCoordinates frenet_coords;

    /// @brief Current Yaw for Ego Vehicle
    units::angle::radian_t yaw;
};

/// @brief String Stream for Global Coordinates information (used for printing verbose information)
inline std::ostream& operator<<(std::ostream& out, const GlobalCoordinates& global_coords)
{
    return out << "GlobalCoordinates{x: " << global_coords.x << ", y: " << global_coords.y << "}";
}

/// @brief String Stream for Frenet Coordinates information (used for printing verbose information)
inline std::ostream& operator<<(std::ostream& out, const FrenetCoordinates& frenet_coords)
{
    return out << "FrenetCoordinates{s: " << frenet_coords.s << ", d: " << frenet_coords.d
               << ", dx: " << frenet_coords.dx << ", dy: " << frenet_coords.dy << "}";
}

/// @brief String Stream for VehicleDynamics information (used for printing verbose information)
inline std::ostream& operator<<(std::ostream& out, const VehicleDynamics& vehicle_dynamics)
{
    return out << "VehicleDynamics{" << vehicle_dynamics.global_coords << ", " << vehicle_dynamics.frenet_coords
               << ", velocity: " << vehicle_dynamics.velocity << ", yaw: " << vehicle_dynamics.yaw << "}";
}
}  // namespace planning

#endif  /// PLANNING_DATATYPES_LANE_H
