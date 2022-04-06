
# These vairables are used only for building Matehmatiques
# ie are not needed by the end user code
#
#  VERSION_FILE_MATHQ should be a bash file with: export VERSION_MATHQ=X.X

# static variables
VERSION_FILE_MATHQ := $(DIR_MATHQ)/versioning/version.master.record.mathq
TAG_FILE_MATHQ := $(DIR_MATHQ)/versioning/tag.mathq.out.txt
TAG_ANNOTATION_FILE := $(DIR_MATHQ)/versioning/tag.annotation.mathq.out.txt
VERSION_HEADER_FILE_MATHQ := $(DIR_MATHQ)/include/version_mathq.h

# dynamic variables
VERSION_MATHQ = `. $(VERSION_FILE_MATHQ) && echo "$${VERSION_MATHQ}"`
TAG_MATHQ = `cat $(TAG_FILE_MATHQ)`
