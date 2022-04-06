
# These vairables are used only for building Matehmatiques
# ie are not needed by the end user code
#
#  VERSION_FILE_MATHQ should be a bash file with: export VERSION_MATHQ=X.X
VERSION_FILE_MATHQ = $(DIR_MATHQ)/versioning/version.mathq
VERSION_MATHQ = `. $(VERSION_FILE_MATHQ) && echo "$${VERSION_MATHQ}"`
TAG_FILE_MATHQ = $(DIR_MATHQ)/versioning/tag.mathq
TAG_MATHQ = `cat $(TAG_FILE_MATHQ)`
TAG_ANNOTATION_FILE = $(DIR_MATHQ)/versioning/tag.annotation.mathq
VERSION_HEADER_FILE_MATHQ = $(DIR_MATHQ)/include/version_mathq.h