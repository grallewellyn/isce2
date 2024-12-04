#!/bin/bash

export SCONS_CONFIG_DIR=/home/.isce
export PATH="/home/pkgs/isce/contrib/stack/topsStack:$PATH"
export ISCE_INSTALL_ROOT=/home/pkgs/isce
export PYTHONPATH=$ISCE_INSTALL_ROOT:$PYTHONPATH
export ISCE_HOME=$ISCE_INSTALL_ROOT/isce
export PATH=$ISCE_HOME/applications:$PATH

pushd /home/pkgs/isce2
scons install
