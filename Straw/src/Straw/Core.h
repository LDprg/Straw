#pragma once

#ifdef ST_PLATFORM_WINDOWS
	#ifdef ST_BUILD_DLL
		#define STRAW_API __declspec(dllexport)
	#else
		#define STRAW_API __declspec(dllimport)
	#endif
#else
	#error Straw has only Windows support
#endif
