workspace "Straw"
	architecture "x64"
	startproject "Sandbox"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Straw/vendor/glfw/include"
IncludeDir["Glad"] = "%{wks.location}/Straw/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Straw/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/Straw/vendor/glm"

include "Straw/vendor/glfw"
include "Straw/vendor/Glad"
include "Straw/vendor/imgui"

project "Straw"
	location "Straw"
	kind "StaticLib"
	language "C++"	

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "stpch.h"
	pchsource "%{prj.name}/src/stpch.cpp"

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp",
		"%{IncludeDir.glm}/glm/**.h"
	}

	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	defines "GLFW_INCLUDE_NONE"

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

		defines "ST_PLATFORM_WINDOWS"

	filter "configurations:Debug"
		defines{
			"ST_DEBUG",
			"ST_ENABLE_ASSERTS"
		}
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "ST_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "ST_DIST"
		runtime "Release"
		optimize "on"
	
project "Sandbox"
	location "Sandbox"

	kind "ConsoleApp"
	language "C++"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp",
		"%{IncludeDir.glm}/glm/**.h"
	}

	includedirs{
		"%{wks.location}/Straw/src",
		"%{wks.location}/Straw/vendor/spdlog/include",
		"%{IncludeDir.glm}"
	}

	links{
		"Straw"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"
		 
		defines{
			"ST_PLATFORM_WINDOWS" 
		}

	filter "configurations:Debug"
		defines{
			"ST_DEBUG",
			"ST_ENABLE_ASSERTS"
		}
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "ST_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "ST_DIST"
		runtime "Release"
		optimize "on"