#include "error.h"

void RTMPError_New(int code, const char *message) {
  RTMPError *error = (RTMPError *)malloc(sizeof(RTMPError));
  error->code = code;
  error->message = (char *)malloc(strlen(message) * sizeof(char));

  return error;
}

void RTMPError_Free(RTMPError *error) {
  if (error) {
    if (error->message) {
      free(error->message);
      error->message = NULL;
    }
    free(error);
  }
}
