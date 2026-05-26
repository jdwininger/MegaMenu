GDK ?= /opt/sgdk

# Output filename without extension.
ROM = MegaMenu

# Optional extra defines.
CCFLAGS += -DMENU_ROM_TARGET_4MB

# SGDK handles src/, inc/, and res/ conventions automatically.
include $(GDK)/makefile.gen
