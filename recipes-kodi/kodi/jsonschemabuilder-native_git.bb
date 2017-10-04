
include kodi.inc
FILESPATH =. "${FILE_DIRNAME}/jsonschemabuilder-files:"

inherit cmake gettext pythonnative native
S = "${WORKDIR}/git"

SRCREV = "7fc6da0c87414d2ba20055e084adc10546a15b7c"
OECMAKE_SOURCEPATH = "${S}/tools/depends/native/JsonSchemaBuilder"
DEPENDS = " \
  "

OECMAKE_FIND_ROOT_PATH_MODE_PROGRAM = "BOTH"

EXTRA_OECMAKE_append = " \
  -DCORE_SOURCE_DIR=${S} \
"

do_install() {
  install -m 0755 -d ${D}${bindir}
  install -m 0755 ${B}/JsonSchemaBuilder ${D}${bindir}
}
