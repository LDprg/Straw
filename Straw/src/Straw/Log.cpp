#include "Log.h"

namespace Straw
{
	std::shared_ptr <spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr <spdlog::logger> Log::s_ClientLogger;
	
	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: \t%v%$");

		s_CoreLogger = spdlog::stdout_color_mt("STRAW");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

}