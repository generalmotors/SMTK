export INSTALL_DIR=/opt/axion/axionsdk
cmake                                                               \
    -G Ninja                                                        \
    -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR                             \
    -DCMAKE_PREFIX_PATH="$INSTALL_DIR/lib/cmake/Boost-1.79.0"       \
    $SRC_DIR