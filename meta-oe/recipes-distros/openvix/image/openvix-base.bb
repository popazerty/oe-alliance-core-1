SUMMARY = "Base packages require for image."
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/LICENSE;md5=4d92cd373abda3937c2bc47fbc49d690 \
                    file://${COREBASE}/meta/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"

ALLOW_EMPTY_${PN} = "1"
PACKAGES = "${PN}"

PV = "1.0"
PR = "r17"

inherit packagegroup

DEPENDS = "openvix-version-info"

RDEPENDS_${PN} = "\
    oe-alliance-base \
    openvix-version-info \
    openvix-enigma2 \
    openvix-bootlogo \
    openvix-spinner \
    libcrypto-compat-0.9.8 \
    packagegroup-base-smbfs \
    packagegroup-base-smbfs-client \
    packagegroup-base-smbfs-server \
    "

