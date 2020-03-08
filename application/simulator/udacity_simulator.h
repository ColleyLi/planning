///
/// @file udacity_simulator.h
/// @brief Contains Simulation Client Interface for Udacity Simulator
/// @copyright Copyright (c) 2020. All Rights Reserved.
///
#ifndef SIMULATOR_UDACITY_SIMULATOR_H_
#define SIMULATOR_UDACITY_SIMULATOR_H_

#include "application/simulator/i_simulator.h"
#include "planning/common/argument_parser/argument_parser.h"
#include "planning/motion_planning/motion_planning.h"
#include "planning/motion_planning/roadmodel_data_source.h"

#include <json.hpp>

#include <math.h>
#include <fstream>
#include <iomanip>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

namespace sim
{
using json = nlohmann::json;

/// @brief Simulator Client
class UdacitySimulator : public ISimulator
{
  public:
    /// @brief Constructor. Initializes Map Points from map_file
    explicit UdacitySimulator(const std::string& map_file);

    /// @brief Initialize and Register Callbacks for Connect, Receive and Disconnect
    virtual void Init() override;

    /// @brief Listen to WebSocket Port
    virtual void Listen() override;

  protected:
    /// @brief Connect callback for WebSocket
    virtual void ConnectCallback(uWS::WebSocket<uWS::SERVER> ws, uWS::HttpRequest req) override;

    /// @brief Disconnect callback for WebSocket
    virtual void DisconnectCallback(uWS::WebSocket<uWS::SERVER> ws, std::int32_t code, char* message,
                                    size_t length) override;

    /// @brief Receive callback for WebSocket
    virtual void ReceiveCallback(uWS::WebSocket<uWS::SERVER> ws, char* data, size_t length,
                                 uWS::OpCode op_code) override;

  private:
    /// @brief Extract Map Points from provided Map file
    void InitializeMap();

    /// @brief Updates DataSource from the received WebSocket Msg (json)
    void UpdateDataSource(const json& msg);

    /// @brief WebSocket Handle
    uWS::Hub h_;

    /// @brief Map Waypoints
    std::vector<planning::MapCoordinates> map_waypoints_;

    /// @brief Map File
    std::string map_file_;

    /// @brief DataSource (contains information on Vehicle Dynamics, SensorFusion, etc.)
    std::shared_ptr<planning::IDataSource> data_source_;

    /// @brief Motion Planning Instance to be used to generate Trajectory and Select optimal trajectory for ego motion
    std::unique_ptr<planning::MotionPlanning> motion_planning_;
};
}  // namespace sim

#endif  /// SIMULATOR_UDACITY_SIMULATOR_H_
