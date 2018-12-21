#include "httplite/core/http_status.h"

namespace httplite {
namespace {

// http://www.iana.org/assignments/http-status-codes/http-status-codes.xhtml#http-status-codes-1
enum HttpStatusCode {
  UNDEFINED = 0,
  FIRST_CODE = 100,

  // Informational
  CONTINUE = 100,
  SWITCHING = 101,
  PROCESSING = 102,

  // Success
  OK = 200,
  CREATED = 201,
  ACCEPTED = 202,
  PROVISIONAL = 203,
  NO_CONTENT = 204,
  RESET_CONTENT = 205,
  PART_CONTENT = 206,
  MULTI_STATUS = 207,
  ALREADY_REPORTED = 208,
  IM_USED = 226,

  // Redirect
  MULTIPLE = 300,
  MOVED_PERM = 301,
  MOVED_TEMP = 302,
  SEE_OTHER = 303,
  NOT_MODIFIED = 304,
  USE_PROXY = 305,
  TEMP_REDIRECT = 307,
  RESUME_INCOMPLETE = 308,

  // Client Error
  BAD_REQUEST = 400,
  UNAUTHORIZED = 401,
  PAYMENT = 402,
  FORBIDDEN = 403,
  NOT_FOUND = 404,
  METHOD_NA = 405,
  NONE_ACC = 406,
  PROXY = 407,
  REQUEST_TO = 408,
  CONFLICT = 409,
  GONE = 410,
  LEN_REQUIRED = 411,
  PRECOND_FAILED = 412,
  ENTITY_TOO_BIG = 413,
  URI_TOO_BIG = 414,
  UNKNOWN_MEDIA = 415,
  BAD_RANGE = 416,
  BAD_EXPECTATION = 417,
  IM_A_TEAPOT = 418,
  MISDIRECTED_REQUEST = 421,
  UNPROC_ENTITY = 422,
  LOCKED = 423,
  FAILED_DEP = 424,
  UPGRADE_REQUIRED = 426,
  PRECOND_REQUIRED = 428,
  TOO_MANY_REQUESTS = 429,
  HEADER_TOO_LARGE = 431,

  UNAVAILABLE_LEGAL = 451,
  CLIENT_CLOSED_REQUEST = 499,

  // Server Error
  ERROR = 500,
  NOT_IMP = 501,
  BAD_GATEWAY = 502,
  SERVICE_UNAV = 503,
  GATEWAY_TO = 504,
  BAD_VERSION = 505,
  VARIANT_NEGOTIATES = 506,
  INSUF_STORAGE = 507,
  LOOP_DETECTED = 508,
  NOT_EXTENDED = 510,
  NETAUTH_REQUIRED = 511,

  LAST_CODE = 599,
};

HttpStatusCode to(cub::Status status) {
  switch (status) {
  case cub::Success:
    return OK;
  case cub::Cancelled:
    return CLIENT_CLOSED_REQUEST;
  case cub::Unknown:
    return ERROR;
  case cub::InvalidArgument:
    return BAD_REQUEST;
  case cub::DeadlineExceeded:
    return GATEWAY_TO;
  case cub::NotFound:
    return NOT_FOUND;
  case cub::AlreadyExists:
    return CONFLICT;
  case cub::PermissionDenied:
    return FORBIDDEN;
  case cub::ResourceExhausted:
    return TOO_MANY_REQUESTS;
  case cub::FailedPrecondition:
    return BAD_REQUEST;
  case cub::Aborted:
    return CONFLICT;
  case cub::OutOfRange:
    return BAD_REQUEST;
  case cub::Unimplemented:
    return NOT_IMP;
  case cub::Internal:
    return ERROR;
  case cub::Unavailable:
    return SERVICE_UNAV;
  case cub::DataLoss:
    return ERROR;
  case cub::Unauthenticated:
    return UNAUTHORIZED;
  default:
    return ERROR;
  }
}

}  // namespace

HttpStatus::HttpStatus(cub::Status result) : status(to(result)) {
}

int HttpStatus::getStatus() const {
  return status;
}

}  // namespace httplite
