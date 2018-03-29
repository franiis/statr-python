cp /home/piotr/Projects/statr/build/libstatr.a lib
cp /home/piotr/Projects/statr/src/*.h lib

cython statr/statr.pyx -o statr/statr.bycython.c

python setup.py build_ext --build-lib statr
