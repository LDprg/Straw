#pragma once

#include "Core.h"
#include "Events/Event.h"

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