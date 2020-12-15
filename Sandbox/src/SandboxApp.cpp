#include <Straw.h>

class Sandbox :public Straw::Application
{
public:
	Sandbox()
	{
		PushOverlay(new Straw::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Straw::Application* Straw::CreateApplication()
{
	return new Sandbox();
}