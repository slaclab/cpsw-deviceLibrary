########################
### Package versions ###
########################

# Location of packages. On S3DF, this should be defaulted to EPICS_PACKAGE_TOP. On AFS, we default to an absolute AFS path
# This may also be provided on the command line or in the environment
ifeq ($(PACKAGE_TOP),)
ifneq ($(EPICS_PACKAGE_TOP),)
PACKAGE_TOP     = $(EPICS_PACKAGE_TOP)
else
$(error PACKAGE_TOP or EPICS_PACKAGE_TOP must be set in the environment or on the command line)
endif
endif

CPSW_FRAMEWORK_VERSION=R4.5.2

CPSW_DIR=$(PACKAGE_TOP)/cpsw/framework/$(CPSW_FRAMEWORK_VERSION)/src
