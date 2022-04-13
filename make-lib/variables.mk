
# These vairables are used only for building Matehmatiques
# ie are not needed by the end user code
#
#  COMPATIBLE_VERSION_MATHQ_FILE should be a bash file with: export COMPATIBLE_VERSION_MATHQ=X.X

# static variables
TAG_ANNOTATION_FILE := $(DIR_MATHQ)/versioning/tag.annotation.mathq.out.txt
VERSION_HEADER_FILE_MATHQ := $(DIR_MATHQ)/include/version_mathq.h
COMPATIBLE_VERSION_MATHQ_FILE := $(DIR_MATHQ)/versioning/compatible.version.master.record.mathq

# dynamic variables
COMPATIBLE_VERSION_MATHQ = `. $(COMPATIBLE_VERSION_MATHQ_FILE) && echo "$${COMPATIBLE_VERSION_MATHQ}"`

