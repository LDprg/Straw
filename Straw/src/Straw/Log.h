#pragma once

#include "Core.h"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Straw
{
	class STRAW_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()
		{
			return s_CoreLogger;
		}

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger()
		{
			return s_ClientLogger;
		}

	private:
		static std::shared_ptr <spdlog::logger> s_CoreLogger;
		static std::shared_ptr <spdlog::logger> s_ClientLogger;
	};
}

#define ST_CORE_TRACE(...)	::Straw::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ST_CORE_INFO(...)	::Straw::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ST_CORE_WARN(...)	::Straw::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ST_CORE_ERROR(...)	::Straw::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ST_CORE_FATAL(...)	::Straw::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define ST_TRACE(...)		::Straw::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ST_INFO(...)		::Straw::Log::GetClientLogger()->info(__VA_ARGS__)
#define ST_WARN(...)		::Straw::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ST_ERROR(...)		::Straw::Log::GetClientLogger()->error(__VA_ARGS__)
#define ST_FATAL(...)		::Straw::Log::GetClientLogger()->critical(__VA_ARGS__)