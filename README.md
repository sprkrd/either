# Either's implementation

Implementation of `Either`, a union-based type to store either of two types
of value. Copy/move constructors/assignments behave as one would expect. It
supports a `join` operation to map left and right value into a common type.

An example of usage can be found in src/either_example.cpp. This is
a header-only library, so it is enough to copy its header (include/ash/either.hpp)
to your project.

`Either` only works when using different types (say, `Either<int,int>` will
not compile). This library is compatible with C++11 onwards.

## Instructions

To use, just copy the header file to your project and include it in the sources
in which you want to use it.

To build the example and the test:
```
make build
cd build
cmake ..
make
```

Then, to run the tests:
```
make test
```

The example can be executed from the `bin` folder.

## License

![LGPL 3.0 logo][lgplv3logo]

Either's implementation

Copyright (C) 2019 Alejandro Suárez Hernández

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

[lgplv3logo]: lgplv3.png "LGPL 3.0 logo"
