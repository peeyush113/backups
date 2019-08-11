#!/bin/bash


# (c) 2008 The Board of Trustees of the University of Illinois.

CONFIRM=0;

echo -n "Desired MCUDA install path (/MCUDA appended): ";
read INSTALL_DIR;
echo -n "Existing CUDA installation directory path: ";
read CUDA_DIR;
echo -n "Choice of MCUDA library (omp/pthread/serial): ";
read MCUDA_LIB;
echo -n "Library and final source code compiler for MCUDA: ";
read MCUDA_CC;

while [ $CONFIRM -ne 1 ] ; do
  echo "";
  echo "";
  echo "Confirm setup parameters...............................";
  echo "MCUDA will be installed to: $INSTALL_DIR";
  echo "CUDA is installed in: $CUDA_DIR";
  echo "MCUDA library implementation: $MCUDA_LIB";
  echo "Path to MCUDA library and application compiler: $MCUDA_CC";
  echo -n "Confirm (y/n): ";
  read CONFIRM_INPUT;
  case $CONFIRM_INPUT in
  [nN]*)
    echo "MCUDA installation aborted"
    exit 1;
    ;;
  [yY]*)
    CONFIRM=1;
    ;;
  esac
done

echo "Verifying setup parameters...";
if [ ! -d $INSTALL_DIR ]; then
  echo "Error: Directory $INSTALL_DIR does not exist";
  exit 2;
fi

if [ ! -w $INSTALL_DIR ]; then
  echo "Error: Installation directory $INSTALL_DIR must be writable";
  exit 2;
fi

if [ ! -f "$CUDA_DIR/include/device_functions.h" ]; then
  echo "Error finding $CUDA_DIR/include/device_functions.h: aborting";
  exit 3;
fi

if [ ! -w "$CUDA_DIR/include/device_functions.h" ]; then
  echo "Error: requires write permissions to $CUDA_DIR/include/device_functions.h";
  echo "Aborting";
  exit 3;
fi

if [ ! -f "$CUDA_DIR/include/host_defines.h" ]; then
  echo "Error finding $CUDA_DIR/include/host_defines.h: aborting";
  exit 3;
fi

if [ ! -w "$CUDA_DIR/include/host_defines.h" ]; then
  echo "Error: requires write permissions to $CUDA_DIR/include/host_defines.h";
  echo "Aborting";
  exit 3;
fi

case $MCUDA_LIB in
pthread)
  ;;
omp)
  ;;
serial)
  ;;
*)
  echo "Error: unsupported MCUDA library implementation \"$MCUDA_LIB\"";
  exit 4;
  ;;
esac
  

# unpack MCUDA into INSTALL_DIR
if [ $# -eq 0 ] ; then
  tar -C $INSTALL_DIR -zxf MCUDA.tgz 
else 
  if [ $1 == local ] ; then
    mkdir $INSTALL_DIR/MCUDA;
    mkdir $INSTALL_DIR/MCUDA/bin;
    mkdir $INSTALL_DIR/MCUDA/src;
    mkdir $INSTALL_DIR/MCUDA/include;
    mkdir $INSTALL_DIR/MCUDA/lib;
    cp bin/* $INSTALL_DIR/MCUDA/bin;
    cp src/* $INSTALL_DIR/MCUDA/src;
    cp include/* $INSTALL_DIR/MCUDA/include;
    cp lib/* $INSTALL_DIR/MCUDA/lib;
  fi;
fi;

# edit MCUDA files to match the user parameters
cd $INSTALL_DIR/MCUDA/bin;
sed -i 's:MCUDA_DIR:'$INSTALL_DIR'/MCUDA:g' mcuda;
sed -i 's:CUDA_INSTALL_DIR:'$CUDA_DIR':g' mcuda;
sed -i 's:LIB_TYPE:'$MCUDA_LIB':g' mcuda;

sed -i 's:MCUDA_DIR:'$INSTALL_DIR'/MCUDA:g' mcc;
sed -i 's:CUDA_INSTALL_DIR:'$CUDA_DIR':g' mcc;
sed -i 's:LIB_TYPE:'$MCUDA_LIB':g' mcc;
sed -i 's:USR_CC:'$MCUDA_CC':g' mcc;


if [ $MCUDA_LIB == pthread ] ; then 
cd ../include;
sed -i '/PTHREADS/ i\
#define MCUDA_PTHREADS
' mcuda.h;
fi


cd ../src;
sed -i 's:USER_DEFINED_CC:'$MCUDA_CC':g' Makefile;
sed -i 's:MCUDA_DIR:'$INSTALL_DIR'/MCUDA:g' Makefile;
sed -i 's:CUDA_INSTALL_DIR:'$CUDA_DIR':g' Makefile;
sed -i 's:LIB_TYPE:'$MCUDA_LIB':g' Makefile;

make;


# update the CUDA header file(s)

# these are not sound operations, and should they fail, it is probably 
# easier just to edit the headers by hand
sed -i '/^__func__.*__syncthreads/ {
i\
#if !defined(__MCUDA__)
N
N
N
N
a\
#endif
}' $CUDA_DIR/include/device_functions.h

sed -i '/^#define __device__ / {
i\
#if !defined(__MCUDA__)
N
N
N
N
N
N
N
N
N
N
N
a\
#endif
}' $CUDA_DIR/include/host_defines.h



echo "Installation attempt complete."

