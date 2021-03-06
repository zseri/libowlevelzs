#include "xcpy.h"
#include <stdlib.h>      /* malloc */
#include <string.h>      /* memcpy */
#include <llzs_config.h>

void llzs_strixcpy(char * restrict * restrict dstp, const char * restrict src, size_t n) {
  /* assert(strlen(src) == n && sizeof(dest) >= (n + 1)); */
  memcpy(*dstp, src, n);
  *dstp += n; **dstp = 0;
}

char * llzs_strxcpy(char * restrict dest, const char * restrict src, size_t n) {
  llzs_strixcpy(&dest, src, n);
  return dest;
}

char * llzs_strxdup(const char * str, size_t n) {
  if(zs_unlikely(!str)) return 0;
  /* assert(strlen(str) == n); */
  char *const ret = malloc(n + 1);
  if(zs_likely(ret)) {
    memcpy(ret, str, n);
    ret[n] = 0;
  }
  return ret;
}
