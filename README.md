# README.md

Hermes is a background process on the Schulich Delta's onboard computer. 
It rebroadcasts a data feed from the Central Communication System and also logs the data. 

The name is inspired by the Olympian god Hermes who is portrayed as a messenger and scribe of the gods.

## Testing

Testing the Schulich Delta Desktop Hermes is done with googletest and googlemock, the gmock and gtest header files need to be in your include path /usr/local/include or /usr/include.
You must compile the library that has the definitions yourself.
Meaning you need a `libgmock.a` archive file in the test directory in order to compile the tests.

To create a `libgmock.a` file in a Linux system follow these instructions in an arbitrary dir.

1. Get the googletest and googlemock source code:
    `git clone https://github.com/google/googletest.git`

2. Go into the cloned directory
    `cd googletest/`

3. Compile googletest:
    `g++ -isystem googletest/include/ -Igoogletest -isystem googlemock/include/ -Igooglemock -pthread -c googletest/src/gtest-all.cc`

4. Compile googlemock:
    `g++ -isystem googletest/include/ -Igoogletest -isystem googlemock/include/ -Igooglemock -pthread -c googlemock/src/gmock-all.cc`

5. Collect both the resulting .o files into an archive file:
    `ar -rv libgmock.a gtest-all.o gmock-all.o`

Congratulations! You now have a `libgmock.a` archive file, include it in the `../build/.lib/` directory and you should be good to go, run `qmake` then `make` in the Tests directory to check if you can compile the tests. If you can't find the `.lib`, use `ls -a` to show it.

To get the Settings test to pass, testconfig.ini must be copied beside the Tests binary. 
Use the following command in the root directory
    cp testconfig.ini ../build/.tests/

Both gmock and the gtest folders need to be placed in the `/usr/local/include` system directory. 
