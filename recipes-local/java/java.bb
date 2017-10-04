SUMMARY = "java native stub"
SECTION = "base"
PRIORITY = "required"
LICENSE = "proprietary"
LIC_FILES_CHKSUM = "file://${WORKDIR}/license;md5=17a6b3d5436a55985b200c725761907a"

PV = "1"
PR = "r0"

SRC_URI = "file://license \
		   "

do_install() {
	install -d  ${D}${bindir}
	ln -sf /usr/bin/java ${D}${bindir}/java
}

BBCLASSEXTEND = "native"