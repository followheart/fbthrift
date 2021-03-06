/*
 * Copyright 2016-present Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <thrift/compiler/visitor.h>

namespace apache {
namespace thrift {
namespace compiler {

class mutator : virtual public visitor {
 public:
  static void mutate(t_program* program);

  using visitor::visit;

  bool visit(t_program* program) override;

  t_type* resolve_type(t_type* field);
  void traverse_field(t_type* long_type, t_const_value* value);

 private:
  template <typename T, typename... Args>
  friend std::unique_ptr<T> make_mutator(Args&&...);
};

template <typename T, typename... Args>
std::unique_ptr<T> make_mutator(Args&&... args) {
  return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}


template <typename T, typename... Args>
void run_mutator(t_program* program, Args&&... args) {
  make_mutator<T>(std::forward<Args>(args)...)->traverse(program);
}

class field_type_to_const_value : virtual public mutator {
 public:
  using mutator::visit;

  /**
   * This matches the type of fields to their const values
   */
  bool visit(t_field* field) override;

 private:
  void match_type_with_const_value(t_field* tfield);
};

class const_type_to_const_value : virtual public mutator {
 public:
  using mutator::visit;

  /**
   * This matches the type of consts to their const values
   */
  bool visit(t_const* tconst) override;

 private:
  void match_type_with_const_value(t_const* tconst);
};

}
}
}
