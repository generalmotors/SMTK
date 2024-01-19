export INSTALL_DIR=/opt/axion/axionsdk
cmake                                                               \
    -G Ninja                                                        \
    -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR                             \
    $SRC_DIR