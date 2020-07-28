/* file      : tests/basic/driver.c
 * license   : MIT; see accompanying COPYING file
 */

#include <stdio.h>
#include <assert.h>

#include <expat.h>

int
main ()
{
  XML_Expat_Version v = XML_ExpatVersionInfo ();

  assert (v.major == XML_MAJOR_VERSION &&
          v.minor == XML_MINOR_VERSION &&
          v.micro == XML_MICRO_VERSION);

  printf ("version: %d.%d.%d\n", v.major, v.minor, v.micro);
  return 0;
}
