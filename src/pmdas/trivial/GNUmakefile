#
# Copyright (c) 2012-2015,2018 Red Hat.
# Copyright (c) 2000,2003,2004 Silicon Graphics, Inc.  All Rights Reserved.
# 
# This program is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation; either version 2 of the License, or (at your
# option) any later version.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
# or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
# for more details.
# 

TOPDIR = ../../..
include $(TOPDIR)/src/include/builddefs

CFILES	= trivial.c
CMDTARGET = pmdatrivial$(EXECSUFFIX)
LIBTARGET = pmda_trivial.$(DSOSUFFIX)
LLDLIBS = $(PCP_PMDALIB)
LCFLAGS = -I.
DFILES 	= README help
SCRIPTS = pmdatrivial.perl
ifeq "$(HAVE_PYTHON)" "true"
SCRIPTS += pmdatrivial.python
endif

IAM	= trivial
DOMAIN	= TRIVIAL
PMDADIR	= $(PCP_PMDAS_DIR)/$(IAM)

LDIRT	= domain.h *.o $(IAM).log pmda$(IAM) pmda_$(IAM).$(DSOSUFFIX)

default_pcp default:	$(CMDTARGET) $(LIBTARGET)

include $(BUILDRULES)

install install_pcp:	default
	$(INSTALL) -m 755 -d $(PMDADIR)
	$(INSTALL) -m 755 Install Remove $(SCRIPTS) $(PMDADIR)
	$(INSTALL) -m 644 GNUmakefile.install $(PMDADIR)/Makefile
	$(INSTALL) -m 644 $(DFILES) root pmns domain.h $(CFILES) $(PMDADIR)

$(OBJECTS): domain.h

domain.h: ../../pmns/stdpmid
	$(DOMAIN_MAKERULE)
