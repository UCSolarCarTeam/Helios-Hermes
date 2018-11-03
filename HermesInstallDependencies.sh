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

( 
  cd /tmp
  git clone https://github.com/UCSolarCarTeam/Development-Resources.git
  cd Development-Resources/InstallScripts
  ./rabbitmq-setup.sh 
  ./googletest-setup.sh 
)

(
  mkdir -p ./build/.lib 
  cp /usr/local/lib/libgmock.a ./build/.lib
)