#ifndef HA32FBBFD_6636_4338_A93C_574D9960AC91
#define HA32FBBFD_6636_4338_A93C_574D9960AC91

#include "re2/re2.h"

namespace httplite {

struct HttpPath {
  HttpPath(const char* path);

  template <typename... Args>
  bool matches(const re2::RE2& re, Args&&... args) const {
    return re2::FullMatch(path, re, std::forward<Args>(args)...);
  }

private:
  const char* path;
};

#endif
