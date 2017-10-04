# Base this image on core-image-minimal
include recipes-core/images/core-image-minimal.bb

# add default password for root

ROOTFS_POSTPROCESS_COMMAND += "set_root_passwd;"
set_root_passwd() {
   ROOTPW_ENCRYPTED=""
   if [ -n "${ROOTPW}" ]; then
   ROOTPW_ENCRYPTED=`openssl passwd -crypt -quiet ${ROOTPW}`
   else
   ROOTPW_ENCRYPTED="wYNffsf6sozwE"
   fi
   sed "s%^root:[^:]*:%root:${ROOTPW_ENCRYPTED}:%" \
       < ${IMAGE_ROOTFS}/etc/shadow \
       > ${IMAGE_ROOTFS}/etc/shadow.new;
   mv ${IMAGE_ROOTFS}/etc/shadow.new ${IMAGE_ROOTFS}/etc/shadow ;
}


IMAGE_INSTALL += " \
	autofs \
	bash \
	bzip2 \
	cifs-utils \
	coreutils \
	dosfstools \
	e2fsprogs-e2fsck \
	e2fsprogs-mke2fs \
	e2fsprogs-tune2fs \
	etckeeper \
	gawk \
	glibc-charmaps \
	glibc-binary-localedata-de-de \
	glibc-gconvs \
	glibc-localedatas \
	gzip \
	hdparm \
	image-config \
	ifupdown \
	kernel-modules \
	libevent \
	libusb1 \
	localedef \
	mc \
	mc-fish \
	mc-helpers \
	mc-helpers-perl \
	minidlna \
	nano \
	nfs-utils \
	nfs-utils-client \
	ntfs-3g \
	ntfsprogs \
	ntpdate \
	openssh \
	openssl \
	opkg \
	oscam \
	parted \
	procps \
	rpcbind \
	samba \
	sed \
	tzdata \
	tzdata-europe \
	udev-extraconf \
	usbutils \
	util-linux \
	util-linux-agetty \
	util-linux-blkid \
	virtual/dvb-driver \
	virtual/screengrabber \
	vsftpd \
	wpa-supplicant \
"
    
RDEPENDS_${PN}_append_libc_glibc += "kbd-locale-de"





