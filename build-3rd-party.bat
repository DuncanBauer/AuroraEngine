:: Compile spdlog with CMake
cd AuroraEngine/vendor/spdlog
if not exist build\ (
    mkdir build
)
cd build
cmake ..
cmake --build . --target ALL_BUILD --config Debug
cmake --build . --target ALL_BUILD --config Release
cd ../../../../



:: Compile yaml-cpp with CMake
cd AuroraEngine/vendor/yaml-cpp
if not exist build\ (
    mkdir build
)
cd build
cmake ..
cmake --build . --target ALL_BUILD --config Debug
cmake --build . --target ALL_BUILD --config Release
cd ../../../../