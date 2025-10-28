set -e
curl -Lo srslist.h https://raw.githubusercontent.com/throneproj/routeprofiles/refs/heads/rule-set/srslist.h
g++ a.cpp
mkdir rule-set ||:
cd rule-set
../a.out | python3 ../py.py


cd ..
protoc lib.proto --cpp_out=.
g++ test.cpp -o test `pkg-config --libs --cflags protobuf`
./test
cd rule-set
