 #!/usr/bin/env bash  
if [ "$(id -u)" != "0" ]; then
    echo "Permission Denied. Please run as root"
    exit 1
fi  

 apt-get update
 apt-get -y install \
    build-essential \
    libc6-i386 \
    libboost-chrono-dev \
    libboost-system-dev 

cd ..
mv Epsilon-Hermes ./src
mkdir -p Epsilon-Hermes/build/.lib/
mv src Epsilon-Hermes/
cd Epsilon-Hermes/src

    # install googletest and googlemock
    (cd /tmp
    git clone https://github.com/google/googletest.git 
     cp -r googletest/googletest/include/gtest /usr/local/include
     cp -r googletest/googlemock/include/gmock /usr/local/include
    (cd googletest &&
       g++ -std=c++11 
           -isystem googletest/include/
           -Igoogletest
           -isystem googlemock/include/
           -Igooglemock
           -pthread
           -c
           googlemock/src/gmock-all.cc &&
       g++ -std=c++11 
           -isystem googletest/include/
           -Igoogletest
           -isystem googlemock/include/
           -Igooglemock
           -pthread
           -c
           googletest/src/gtest-all.cc &&
       ar -rv libgmock.a gtest-all.o gmock-all.o ))
    
    cp /tmp/googletest/libgmock.a ../build/.lib/
    # install rabbitmq-c
    (cd /tmp
    git clone https://github.com/alanxz/rabbitmq-c
     cp rabbitmq-c/librabbitmq/*.h /usr/local/include/
    mkdir rabbitmq-c/build
    (cd rabbitmq-c/build && cmake .. && cmake --build .)
     cp rabbitmq-c/build/librabbitmq/librabbitmq.a /usr/local/lib/
     cp rabbitmq-c/build/librabbitmq/*.so* /usr/local/lib/)

    # install SimpleAmqpClient
    (cd /tmp
    git clone https://github.com/alanxz/SimpleAmqpClient
    mkdir SimpleAmqpClient/build
    (cd SimpleAmqpClient/build &&
       cmake -DRabbitmqc_INCLUDE_DIR=../../rabbitmq-c/librabbitmq
             -DRabbitmqc_LIBRARY=../../rabbitmq-c/build/librabbitmq
             .. &&
       make)
     mkdir /usr/local/include/SimpleAmqpClient
     cp SimpleAmqpClient/build/*.so* /usr/local/lib/
     cp SimpleAmqpClient/src/SimpleAmqpClient/*.h /usr/local/include/SimpleAmqpClient/)