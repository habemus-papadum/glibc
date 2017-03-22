#ifndef __struct_iovec_defined
#define __struct_iovec_defined 1

#define __need_size_t
#include <stddef.h>

/* Structure for scatter/gather I/O.  */
struct iovec
  {
    void *iov_base;     /* Pointer to data.  */
    size_t iov_len;     /* Length of data.  */
  };

#endif
