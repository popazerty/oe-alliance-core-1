SUMMARY = "gstreamer dvbmediasink plugin"
SECTION = "multimedia"
PRIORITY = "optional"
LICENSE = "GPLv2"
PACKAGE_ARCH = "${MACHINE_ARCH}"
LIC_FILES_CHKSUM = "file://COPYING;md5=7fbc338309ac38fefcd64b04bb903e34"

DEPENDS = "gstreamer gst-plugins-base libdca"

SRC_URI = "git://git.code.sf.net/p/openpli/${PN};protocol=git"

SRC_URI_append_dags1 = " \
    file://dvbavmediasink-0.1.patch;patch=1 \ 
"
SRC_URI_append_dags2 = " \
    file://dvbavmediasink-0.1.patch;patch=1 \ 
"
SRC_URI_append_dags3 = " \
    file://dvbavmediasink-0.1.patch;patch=1 \ 
"
SRC_URI_append_dags4 = " \
    file://dvbavmediasink-0.1.patch;patch=1 \ 
"
SRC_URI_append_dags5 = " \
    file://dvbavmediasink-0.1.patch;patch=1 \ 
"

S = "${WORKDIR}/git"

inherit gitpkgv

PV = "0.10.0+git${SRCPV}"
PKGV = "0.10.0+git${GITPKGV}"
PR = "r22"

inherit autotools pkgconfig

do_configure_prepend() {
    touch ${S}/NEWS
    touch ${S}/README
    touch ${S}/AUTHORS
    touch ${S}/ChangeLog
}

FILES_${PN} = "${libdir}/gstreamer-0.10/*.so*"
FILES_${PN}-dev += "${libdir}/gstreamer-0.10/*.la"
FILES_${PN}-staticdev += "${libdir}/gstreamer-0.10/*.a"
FILES_${PN}-dbg += "${libdir}/gstreamer-0.10/.debug"

EXTRA_OECONF = "${DVBMEDIASINK_CONFIG}"
