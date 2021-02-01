#pragma once
#include "Straw/Layer.h"
#include "Straw/Events/MouseEvent.h"
#include "Straw/Events/KeyEvent.h"
#include "Straw/Events/ApplicationEvent.h"

namespace Straw
{

	class STRAW_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& event) override;
	private:
		bool OnMouseButtonPressed(MouseButtonPressedEvent& event);
		bool OnMouseButtonReleased(MouseButtonReleasedEvent& event);
		bool OnMouseMoved(MouseMovedEvent& event);
		bool OnMouseScrolled(MouseScrollEvent& event);
		bool OnKeyPressed(KeyPressedEvent& event);
		bool OnKeyReleased(KeyReleasedEvent& event);
		bool OnKeyTyped(KeyTypedEvent& event);
		bool OnWindowResized(WindowResizeEvent& event);
	private:
		float m_Time = 0.f;
	};

}
