:: Compile yaml-cpp with CMake
cd AuroraUtilLib/vendor/yaml-cpp
if not exist build\ (
    mkdir build
)
cd build
cmake ..
cmake --build . --target ALL_BUILD --config Debug
cd ../../../../

cd AuroraUtilLib/vendor/yaml-cpp
if not exist build\ (
    mkdir build
)
cd build
cmake ..
cmake --build . --target ALL_BUILD --config Release
cd ../../../../

:: Compile CryptoPP with MSBuild for Windows | Other platforms to come later
cd AuroraMapleLib/vendor/cryptopp
if not exist x64\Output\Debug (
    MSBuild cryptest.sln /p:Configuration=Debug /p:Platform=x64
)
cd ../../../

cd AuroraMapleLib/vendor/cryptopp
if not exist x64\Output\Release (
    MSBuild cryptest.sln /p:Configuration=Release /p:Platform=x64
)
cd ../../../

::MSBuild ProjectAurora.sln /p:Configuration=Debug /p:Platform=x64
::MSBuild ProjectAurora.sln /p:Configuration=Release /p:Platform=x64
