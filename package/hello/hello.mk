################################################################################
#
# hello
#
################################################################################

HELLO_VERSION = 1.0
HELLO_SITE = ../src
HELLO_SITE_METHOD = local

define HELLO_BUILD_CMDS
	$(MAKE) CC="$(TARGET_CC)" LD="$(TARGET_LD)" -C $(@D)
endef

define HELLO_INSTALL_TARGET_CMDS
	$(INSTALL) -D -m 0755 $(@D)/hello $(TARGET_DIR)/usr/bin
	$(INSTALL) -D -m 0755 $(@D)/alloc $(TARGET_DIR)/usr/bin
endef

$(eval $(generic-package))