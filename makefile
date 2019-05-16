# If this library is used as a submodule by another
# package then they define TOPDIR and provide a
# 'release.mak'

ifndef TOPDIR
TOPDIR=.
endif

ifndef INSTALL_DIR
INSTALL_DIR=.
endif

TOPTARGETS := all clean install uninstall
SUBDIRS := src 

define UPD
$(foreach var,$(1),$(var)=$(addprefix $(if $($(var):/%=),../,),$($(var))))
endef

$(TOPTARGETS): $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS) $(call UPD,TOPDIR INSTALL_DIR)

.PHONY: $(TOPTARGETS) $(SUBDIRS) 
