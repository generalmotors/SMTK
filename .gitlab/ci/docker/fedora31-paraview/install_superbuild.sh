#!/bin/sh

set -e

readonly superbuild_ref="$1"
shift

readonly workdir="$HOME/code/cmb"
git clone --recursive https://gitlab.kitware.com/cmb/cmb-superbuild.git "$workdir/src-sb"
git -C "$workdir/src-sb" checkout "$superbuild_ref"
git -C "$workdir/src-sb" submodule update --recursive --init
mkdir -p "$workdir/build-sb"
cd "$workdir/build-sb"

cmake -GNinja \
    -DDEVELOPER_MODE_smtk:BOOL=ON \
    -DENABLE_cmb:BOOL=OFF \
    -DENABLE_cmbusersguide:BOOL=OFF \
    -DENABLE_smtkprojectmanager:BOOL=OFF \
    -DENABLE_smtkresourcemanagerstate:BOOL=OFF \
    -DENABLE_paraview:BOOL=ON \
    -DSUPPRESS_szip_OUTPUT:BOOL=OFF \
    -DUSE_SYSTEM_qt5:BOOL=ON \
    "-D__BUILDBOT_INSTALL_LOCATION:PATH=$SUPERBUILD_PREFIX" \
    "$workdir/src-sb"
ninja
cp smtk-developer-config.cmake "$SUPERBUILD_PREFIX"

rm -rf "$workdir"
