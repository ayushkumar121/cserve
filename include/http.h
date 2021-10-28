#ifndef HTTP_H
#define HTTP_H

/*
 * HTTP 1.x standard : https://www.ietf.org/rfc/rfc2616.txt
 */

typedef enum
{
  HTTP_GET,
  HTTP_POST,
  HTTP_PUT,
  HTTP_HEAD,
  HTTP_OPTIONS,
  HTTP_DELETE,
  HTTP_UNRECOGNISED_METHOD,
} http_method;

typedef enum
{
  /* Successful 2xx  */
  HTTP_OK                             = 200,
  HTTP_CREATED                        = 201,
  HTTP_ACCEPTED                       = 202,
  HTTP_NON_AUTHORITATIVE_INFORMATION  = 203,
  HTTP_NO_CONTENT                     = 204,
  HTTP_RESET_CONTENT                  = 205, 
  HTTP_PARTIAL_CONTENT                = 206,

  /* Redirection 3xx */
  HTTP_MULTIPLE_CHOICE                = 300,
  HTTP_MOVE_PERMANENTLY               = 301,
  HTTP_FOUND                          = 302,
  HTTP_SEE_OTHER                      = 303,
  HTTP_NOT_MODIFIED                   = 304,
  HTTP_USE_PROXY                      = 305,
  HTTP_UNUSED                         = 306,
  HTTP_TEMPORARY_REDIRECT             = 307,

  /* Client Error 4xx */
  HTTP_BAD_REQUEST                    = 400,
  HTTP_UNAUTHORIZED                   = 401,
  HTTP_FORBIDDEN                      = 403,
  HTTP_NOT_FOUND                      = 404,
  HTTP_METHOD_NOT_ALLOWED             = 405,
  HTTP_NOT_ACCEPTABLE                 = 406,
  HTTP_PROXY_AUTHENTICATION_REQUIRED  = 407,
  HTTP_REQUEST_TIMEOUT                = 408,
  HTTP_CONFLICT                       = 409,
  HTTP_GONE                           = 410,
  HTTP_LENGTH_REQUIRED                = 411,
  HTTP_PRECONDITION_FAILED            = 412,
  HTTP_REQUEST_ENTITY_TOO_LARGE       = 413,
  HTTP_REQUEST_URI_TOO_LONG           = 414,
  HTTP_UNSUPPORTED_MEDIA_TYPE         = 415,
  HTTP_REQUESTED_RANGE_NOT_SATISFIED  = 416,
  HTTP_EXPECTION_FAILED               = 417,

  /* Server Error 5xx */
  HTTP_INTERNAL_SERVER_ERROR          = 500,
  HTTP_NOT_IMPLEMENTED                = 501,
  HTTP_BAD_GATEWAY                    = 502,
  HTTP_SERVICE_UNAVAILABLE            = 503,
  HTTP_GATEWAY_TIMEOUT                = 504,
  HTTP_VERSION_NOT_SUPPORTED          = 505,

} http_status;

#endif /* HTTP_H */