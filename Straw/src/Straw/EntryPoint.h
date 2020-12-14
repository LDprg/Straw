#pragma once

#ifdef ST_PLATFORM_WINDOWS

namespace Straw
{
	extern Application* CreateApplication();
}

int main(int argc, char** argv)
{
	Straw::Log::Init();

	ST_CORE_TRACE("Log Initialised!");

	auto app = Straw::CreateApplication();

	app->Run();

	delete app;
}

#endif 
