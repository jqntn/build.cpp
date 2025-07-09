#pragma once

#pragma warning(push)
#pragma warning(disable : 4530)
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
#pragma warning(pop)

namespace fs = std::filesystem;

enum log_severity : char
{
  info = 'I',
  warning = 'W',
  error = 'E',
  fatal = 'F',
};

void
log(log_severity severity, const std::string& str)
{
  FILE* stream = stdout;
  if (severity == error || severity == fatal) {
    stream = stderr;
  }

  fprintf(stream, "%c: %s", severity, str.c_str());

  if (severity == fatal) {
    std::abort();
  }
}

enum target_kind
{
  binary,
  library,
  shared,
};

enum target_version
{
  cpp98,
  cpp11,
  cpp14,
  cpp17,
  cpp20,
  cpp23,
  cpp26,
};

enum target_mode
{
  debug,
  release,
};

class target
{
public:
  target(std::string name)
    : m_name(name)
  {
  }

  void set_kind(target_kind kind) { m_kind = kind; }
  void set_version(target_version version) { m_version = version; }
  void set_mode(target_mode mode) { m_mode = mode; }
  void add_files(const std::vector<fs::path>& files)
  {
    m_files.insert(m_files.end(), files.begin(), files.end());
  }

  void build()
  {
    if (m_files.empty()) {
      log(fatal, "no source files have been added");
    }

    fs::path out_dir = "build";

    fs::remove_all(out_dir);
    fs::create_directories(out_dir);
  }

private:
  std::string m_name = "out";
  target_kind m_kind = target_kind::binary;
  target_version m_version = target_version::cpp20;
  target_mode m_mode = target_mode::debug;
  std::vector<fs::path> m_files;
};