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

#ifndef __ESSENTIALS_H
#define __ESSENTIALS_H

#include <algorithm>
#include <functional>
#include <unordered_map>
#include <vector>

// Strings.

inline std::string ToLowerCase(const std::string& str) {
  std::string result = str;
  for (char& c : result) {
    c = std::tolower(static_cast<unsigned char>(c));
  }
  return result;
}

inline bool StartsWith(const std::string& str, const std::string& prefix) {
  return str.compare(0, prefix.length(), prefix) == 0;
}

// Let's bring some sanity to maps.

// Map contains.
template <typename T, typename U>
bool MapContains(const std::unordered_map<T, U>& map, const T& key) {
  const auto& it = map.find(key);
  return it != map.end();
}

// Map lookup.
template <typename T, typename U>
std::optional<U> MapLookup(const std::unordered_map<T, U>& map, const T& key) {
  const auto& it = map.find(key);
  if (it == map.end()) return std::nullopt;
  return it->second;
}

// Sorted version of a map, with specified sort order.
// E.g. -
// for (const auto& [key, value] :
//      Sorted(all_states_, [](const std::string& value1,
//                             const std::string& value2) {
//        return value1 < value2;
//      })) {
//   ...
// }
template <typename T, typename U, typename Func>
std::vector<std::pair<T, U>> Sorted(const std::unordered_map<T, U>& input,
                                    Func value_ordering) {
  std::vector<std::pair<T, U>> result;
  result.insert(result.begin(), input.begin(), input.end());
  std::sort(
      result.begin(), result.end(),
      [value_ordering](const std::pair<T, U>& el1, const std::pair<T, U>& el2) {
        return el1.first < el2.first ||
               (el1.first == el2.first &&
                value_ordering(el1.second, el2.second));
      });

  return result;
}

// Sorted version of a map, with specified sort order; just by the key.
template <typename T, typename U>
std::vector<std::pair<T, U>> Sorted(const std::unordered_map<T, U>& input) {
  std::vector<std::pair<T, U>> result;
  result.insert(result.begin(), input.begin(), input.end());
  std::sort(result.begin(), result.end(),
            [](const std::pair<T, U>& el1, const std::pair<T, U>& el2) {
              return el1.first < el2.first;
            });
  return result;
}

#endif  // __ESSENTIALS_H