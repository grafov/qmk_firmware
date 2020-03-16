BOOTMAGIC_ENABLE=no
COMMAND_ENABLE=no
SLEEP_LED_ENABLE=no
NKRO_ENABLE = yes
FORCE_NKRO = yes
DEBUG_ENABLE = no
CONSOLE_ENABLE = no
TAP_DANCE_ENABLE = yes
KEYLOGGER_ENABLE = no
UCIS_ENABLE = no
MOUSEKEY_ENABLE = yes
AUTOLOG_ENABLE = no
EXTRAKEY_ENABLE = no
LEADER_ENABLE = no

RGBLIGHT_ENABLE = no
RGBLIGHT_ANIMATION = no
RGB_MATRIX_ENABLE = yes

OPT_DEFS += -DUSER_PRINT

# https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/
EXTRAFLAGS += -flto

KEYMAP_VERSION = $(shell \
 if [ -d "${KEYMAP_PATH}/.git" ]; then \
  cd "${KEYMAP_PATH}" && git describe --abbrev=6 --dirty --always --tags --match 'v*' 2>/dev/null; \
 else echo QMK; fi)

KEYMAP_BRANCH = $(shell \
 if [ -d "${KEYMAP_PATH}/.git" ]; then \
  cd "${KEYMAP_PATH}"; \
 fi; \
 git rev-parse --abbrev-ref HEAD 2>/dev/null)

OPT_DEFS += -DKEYMAP_VERSION=\"$(KEYMAP_VERSION)\\\#$(KEYMAP_BRANCH)\"

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
