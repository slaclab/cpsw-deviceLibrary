# If this library is used as a submodule by another
# package then they define TOPDIR and provide a
# 'release.mak'

ifndef TOPDIR
TOPDIR=.
endif

TOPTARGETS := all clean install uninstall
SUBDIRS := src 

$(TOPTARGETS): $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@ TOPDIR=../$(TOPDIR) $(MAKECMDGOALS)

.PHONY: $(TOPTARGETS) $(SUBDIRS) 
