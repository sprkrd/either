//Either's implementation

//Copyright (C) 2019 Alejandro Suárez Hernández

//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU Lesser General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU Lesser General Public License for more details.

//You should have received a copy of the GNU Lesser General Public License
//along with this program.  If not, see <https://www.gnu.org/licenses/>.

#ifndef _ASH_EITHER_HPP_
#define _ASH_EITHER_HPP_

#include <type_traits>
#include <stdexcept>
#include <utility>

namespace ash {

template<class Left, class Right>
class Either {
  static_assert(!std::is_same<Left,Right>::value, "Left and Right types cannot be equal");

  private:

    template<class LeftMapper, class RightMapper>
    struct return_type {
      typedef decltype(std::declval<LeftMapper>()(std::declval<Left>())) type;
      typedef decltype(std::declval<RightMapper>()(std::declval<Right>())) type_;
      static_assert(std::is_same<type,type_>::value, "Both mappers must return the same type");
    };

    template<class LeftMapper, class RightMapper>
    using return_type_t = typename return_type<LeftMapper,RightMapper>::type;

  public:

    Either(const Either& other) {
      copy(other);
    }

    Either(Either&& other) noexcept {
      move(std::move(other));
    }

    Either(const Left& left) : _left(left), _is_left(true) {
    }

    Either(const Right& right) : _right(right), _is_left(false) {
    }

    Either(Left&& left) noexcept : _left(std::move(left)), _is_left(true) {
    }

    Either(Right&& right) noexcept : _right(std::move(right)), _is_left(false) {
    }

    Either& operator=(const Either& other) {
      copy(other);
      return *this;
    }

    Either& operator=(Either&& other) noexcept {
      move(other);
      return *this;
    }

    Either& operator=(const Left& left) {
      destroy();
      new(&_left) Left(left);
      _is_left = true;
      return *this;
    }

    Either& operator=(const Right& right) {
      destroy();
      new(&_right) Right(right);
      _is_left = false;
      return *this;
    }

    Either& operator=(Left&& left) noexcept {
      destroy();
      new(&_left) Left(std::move(left));
      _is_left = true;
      return *this;
    }

    Either& operator=(Right&& right) noexcept {
      destroy();
      new(&_right) Right(std::move(right));
      _is_left = false;
      return *this;
    }

    bool isLeft() const {
      return _is_left;
    }

    bool isRight() const {
      return not _is_left;
    }

    const Left& getLeft() const {
      if (not _is_left)
        throw std::runtime_error("Either type does not contain value of Left type");
      return _left;
    }

    const Right& getRight() const {
      if (_is_left)
        throw std::runtime_error("Either type does not contain value of Right type");
      return _right;
    }

    template<class LeftMapper, class RightMapper>
    return_type_t<LeftMapper,RightMapper> join(const LeftMapper& left_mapper, const RightMapper& right_mapper) const {
      return _is_left? left_mapper(_left) : right_mapper(_right);
    }

    ~Either() {
      destroy();
    }

  private:

    union {
      Left _left;
      Right _right;
    };
    bool _is_left;

    void destroy() {
      if (_is_left) _left.~Left();
      else _right.~Right();
    }

    void copy(const Either& other) {
      if (other._is_left) *this = other._left;
      else *this = other._right;
    }

    void move(Either&& other) {
      if (other._is_left) *this = std::move(other._left);
      else *this = std::move(other._right);
    }
};

} // end namespace

#endif


