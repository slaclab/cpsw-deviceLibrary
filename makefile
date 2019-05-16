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
	$(MAKE) -C $@ $(MAKECMDGOALS) TOPDIR=$(addprefix $(if $(TOPDIR:/%=),../,),$(TOPDIR))

.PHONY: $(TOPTARGETS) $(SUBDIRS) 
