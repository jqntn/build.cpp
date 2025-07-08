// cl /std:c++20 /EHsc build.cpp && build && del build.exe build.obj

#include "build.hpp"

int
main()
{
  target hello("hello");

  hello.set_kind(binary);
  hello.set_version(cpp20);
  hello.add_files({ "CMakeProject1.cpp", "CMakeProject1.h" });

  hello.build();
}