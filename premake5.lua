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
IncludeDir["GLFW"] = "%{wks.location}/Straw/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Straw/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Straw/vendor/imgui"

include "Straw/vendor/GLFW"
include "Straw/vendor/Glad"
include "Straw/vendor/imgui"

project "Straw"
	location "Straw"
	kind "SharedLib"
	language "C++"	

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "stpch.h"
	pchsource "%{prj.name}/src/stpch.cpp"

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
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

		defines{
			"ST_PLATFORM_WINDOWS",
			"ST_BUILD_DLL"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} %{wks.location}/bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines{
			"ST_DEBUG",
			"ST_ENABLE_ASSERTS"
		}
		runtime "Debug"
		buildoptions "/MDd"
		symbols "on"

	filter "configurations:Release"
		defines "ST_RELEASE"
		runtime "Release"
		buildoptions "/MD"
		optimize "on"

	filter "configurations:Dist"
		defines "ST_DIST"
		runtime "Release"
		buildoptions "/MD"
		optimize "on"
	
project "Sandbox"
	location "Sandbox"

	kind "ConsoleApp"
	language "C++"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{wks.location}/Straw/src",
		"%{wks.location}/Straw/vendor/spdlog/include"
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
		buildoptions "/MDd"
		symbols "on"

	filter "configurations:Release"
		defines "ST_RELEASE"
		runtime "Release"
		buildoptions "/MD"
		optimize "on"

	filter "configurations:Dist"
		defines "ST_DIST"
		runtime "Release"
		buildoptions "/MD"
		optimize "on"