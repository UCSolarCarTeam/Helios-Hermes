#
#-------------------------------------------------

qmake
./format.sh
make all -j8
make check
