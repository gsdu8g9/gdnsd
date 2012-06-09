
## Overview

gdnsd is an Authoritative-only DNS server. The initial g stands for Geographic, as gdnsd offers a plugin system for geographic (or other sorts of) balancing, redirection, and service-state-conscious failover. The plugin system can also do things like weighted address/cname records.  If you don't care about these features you can ignore them :).

gdnsd is written in C using libev and pthreads with a focus on high performance, low latency service. It does not offer any form of caching or recursive service, and does not support DNSSEC.  There's a strong focus on making the code efficient, lean, and resilient.  The code has a decent regression testsuite with full branch coverage on the core packet parsing and generation code, and some scripted QA tools for e.g. valgrind validation, clang-analyzer, etc.

The geographically-aware features also support the emerging EDNS Client Subnet draft ( https://datatracker.ietf.org/doc/draft-vandergaast-edns-client-subnet/ , https://afasterinernet.com ) for receiving more-precise network location information from intermediate shared caches.

## Resources

This project is hosted at Github: https://github.com/blblack/gdnsd 

Release downloads: https://github.com/blblack/gdnsd/downloads

Bug reports: https://github.com/blblack/gdnsd/issues

Wikified docs: https://github.com/blblack/gdnsd/wiki

Google Group for discussion: https://groups.google.com/forum/#!forum/gdnsd

See the INSTALL file for details on prerequisites and build procedure
for working from the source tree or a source tarball.

The documentation is included in the source tree in POD format
and installed as manpages and textfiles on installation.

## Portability

The primary target platform is modern x86_64 Linux.  The code also compiles and works fine on MacOS X.  In theory, it should be portable to any reasonably-modern POSIXy platform with a good C99 compiler.  Several releases ago I spent some effort testing that it did in fact compile, pass tests, and operate correctly at runtime on a number of *BSDs, OpenSolaris w/ Sun's compiler, and even an embedded Linux router with a big-endian MIPS CPU.  YMMV on such targets with the modern codebase as I only regularly test Linux and Mac targets, but clean portability patches are always welcome.

## COPYRIGHT AND LICENSING

Some files within this distribution are externally sourced
open source software, and are covered by their own seperate
copyright and license terms.  Notably:

 *) All files in the subdirectory gdnsd/libev come from Marc
Alexander Lehmann's libev distribution, and are covered by his
separate LICENSE file, which is also included in that directory.
His license is GPL-compatible (specifically, it is an either/or
of GPL and other terms).

 *) Several autoconf-related files (macros and helper scripts
and so-on) contain their own embedded copyright and
GPL-compatible licensing terms.

All actual gdnsd source code is licensed under the terms of the
GPLv3, and includes an appropriate copyright/licensing block
near the top of each source file.

gdnsd is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

gdnsd is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with gdnsd.  If not, see <http://www.gnu.org/licenses/>.

