#!/usr/bin/env bash

if [ "$#" -ne 1 ]; then
	echo "Illegal number of parameters: please provide location of qmk folder"
fi

QMKPATH=$(readlink -f "$1")

# Absolute path to this script
SCRIPT=$(readlink -f "$0")
# Absolute path this script is in
SCRIPTPATH=$(dirname "$SCRIPT")

ln -s $SCRIPTPATH $QMKPATH/keyboards/ferris/keymaps/atred
