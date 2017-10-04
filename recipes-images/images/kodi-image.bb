# Base this image on core-image-minimal

include kodi-image-base.inc

IMAGE_INSTALL += " \
	virtual/kodi \
	"
