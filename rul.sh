set -e
curl -Lo srslist.h https://raw.githubusercontent.com/throneproj/routeprofiles/refs/heads/rule-set/srslist.h
g++ a.cpp
mkdir rule-set ||:
cd rule-set
../a.out | python3 ../py.py

cd ..
git clone --depth 1 --single-branch --branch profile https://github.com/throneproj/routeprofiles.git
cd routeprofiles
rm -fv README.md
rm -rfv .git

cd ..
mkdir routes
cd routes
curl -s https://api.github.com/repos/throneproj/routeprofiles/releases/latest \
  | grep "browser_download_url" \
  | cut -d '"' -f 4 \
  | xargs -n 1 curl -LO
cp ../rule-set/srslist.json ./rule-set.json

cd ..
protoc lib.proto --cpp_out=.
g++ test.cpp -o test `pkg-config --libs --cflags protobuf`
./test


