///
/// @file
/// @brief Contains Argument Parser Interface class
/// @copyright Copyright (c) 2021. All Rights Reserved.
///
#ifndef PLANNING_COMMON_ARGUMENT_PARSER_I_ARGUMENT_PARSER_H
#define PLANNING_COMMON_ARGUMENT_PARSER_I_ARGUMENT_PARSER_H

#include "planning/common/cli_options.h"

namespace planning
{
/// @brief Argument Parser Interface class
class IArgumentParser
{
  public:
    /// @brief Destructor
    virtual ~IArgumentParser() = default;

    /// @brief Provides Parsed Arguments
    virtual CLIOptions GetParsedArgs() const = 0;

  protected:
    /// @brief Parse Arguments from argc, argv
    virtual CLIOptions ParseArgs(int argc, char** argv) = 0;
};
}  // namespace planning

#endif  /// PLANNING_COMMON_ARGUMENT_PARSER_I_ARGUMENT_PARSER_H
