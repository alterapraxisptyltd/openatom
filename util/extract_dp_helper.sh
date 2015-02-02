#! /bin/bash

#
# Extract the drm_dp_helper.[ch] files from a linux tree
# and convert them to a format usable in userspace or coreboot.
#
# Usage
#	sh extract_dp_helper.sh <path/to/linux/sources>
#
# It outputs the drm_dp_helper file in the working directory.
#

DEST=$(pwd)
HEADER=drm_dp_helper.h
SOURCE=drm_dp_helper.c

HOME=$(dirname "${BASH_SOURCE[0]}")

SPATCH=spatch

echo Hello

cp $1/include/drm/$HEADER $DEST
cp $1/drivers/gpu/drm/$SOURCE $DEST

$SPATCH -sp_file $HOME/dp_helper.spatch \
	--macro-file-builtins $HOME/moo.h \
	-in_place $DEST/$SOURCE $DEST/$HEADER

echo $PWD
