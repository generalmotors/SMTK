export INSTALL_DIR=/opt/axion/axionsdk
export SRC_DIR= ${{ github.workspace }}
cmake                                                               \
    -G Ninja                                                        \
    -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR                             \
    $SRC_DIR