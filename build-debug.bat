:: Compile yaml-cpp with CMake
cd AuroraCoreLib/vendor/yaml-cpp
if not exist build\ (
    mkdir build
)
cd build
cmake ..
cmake --build . --target ALL_BUILD --config Debug
cd ../../../../

cd AuroraMapleLib/vendor/cryptopp
MSBuild cryptest.sln /p:Configuration=Debug /p:Platform=x64

cd ../../../
MSBuild ProjectAurora.sln /p:Configuration=Debug /p:Platform=x64

PAUSE