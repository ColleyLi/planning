///
/// @file
///

#ifndef MOTION_PLANNING_FIXTURE_H_
#define MOTION_PLANNING_FIXTURE_H_

#include <gtest/gtest.h>
#include <motion_planning/motion_planning.h>

class MotionPlanningFixture : public ::testing::Test
{
  public:
  protected:
    virtual void SetUp() override {}
    virtual void TearDown() override {}

  private:
};

#endif  /// MOTION_PLANNING_FIXTURE_H