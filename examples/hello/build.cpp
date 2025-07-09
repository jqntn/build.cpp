#include "../../build.hpp"

int
main()
{
  target hello("hello");

  hello.set_mode(debug);
  hello.set_kind(binary);
  hello.set_version(cpp20);
  hello.add_files({ "hello.cpp" });

  hello.build();
}