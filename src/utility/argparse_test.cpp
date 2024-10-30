/*
 * Copyright (c) 2024 Nomen Aliud (aka Arnab Bose)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "argparse.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_exception.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

// Affirms exact equality of exception message.
using Catch::Matchers::Message;
// Checks exception message with a string matcher.
using Catch::Matchers::MessageMatches;

// Helper to call parse, with the correct argc count.
void CallParse(ArgumentParser& parser, const std::vector<std::string> args) {
  // Create an array of const char* and initialize it from the std::vector
  std::vector<const char*> argv(args.size() + 1);  // +1 for NULL terminator

  for (std::size_t i = 0; i < args.size(); ++i) {
    argv[i] = args[i].c_str();  // Use .c_str() to get const char*
  }

  argv[args.size()] = nullptr;  // Set last element to NULL

  // Simulating argc.
  int argc = static_cast<int>(args.size());

  parser.Parse(argc, argv.data());
}

SCENARIO("Exception on unknown arg") {
  ArgumentParser parser;
  parser.AddBool("help", "Show help.");
  CHECK_THROWS_AS(CallParse(parser, {"COMMAND", "--argname1", "argvalue1"}),
                  std::invalid_argument);
}

SCENARIO("Incomplete argument") {
  ArgumentParser parser;
  parser.AddString("name", "This argument must have a value.");

  THEN("End without specifying value") {
    CHECK_THROWS_MATCHES(
        CallParse(parser, {"COMMAND", "--name"}), std::invalid_argument,
        Catch::Matchers::Message("Value of argument not found: name"));
  }

  THEN("Another argument without specifying value") {
    CHECK_THROWS_MATCHES(
        CallParse(parser, {"COMMAND", "--name", "--help"}),
        std::invalid_argument,
        Catch::Matchers::Message("Expecting value for name but found --help"));
  }
}

SCENARIO("Correctness of argument parsing") {
  ArgumentParser parser;
  parser.AddString("name", "Add a name.");
  parser.AddBool("help", "Show help.");

  THEN("No argument") {
    CallParse(parser, {"COMMAND"});
    CHECK_FALSE(parser.GetBool("help"));
    CHECK_THROWS_MATCHES(parser.GetString("badarg"), std::runtime_error,
                         MessageMatches(Catch::Matchers::StartsWith(
                             "Unknown argument in Get...")));
    CHECK_THROWS_MATCHES(parser.GetString("help"), std::runtime_error,
                         MessageMatches(Catch::Matchers::StartsWith(
                             "Invalid argument in Get...")));
  }
  THEN("Only bool argument") {
    CallParse(parser, {"COMMAND", "--help"});
    CHECK(parser.GetBool("help"));
    CHECK_FALSE(parser.GetString("name").has_value());
  }
  THEN("Bool = form") {
    GIVEN("=true") {
      CallParse(parser, {"COMMAND", "--help=true"});
      CHECK(parser.GetBool("help"));
    }
    GIVEN("=yes") {
      CallParse(parser, {"COMMAND", "--help=yes"});
      CHECK(parser.GetBool("help"));
    }
    GIVEN("=anything_else") {
      CallParse(parser, {"COMMAND", "--help=false"});
      CHECK_FALSE(parser.GetBool("help"));
    }
  }
  THEN("Only string argument") {
    CallParse(parser, {"COMMAND", "--name", "hello"});
    CHECK_FALSE(parser.GetBool("help"));
    CHECK(parser.GetString("name") == "hello");
  }
  THEN("Both arguments") {
    CallParse(parser, {"COMMAND", "--name", "hello", "--help"});
    CHECK(parser.GetBool("help"));
    CHECK(parser.GetString("name") == "hello");
  }
  THEN("Both arguments, using 'arg=value' format") {
    CallParse(parser, {"COMMAND", "--name=hello", "--help"});
    CHECK(parser.GetBool("help"));
    CHECK(parser.GetString("name") == "hello");
  }
}