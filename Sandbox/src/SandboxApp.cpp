#include <Straw.h>

class ExampleLayer : public Straw::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		
	}

	void OnEvent(Straw::Event& event) override 
	{
	}
};

class Sandbox :public Straw::Application
{
public:
	Sandbox()
	{
		PushOverlay(new ExampleLayer());
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