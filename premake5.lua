workspace "ProjectAurora"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}


require "vscode"


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include dirs relative to root folder
IncludeDir = {}
IncludeDir["Boost"] = "C:/boost/boost_1_81_0"

IncludeDir["GLFW"]  = "AuroraEngineLib/vendor/glfw/include"
IncludeDir["GLAD"]  = "AuroraEngineLib/vendor/glad/include"
IncludeDir["glm"]   = "AuroraEngineLib/vendor/glm"
IncludeDir["ImGui"] = "AuroraEngineLib/vendor/imgui"

IncludeDir["SPDLog"]  = "AuroraEngineLib/vendor/spdlog/include"
IncludeDir["YAMLcpp"] = "AuroraEngineLib/vendor/yaml-cpp/include"

IncludeDir["AuroraEngineLib"] = "AuroraEngineLib/src"

LinkDir = {}
LinkDir["YAMLcpp"]  = "AuroraEngineLib/vendor/yaml-cpp/build/%{cfg.buildcfg}"

-- Includes the premake file for 3rd party libraries
include "AuroraEngineLib/vendor/glfw"
include "AuroraEngineLib/vendor/glad"
include "AuroraEngineLib/vendor/imgui"

project "AuroraEngineLib"
	location "AuroraEngineLib"
	kind "StaticLib"
	staticruntime "on"
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

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	filter "system:windows"
		systemversion "latest"
		defines
		{
			"PA_PLATFORM_WINDOWS",
			"PA_ASSERTS_ENABLED"
		}

	filter "configurations:Debug"
		defines "PA_DEBUG"
		runtime "Debug"
		symbols "on"
		links
		{
			"yaml-cppd.lib"
		}

	filter "configurations:Release"
		defines "PA_RELEASE"
		runtime "Release"
		optimize "on"
		links
		{
			"yaml-cpp.lib"
		}

	filter "configurations:Dist"
		defines "PA_DIST"
		runtime "Release"
		optimize "on"
		links
		{
			"yaml-cpp.lib"
		}
		
project "AuroraClient"
	location "AuroraClient"
	kind "ConsoleApp"
	staticruntime "on"
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
		"%{IncludeDir.Boost}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.SPDLog}"
	}

	links
	{
		"AuroraEngineLib",
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
		symbols "on"

	filter "configurations:Release"
		defines "PA_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "PA_DIST"
		runtime "Release"
		optimize "on"