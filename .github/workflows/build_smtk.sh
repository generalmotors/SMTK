export INSTALL_DIR=/opt/axion/axionsdk
cmake                                                               \
    -G Ninja                                                        \
    -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR                             \
    -DCMAKE_PREFIX_PATH="$INSTALL_DIR/lib/cmake/Boost-1.79.0;$INSTALL_DIR/lib/cmake/paraview-5.11"       \
    $SRC_DIR