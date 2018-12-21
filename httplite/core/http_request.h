#ifndef HB44705F4_4F40_4ADA_8EB0_EAF3F4EC02FB
#define HB44705F4_4F40_4ADA_8EB0_EAF3F4EC02FB

#include "cub/dci/role.h"
#include "cub/base/status.h"
#include "cub/string/string_view.h"

namespace httplite {

struct HttpBody;
struct HttpStatus;
struct HttpResponse;

DEFINE_ROLE(HttpRequest) {
  ABSTRACT(cub::StringView getPath() const);
  ABSTRACT(cub::StringView getMethod() const);
  ABSTRACT(cub::Status parseBody(HttpBody&) const);
  ABSTRACT(cub::Status replyResponse(const HttpResponse&, const HttpStatus&) const);
};

}

#endif
