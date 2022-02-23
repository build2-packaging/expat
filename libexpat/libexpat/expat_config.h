/* file      : libexpat/expat_config.h -*- C -*-
 * license   : MIT; see accompanying COPYING file
 */

#ifndef LIBEXPAT_EXPAT_CONFIG_H
#define LIBEXPAT_EXPAT_CONFIG_H

/* Endianess.
 */
#ifdef __FreeBSD__
#  include <sys/endian.h> /* BYTE_ORDER */
#else
#  if defined(_WIN32)
#    ifndef BYTE_ORDER
#      define BIG_ENDIAN    4321
#      define LITTLE_ENDIAN 1234
#      define BYTE_ORDER    LITTLE_ENDIAN
#    endif
#  else
#    include <sys/param.h>  /* BYTE_ORDER/__BYTE_ORDER */
#    ifndef BYTE_ORDER
#      ifdef __BYTE_ORDER
#        define BYTE_ORDER    __BYTE_ORDER
#        define BIG_ENDIAN    __BIG_ENDIAN
#        define LITTLE_ENDIAN __LITTLE_ENDIAN
#      else
#        error no BYTE_ORDER/__BYTE_ORDER define
#      endif
#    endif
#  endif
#endif

#if BYTE_ORDER == BIG_ENDIAN
#  define BYTEORDER 4321
#else
#  define BYTEORDER 1234
#endif

#define UNUSED(x) (void)x;

/* Specific for FreeBSD.
 */
#if defined(__FreeBSD__)

/* Note that sys/random.h is not available for older versions of glibc. Thus,
 * we don't define this macro on Linux.
 */
#  define HAVE_GETRANDOM         1

/* Note that the getrandom system call is not available in older Linux
 * kernels. Thus, we don't define this macro on Linux.
 */
#  define HAVE_SYSCALL_GETRANDOM 1
#endif

/* Specific for FreeBSD and Mac OS.
 */
#if defined(__FreeBSD__) || defined(__APPLE__)
#  define HAVE_ARC4RANDOM_BUF 1
#endif

/* Specific for (non-) VC.
 */
#ifndef _MSC_VER
#  define XML_DEV_URANDOM 1
#endif

/* Common for all supported OSes/compilers.
 */
#define XML_NS            1
#define XML_DTD           1
#define XML_CONTEXT_BYTES 1024

#undef XML_ATTR_INFO
#undef HAVE_LIBBSD
#undef HAVE_ARC4RANDOM

/* We can probably assume that on platforms we build for, these keywords/types
 * don't require definition.

#undef size_t
*/

#endif /* LIBEXPAT_EXPAT_CONFIG_H */
