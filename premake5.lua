workspace "ProjectAurora"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include dirs relative to root folder
IncludeDir = {}
IncludeDir["Boost"] = "C:/boost/boost_1_81_0"
IncludeDir["CryptoPP"] = "AuroraMapleLib/vendor"
IncludeDir["GLFW"] = "AuroraEngineLib/vendor/glfw/include"
IncludeDir["SPDLog"] = "AuroraCoreLib/vendor/spdlog/include"
IncludeDir["YAMLcpp"] = "AuroraCoreLib/vendor/yaml-cpp/include"

IncludeDir["AuroraCoreLib"] = "AuroraCoreLib/src"
IncludeDir["AuroraEngineLib"] = "AuroraEngineLib/src"
IncludeDir["AuroraMapleLib"] = "AuroraMapleLib/src"

LinkDir = {}
LinkDir["CryptoPP"] = "AuroraMapleLib/vendor/cryptopp/x64/Output/%{cfg.buildcfg}"
LinkDir["YAMLcpp"] = "AuroraCoreLib/vendor/yaml-cpp/build/%{cfg.buildcfg}"

-- Includes the premake file for 3rd party libraries
include "AuroraEngineLib/vendor/glfw"

project "AuroraCoreLib"
	location "AuroraCoreLib"
	kind "SharedLib"
	language "C++"
	cppdialect "C++20"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "AuroraCoreLibPCH.h"
	pchsource "AuroraCoreLib/src/AuroraCoreLibPCH.cpp"

	files
	{
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h"
	}

	includedirs
	{
		"%{IncludeDir.AuroraCoreLib}",
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
			"PA_CORE_BUILD_DLL"
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

	filter "configurations:Dist"
		defines "PA_DIST"
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
		"%{IncludeDir.AuroraCoreLib}",
		"%{IncludeDir.AuroraEngineLib}",
		"%{IncludeDir.SPDLog}",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"AuroraCoreLib",
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		staticruntime "Off"
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
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "PA_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "PA_DIST"
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
		"%{IncludeDir.AuroraCoreLib}",
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
		"AuroraCoreLib",
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

	filter "configurations:Dist"
		defines "PA_DIST"
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
		"%{IncludeDir.AuroraCoreLib}",
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
		"AuroraCoreLib",
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

	filter "configurations:Dist"
		defines "PA_DIST"
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
		"%{IncludeDir.AuroraCoreLib}",
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
		"AuroraCoreLib",
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

	filter "configurations:Dist"
		defines "PA_DIST"
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
		"%{IncludeDir.AuroraCoreLib}",
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
		"AuroraCoreLib",
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

	filter "configurations:Dist"
		defines "PA_DIST"
		buildoptions "/MD"
		optimize "On"