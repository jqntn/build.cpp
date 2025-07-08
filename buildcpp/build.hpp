#pragma once

#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

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

class target
{
public:
  target(std::string name)
    : m_name(name)
  {
  }

  void set_kind(target_kind kind) { m_kind = kind; }
  void set_version(target_version version) { m_version = version; }
  void add_files(const std::vector<fs::path>& files)
  {
    m_files.insert(m_files.end(), files.begin(), files.end());
  }

  void build()
  {
    if (m_files.empty()) {
      std::fprintf(stderr, "no source files have been added");
      std::abort();
    }

    fs::path out_dir = "build.cpp.out";

    fs::remove_all(out_dir);
    fs::create_directories(out_dir);
  }

private:
  std::string m_name = "out";
  target_kind m_kind = target_kind::binary;
  target_version m_version = target_version::cpp20;
  std::vector<fs::path> m_files;
};