
export SOURCE_DIR=/opt/axion/source
export INSTALL_DIR=/opt/axion/axionsdk
export BUILD_DIR=/opt/axion/build

mkdir -p $SOURCE_DIR
mkdir -p $INSTALL_DIR
mkdir -p $BUILD_DIR

git clone https://gitlab.kitware.com/cmb/cmb-superbuild.git $SOURCE_DIR
cd $SOURCE_DIR
git submodule update --init --recursive


cmake -GNinja \
    -DENABLE_python3:BOOL=ON \
    -DENABLE_pybind11:BOOL=ON \
    -DUSE_SYSTEM_qt5:BOOL=ON \
    -S $SOURCE_DIR \
    -B $BUILD_DIR                         \
    -Dsuperbuild_install_location=$INSTALL_DIR \
    -DDEVELOPER_MODE_smtk:BOOL=ON \
    -DENABLE_cmb:BOOL=OFF         \
    -DENABLE_cmbusersguide:BOOL=OFF \
    -DENABLE_paraview:BOOL=ON

cmake --build $BUILD_DIR 

