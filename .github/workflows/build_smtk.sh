export INSTALL_DIR=/opt/axion/axionsdk
export BUILD_DIR=/opt/axion/smtk-build
export CCACHE_DIR=/opt/axion/ccache
ls $INSTALL_DIR/lib/cmake
git submodule update --init --recursive
cmake                                                               \
    -S $SRC_DIR                                                     \
    -B $BUILD_DIR                                                   \
    -G Ninja                                                        \
    -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR                             \
    -DCMAKE_PREFIX_PATH="$INSTALL_DIR/lib/cmake/Boost-1.79.0;$INSTALL_DIR/lib/cmake/paraview-5.11;$INSTALL_DIR/lib/cmake/paraview-5.11/vtk"       \
    $SRC_DIR \
    -DCMAKE_CXX_COMPILER_LAUNCHER=ccache  \
    -DBUILD_TESTING=OFF \
    -DQt5_DIR=$INSTALL_DIR/lib/cmake/Qt5 \
    -DDelaunay_ENABLE_TESTING=OFF \
    -DSMTK_ENABLE_POLYGON_SESSION=OFF \
    -DSMTK_ENABLE_MESH_SESSION=OFF \
    -DSMTK_ENABLE_TESTING=OFF

cmake --build $BUILD_DIR --target install