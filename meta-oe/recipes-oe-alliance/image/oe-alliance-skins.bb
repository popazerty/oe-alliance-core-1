SUMMARY = "Manage skins for OE-Alliance feeds."
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/LICENSE;md5=4d92cd373abda3937c2bc47fbc49d690 \
                    file://${COREBASE}/meta/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"

ALLOW_EMPTY_${PN} = "1"
PACKAGES = "${PN}"

PV = "1.0"
PR = "r26"

inherit packagegroup

DEPENDS = "enigma2"

RDEPENDS_${PN} = "\
	enigma2-plugin-skins-mynovumhd2 \
	enigma2-plugin-skins-mynovumhd2black \
	enigma2-plugin-skins-novum_hd_slim \
	enigma2-nou-skins \
	enigma2-plugin-skins-army-moodblue-hd \
	enigma2-plugin-skins-kravense \
	enigma2-plugin-skins-kravenhd \
	enigma2-plugin-skins-kravenfullhd \
	enigma2-plugin-skins-blackspirit.hd \
    "
