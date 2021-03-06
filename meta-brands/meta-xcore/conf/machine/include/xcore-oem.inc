# We know about rtc
include conf/machine/include/build-extras.inc

BRAND_OEM = "xcore"

MACHINE_NAME = "\
${@base_contains('MACHINEBUILD', 'spycat', 'SPYCAT' , '', d)}\
${@base_contains('MACHINEBUILD', 'spycatmini', 'SPYCAT' , '', d)}\
${@base_contains('MACHINEBUILD', 'vp7358ci', '7358ci' , '', d)}\
${@base_contains('MACHINEBUILD', 'bcm7358', '7358' , '', d)}\
${@base_contains('MACHINEBUILD', 'osmini', 'OS mini' , '', d)}\
"

MACHINE_BRAND = "\
${@base_contains('MACHINEBUILD', 'spycat', 'XCORE' , '', d)}\
${@base_contains('MACHINEBUILD', 'spycatmini', 'XCORE' , '', d)}\
${@base_contains('MACHINEBUILD', 'vp7358ci', 'Sample2' , '', d)}\
${@base_contains('MACHINEBUILD', 'bcm7358', 'Sample1' , '', d)}\
${@base_contains('MACHINEBUILD', 'osmini', 'Edision' , '', d)}\
"

IMAGEDIR ?= "\
${@base_contains('MACHINEBUILD', 'spycat', 'spycat' , '', d)}\
${@base_contains('MACHINEBUILD', 'spycatmini', 'spycat' , '', d)}\
${@base_contains('MACHINEBUILD', 'vp7358ci', 'vp7358ci' , '', d)}\
${@base_contains('MACHINEBUILD', 'bcm7358', 'bcm7358' , '', d)}\
${@base_contains('MACHINEBUILD', 'osmini', 'osmini' , '', d)}\
"

MTD_KERNEL = "\
${@base_contains('MACHINEBUILD', 'spycat', 'mtd0' , '', d)}\
${@base_contains('MACHINEBUILD', 'spycatmini', 'mtd0' , '', d)}\
${@base_contains('MACHINEBUILD', 'vp7358ci', 'mtd2' , '', d)}\
${@base_contains('MACHINEBUILD', 'bcm7358', 'mtd2' , '', d)}\
${@base_contains('MACHINEBUILD', 'osmini', 'mtd0' , '', d)}\
"

MTD_ROOTFS = "\
${@base_contains('MACHINEBUILD', 'spycat', 'mtd2' , '', d)}\
${@base_contains('MACHINEBUILD', 'spycatmini', 'mtd2' , '', d)}\
${@base_contains('MACHINEBUILD', 'vp7358ci', 'mtd3' , '', d)}\
${@base_contains('MACHINEBUILD', 'bcm7358', 'mtd3' , '', d)}\
${@base_contains('MACHINEBUILD', 'osmini', 'mtd2' , '', d)}\
"

MACHINE_DRIVER = "\
${@base_contains('MACHINEBUILD', 'spycat', 'spycat' , '', d)}\
${@base_contains('MACHINEBUILD', 'spycatmini', 'spycatmini' , '', d)}\
${@base_contains('MACHINEBUILD', 'vp7358ci', 'vp7358ci' , '', d)}\
${@base_contains('MACHINEBUILD', 'bcm7358', 'bcm7358' , '', d)}\
${@base_contains('MACHINEBUILD', 'osmini', 'osmini' , '', d)}\
"

KERNEL_FILE = "kernel.bin"
ROOTFS_FILE = "rootfs.bin"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS = "\
    xcore-dvb-modules-${MACHINE_DRIVER} \
    "

DVBPROVIDER = "kernel"

MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS += " \
    kernel-module-cdfs \
    "

MACHINE_EXTRA_RRECOMMENDS += " \
    gst-plugin-dvbmediasink \
    "

include conf/machine/include/autoload-filesystems.inc

DVBMEDIASINK_CONFIG = "--with-wma --with-wmv --with-pcm --with-dts --with-eac3"

TARGET_ARCH = "mipsel"
DEFAULTTUNE = "mips32el"

PREFERRED_PROVIDER_virtual/blindscan-dvbs = "xcore-blindscan-utils"
PREFERRED_PROVIDER_virtual/blindscan-dvbc = "xcore-blindscan-utils"

PREFERRED_PROVIDER_virtual/kernel = "linux-xcore"

KERNEL_OUTPUT = "${KERNEL_IMAGETYPE}"
KERNEL_CONSOLE = "ttyS0,115200n8"

IMAGE_FSTYPES ?= "ubi"

IMAGE_CMD_ubi_prepend = " \
    rm -rf ${IMAGE_ROOTFS}/boot/*; \
    rm -rf ${IMAGE_ROOTFS}/tmp/*; \
    "

MACHINE_FEATURES += "alsa wifi 3dtv switchoff hdmicec bootsplash omb"

BOOTLOGO_FILENAME = "splash.bin"

require conf/machine/include/tune-mips32.inc

# add support for extra feeds
PACKAGE_ARCHS += " ${MACHINEBUILD}"