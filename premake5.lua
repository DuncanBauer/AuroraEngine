workspace "ProjectAurora"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include dirs relative to root folder
IncludeDir = {}
IncludeDir["Boost"] = "C:/boost/boost_1_81_0"

IncludeDir["CryptoPP"] = "AuroraMapleLib/vendor"

IncludeDir["GLFW"] = "AuroraEngineLib/vendor/glfw/include"
IncludeDir["GLAD"] = "AuroraEngineLib/vendor/glad/include"
IncludeDir["glm"] = "AuroraEngineLib/vendor/glm"
IncludeDir["ImGui"] = "AuroraEngineLib/vendor/imgui"

IncludeDir["SPDLog"] = "AuroraEngineLib/vendor/spdlog/include"
IncludeDir["YAMLcpp"] = "AuroraEngineLib/vendor/yaml-cpp/include"

IncludeDir["AuroraEngineLib"] = "AuroraEngineLib/src"
IncludeDir["AuroraMapleLib"] = "AuroraMapleLib/src"

LinkDir = {}
LinkDir["CryptoPP"] = "AuroraMapleLib/vendor/cryptopp/x64/DLL_Output/%{cfg.buildcfg}"
LinkDir["YAMLcpp"] = "AuroraEngineLib/vendor/yaml-cpp/build/%{cfg.buildcfg}"

-- Includes the premake file for 3rd party libraries
include "AuroraEngineLib/vendor/glfw"
include "AuroraEngineLib/vendor/glad"
include "AuroraEngineLib/vendor/imgui"

project "AuroraEngineLib"
	location "AuroraEngineLib"
	kind "SharedLib"
	language "C++"
	cppdialect "C++20"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "AuroraEngineLibPCH.h"
	pchsource "AuroraEngineLib/src/AuroraEngineLibPCH.cpp"

	files
	{
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h"
	}

	includedirs
	{
		"%{IncludeDir.AuroraEngineLib}",
		"%{IncludeDir.SPDLog}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.YAMLcpp}"
	}

	libdirs
	{
		"%{LinkDir.YAMLcpp}"
	}

	links
	{
		"GLFW",
		"GLAD",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"PA_PLATFORM_WINDOWS",
			"PA_ASSERTS_ENABLED",
			"PA_ENGINE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/AuroraMapleClient"),
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/AuroraMapleServer"),
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/AuroraUnitTesting")
		}

	filter "configurations:Debug"
		defines "PA_DEBUG"
		runtime "Debug"
		staticruntime "Off"
		symbols "On"
		links
		{
			"yaml-cppd.lib"
		}

	filter "configurations:Release"
		defines "PA_RELEASE"
		runtime "Release"
		staticruntime "Off"
		optimize "On"
		links
		{
			"yaml-cpp.lib"
		}

		
project "AuroraMapleLib"
	location "AuroraMapleLib"
	kind "SharedLib"
	language "C++"
	cppdialect "C++20"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "AuroraMapleLibPCH.h"
	pchsource "AuroraMapleLib/src/AuroraMapleLibPCH.cpp"

	files
	{
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h"
	}

	includedirs
	{
		"%{IncludeDir.AuroraMapleLib}",
		"%{IncludeDir.Boost}",
		"%{IncludeDir.CryptoPP}",
		"%{IncludeDir.SPDLog}"
	}

	libdirs
	{
		"%{LinkDir.CryptoPP}"
	}

	links
	{
		"cryptopp.dll"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"PA_PLATFORM_WINDOWS",
			"PA_ASSERTS_ENABLED",
			"PA_MAPLE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/AuroraMapleClient"),
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/AuroraMapleServer"),
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/AuroraUnitTesting")
		}

	filter "configurations:Debug"
		defines "PA_DEBUG"
		runtime "Debug"
		staticruntime "Off"
		symbols "On"

	filter "configurations:Release"
		defines "PA_RELEASE"
		runtime "Release"
		staticruntime "Off"
		optimize "On"

		
project "AuroraMapleClient"
	location "AuroraMapleClient"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h"
	}

	includedirs
	{
		"%{IncludeDir.AuroraEngineLib}",
		"%{IncludeDir.AuroraMapleLib}",
		"%{IncludeDir.Boost}",
		"%{IncludeDir.CryptoPP}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.SPDLog}"
	}

	libdirs
	{
		"%{LinkDir.CryptoPP}"
	}

	links
	{
		"AuroraEngineLib",
		"AuroraMapleLib",
		"ImGui",
		"cryptopp.dll"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"PA_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "PA_DEBUG"
		runtime "Debug"
		staticruntime "Off"
		symbols "On"

	filter "configurations:Release"
		defines "PA_RELEASE"
		runtime "Release"
		staticruntime "Off"
		optimize "On"

		
project "AuroraMapleServer"
	location "AuroraMapleServer"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h"
	}

	includedirs
	{
		"%{IncludeDir.AuroraEngineLib}",
		"%{IncludeDir.AuroraMapleLib}",
		"%{IncludeDir.SPDLog}",
		"%{IncludeDir.Boost}",
		"%{IncludeDir.CryptoPP}"
	}

	libdirs
	{
		"%{LinkDir.CryptoPP}"
	}

	links
	{
		"AuroraEngineLib",
		"AuroraMapleLib",
		"cryptopp.dll"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"PA_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "PA_DEBUG"
		runtime "Debug"
		staticruntime "Off"
		symbols "On"

	filter "configurations:Release"
		defines "PA_RELEASE"
		runtime "Release"
		staticruntime "Off"
		optimize "On"


project "AuroraUnitTesting"
	location "AuroraUnitTesting"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h"
	}

	includedirs
	{
		"%{IncludeDir.AuroraEngineLib}",
		"%{IncludeDir.AuroraMapleLib}",
		"%{IncludeDir.SPDLog}",
		"%{IncludeDir.Boost}",
		"%{IncludeDir.CryptoPP}"
	}

	libdirs
	{
		"%{LinkDir.CryptoPP}"
	}

	links
	{
		"AuroraEngineLib",
		"AuroraMapleLib",
		"cryptopp.dll"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"PA_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "PA_DEBUG"
		runtime "Debug"
		staticruntime "Off"
		symbols "On"

	filter "configurations:Release"
		defines "PA_RELEASE"
		runtime "Release"
		staticruntime "Off"
		optimize "On"