#pragma once

#include <Straw/Core.h>

namespace Straw
{

	class STRAW_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

}