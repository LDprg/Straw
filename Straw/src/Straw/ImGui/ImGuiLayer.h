#pragma once
#include "Straw/KeyCodes.h"
#include "Straw/Layer.h"
#include "Straw/Events/MouseEvent.h"
#include "Straw/Events/KeyEvent.h"
#include "Straw/Events/ApplicationEvent.h"

namespace Straw
{
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
	private:
		float m_Time = 0.f;
	};
}
