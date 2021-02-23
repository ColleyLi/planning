///
/// @file
/// @copyright Copyright (c) 2021. All Rights Reserved.
///
#ifndef PLANNING_COMMON_TIMER_CHRONO_TIMER_H
#define PLANNING_COMMON_TIMER_CHRONO_TIMER_H

#include "planning/common/i_timer.h"

namespace timer
{
/// @brief Chrono based Timer
class ChronoTimer : public ITimer
{
  public:
    /// @brief Constructor.
    ChronoTimer();

    /// @brief Start of the Timer
    void Start() override;

    /// @brief Interrupt Timer
    void Stop() override;

    /// @brief Check whether Timer has timeout (based on timeout value set)
    bool IsTimeout() const override;

    /// @brief Check whether Time is running and is not timeout.
    bool IsRunning() const override;

    /// @brief Set Timer Duration.
    void SetTimer(const std::chrono::system_clock::duration& duration) override;

  private:
    /// @brief Timer Duration
    std::chrono::system_clock::duration duration_;

    /// @brief Start timepoint
    std::chrono::system_clock::time_point start_;

    /// @brief Status on timer started
    bool is_started_;
};
}  // namespace timer

#endif  // PLANNING_COMMON_TIMER_CHRONO_TIMER_H
