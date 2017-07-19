TAP_DANCE_ENABLE = yes
#UNICODE_ENABLE = yes
#UCIS_ENABLE = yes
#UNICODEMAP_ENABLE = yes

IMAGE:=ergodox_ez_grafov.hex
PRJROOT :=$(realpath $(shell echo `pwd`/../../../..))

buildez:
	cd ${PRJROOT}
	docker run -e keymap=grafov -e subproject=ez -e keyboard=ergodox --rm -v ${PRJROOT}:/qmk:rw edasque/qmk_firmware

flash: ${PRJROOT}/.build/${IMAGE}
	@cp ${PRJROOT}/.build/${IMAGE} ~
	sudo ~/bin/teensy ~/${IMAGE}
	@rm -f ~/${IMAGE}

init:
	~/bin/ez.sh
#	~/bin/qwerty.sh
	xset r rate 300 90


