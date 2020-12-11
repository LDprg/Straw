#include <Straw.h>

class Sandbox :public Straw::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Straw::Application* Straw::CreateApplication()
{
	return new Sandbox();
}