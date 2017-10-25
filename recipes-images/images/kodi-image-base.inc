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
	dosfstools \
	e2fsprogs-e2fsck \
	e2fsprogs-mke2fs \
	e2fsprogs-tune2fs \
	etckeeper \
	gstreamer1.0-plugins-base \
	gstreamer1.0-plugins-good \
	gstreamer1.0-plugins-bad \
	gstreamer1.0-plugins-ugly \
	gstreamer1.0-plugin-dvbmediasink \
	gstreamer1.0-libav \
	gzip \
	hdparm \
	image-config \
	ifupdown \
	kernel-modules \
	libusb1 \
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
	rpcbind \
	samba \
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





