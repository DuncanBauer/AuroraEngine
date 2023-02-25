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
IncludeDir["ImGui"] = "AuroraEngineLib/vendor/imgui"

IncludeDir["SPDLog"] = "AuroraUtilLib/vendor/spdlog/include"
IncludeDir["YAMLcpp"] = "AuroraUtilLib/vendor/yaml-cpp/include"

IncludeDir["AuroraUtilLib"] = "AuroraUtilLib/src"
IncludeDir["AuroraEngineLib"] = "AuroraEngineLib/src"
IncludeDir["AuroraMapleLib"] = "AuroraMapleLib/src"

LinkDir = {}
LinkDir["CryptoPP"] = "AuroraMapleLib/vendor/cryptopp/x64/Output/%{cfg.buildcfg}"
LinkDir["YAMLcpp"] = "AuroraUtilLib/vendor/yaml-cpp/build/%{cfg.buildcfg}"

-- Includes the premake file for 3rd party libraries
include "AuroraEngineLib/vendor/glfw"
include "AuroraEngineLib/vendor/glad"
include "AuroraEngineLib/vendor/imgui"

project "AuroraUtilLib"
	location "AuroraUtilLib"
	kind "SharedLib"
	language "C++"
	cppdialect "C++20"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "AuroraUtilLibPCH.h"
	pchsource "AuroraUtilLib/src/AuroraUtilLibPCH.cpp"

	files
	{
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h"
	}

	includedirs
	{
		"%{IncludeDir.AuroraUtilLib}",
		"%{IncludeDir.SPDLog}",
		"%{IncludeDir.YAMLcpp}"
	}

	libdirs
	{
		"%{LinkDir.YAMLcpp}"
	}

	filter "system:windows"
		staticruntime "Off"
		systemversion "latest"

		defines
		{
			"PA_PLATFORM_WINDOWS",
			"PA_ASSERTS_ENABLED",
			"PA_UTIL_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/AuroraEngineLib"),
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/AuroraMapleLib"),
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/AuroraMapleClient"),
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/AuroraMapleServer"),
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/AuroraUnitTesting")
		}

	filter "configurations:Debug"
		defines "PA_DEBUG"
		buildoptions "/MDd"
		symbols "On"

		links
		{
			"yaml-cppd.lib"
		}

	filter "configurations:Release"
		defines "PA_RELEASE"
		buildoptions "/MD"
		optimize "On"

		links
		{
			"yaml-cpp.lib"
		}

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
		"%{IncludeDir.AuroraUtilLib}",
		"%{IncludeDir.AuroraEngineLib}",
		"%{IncludeDir.SPDLog}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"AuroraUtilLib",
		"GLFW",
		"GLAD",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		staticruntime "Off"
		systemversion "latest"

		defines
		{
			"PA_PLATFORM_WINDOWS",
			"PA_ASSERTS_ENABLED",
			"PA_ENGINE_BUILD_DLL",
			"IMGUI_IMPL_OPENGL_LOADER_CUSTOM"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/AuroraMapleClient"),
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/AuroraMapleServer"),
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/AuroraUnitTesting")
		}

	filter "configurations:Debug"
		defines "PA_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "PA_RELEASE"
		buildoptions "/MD"
		optimize "On"

		
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
		"%{IncludeDir.AuroraUtilLib}",
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
		"AuroraUtilLib",
		"cryptlib.lib"
	}

	filter "system:windows"
		staticruntime "Off"
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
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "PA_RELEASE"
		buildoptions "/MD"
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
		"%{IncludeDir.AuroraUtilLib}",
		"%{IncludeDir.AuroraEngineLib}",
		"%{IncludeDir.AuroraMapleLib}",
		"%{IncludeDir.Boost}",
		"%{IncludeDir.CryptoPP}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.SPDLog}"
	}

	libdirs
	{
		"%{LinkDir.CryptoPP}"
	}

	links
	{
		"AuroraUtilLib",
		"AuroraEngineLib",
		"AuroraMapleLib",
		"ImGui",
		"cryptlib.lib"
	}

	filter "system:windows"
		staticruntime "Off"
		systemversion "latest"

		defines
		{
			"PA_PLATFORM_WINDOWS",
			"IMGUI_IMPL_OPENGL_LOADER_CUSTOM"
		}

	filter "configurations:Debug"
		defines "PA_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "PA_RELEASE"
		buildoptions "/MD"
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
		"%{IncludeDir.AuroraUtilLib}",
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
		"AuroraUtilLib",
		"AuroraEngineLib",
		"AuroraMapleLib",
		"cryptlib.lib"
	}

	filter "system:windows"
		staticruntime "Off"
		systemversion "latest"

		defines
		{
			"PA_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "PA_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "PA_RELEASE"
		buildoptions "/MD"
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
		"%{IncludeDir.AuroraUtilLib}",
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
		"AuroraUtilLib",
		"AuroraEngineLib",
		"AuroraMapleLib",
		"cryptlib.lib"
	}

	filter "system:windows"
		staticruntime "Off"
		systemversion "latest"

		defines
		{
			"PA_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "PA_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "PA_RELEASE"
		buildoptions "/MD"
		optimize "On"