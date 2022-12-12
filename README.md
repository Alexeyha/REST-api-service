# Cloud service
## Features 
* Emulated cloud service
* Opportunity to get/add/delete/change information in json format about files
* Service check correctness of requests
* Service send responce about files 
## Install 
### Dependencies and submodules
* [PostgreSQL](https://www.postgresql.org/)
* [Json](https://github.com/nlohmann/json)
* [Boost](https://www.boost.org)
* [libpqxx](https://github.com/jtv/libpqxx)
### Linux
```bash
sudo apt-get install libboost-all-dev
git clone https://github.com/Alexeyha/REST-api-service --recursive
mkdir build
cmake -S . -B build -DCMAKE_CXX_COMPILER="g++-10"
cmake --build build/
```
### Macos
```bash
brew install boost
git clone https://github.com/Alexeyha/REST-api-service --recursive
mkdir build
cmake -S . -B build -DCMAKE_CXX_COMPILER="g++-10"
cmake --build build/
```
