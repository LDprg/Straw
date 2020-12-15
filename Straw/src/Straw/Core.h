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

#ifdef ST_ENABLE_ASSERTS
	#define ST_ASSERT(x, ...) {if(!(x)){ST_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define ST_CORE_ASSERT(x, ...) {if(!(x)){ST_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define ST_ASSERT(x, ...)
	#define ST_CORE_ASSERT(x, ...)
#endif

#ifdef ST_ENABLE_ASSERTS
#define ST_VERIFY(x, ...) ST_ASSERT(x, __VA_ARGS__)
#define ST_CORE_VERIFY(x, ...) ST_CORE_ASSERT(x, __VA_ARGS__)
#else
#define ST_VERIFY(x, ...) x
#define ST_CORE_VERIFY(x, ...) x
#endif

#define ST_BIND_EVENT_FN(func) std::bind(&func, this, std::placeholders::_1)

#define BIT(x) (1 << (x))