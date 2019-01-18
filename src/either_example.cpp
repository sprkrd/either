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

#include <ash/either.hpp>
#include <iostream>
#include <string>
using namespace ash;
using namespace std;

ostream& operator<<(ostream& out, const Either<int, string>& either) {
  if (either.isLeft()) return out << either.getLeft();
  return out << either.getRight();
}

int main(int /*argc*/, char ** /*argv[]*/) {
  //Either<int, string> number_or_string("hello world");
  Either<int, string> number_or_string(42);
  cout << number_or_string << endl;
  auto joined = number_or_string.join(
      [](int /*x*/) -> string { return "forty two"; },
      [](const string& s) -> string { return s; }
  );
  cout << joined << endl;
}


