#ifndef HE8F4583B_91E4_4B9A_A857_824738ED2D43
#define HE8F4583B_91E4_4B9A_A857_824738ED2D43

#include "cub/base/status.h"

namespace httplite {

struct HttpStatus {
  HttpStatus(cub::Status status);

  int getStatus() const;

private:
  int status;
};

}

#endif
