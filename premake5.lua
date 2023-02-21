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
IncludeDir["GLFW"] = "AuroraEngineLib/vendor/glfw/include"
IncludeDir["Boost"] = "C:/boost/boost_1_81_0"

-- Includes the premake file for GLFW
include "AuroraEngineLib/vendor/glfw"

project "AuroraCoreLib"
	location "AuroraCoreLib"
	kind "SharedLib"
	language "C++"

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
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
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
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/AuroraMapleServer")
		}

	filter "configurations:Debug"
		defines "PA_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PA_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PA_DIST"
		optimize "On"


project "AuroraEngineLib"
	location "AuroraEngineLib"
	kind "SharedLib"
	language "C++"

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
		"%{prj.name}/src",
		"AuroraCoreLib/src",
		"AuroraCoreLib/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib",
		"AuroraCoreLib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
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
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/AuroraMapleServer")
		}

	filter "configurations:Debug"
		defines "PA_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PA_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PA_DIST"
		optimize "On"

		
project "AuroraMapleLib"
	location "AuroraMapleLib"
	kind "SharedLib"
	language "C++"

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
		"%{prj.name}/src",
		"AuroraCoreLib/src",
		"AuroraCoreLib/vendor/spdlog/include",
		-- "%{IncludeDir.Boost}",
	}

	links
	{
		"AuroraCoreLib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
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
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/AuroraMapleServer")
		}

	filter "configurations:Debug"
		defines "PA_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PA_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PA_DIST"
		optimize "On"

project "AuroraMapleClient"
	location "AuroraMapleClient"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h"
	}

	includedirs
	{
		"AuroraCoreLib/src",
		"AuroraCoreLib/vendor/spdlog/include",
		"AuroraEngineLib/src",
		"AuroraMapleLib/src",
	}

	links
	{
		"AuroraCoreLib",
		"AuroraEngineLib",
		"AuroraMapleLib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PA_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "PA_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PA_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PA_DIST"
		optimize "On"

		
project "AuroraMapleServer"
	location "AuroraMapleServer"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h"
	}

	includedirs
	{
		"AuroraCoreLib/src",
		"AuroraCoreLib/vendor/spdlog/include",
		"AuroraEngineLib/src",
		"AuroraMapleLib/src",
	}

	links
	{
		"AuroraCoreLib",
		"AuroraEngineLib",
		"AuroraMapleLib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PA_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "PA_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PA_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PA_DIST"
		optimize "On"