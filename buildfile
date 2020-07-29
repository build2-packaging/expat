# file      : buildfile
# license   : MIT; see accompanying COPYING file

# Glue buildfile that "pulls" all the packages.

import pkgs = {*/ -upstream/}
./: $pkgs
