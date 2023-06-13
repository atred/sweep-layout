SRC += features/achordion.c
# EXTRAFLAGS += -flto

MOUSEKEY_ENABLE = no		# Mouse keys(+4700)
COMMAND_ENABLE = no			# Commands for debug and configuration
UNICODE_ENABLE = no
EXTRAKEY_ENABLE = yes		# Audio control and System control(+450)
SLEEP_LED_ENABLE = no		# Breathing sleep LED during USB suspend
NKRO_ENABLE = yes			# Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no		# Enable keyboard backlight functionality
MIDI_ENABLE = no			# MIDI controls
AUDIO_ENABLE = no			# Audio output on port C6
BLUETOOTH_ENABLE = no		# Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE = no		# Enable WS2812 RGB underlight.

TAP_DANCE_ENABLE = no
CAPS_WORD_ENABLE = yes

LTO_ENABLE = yes
