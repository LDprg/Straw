#include "stpch.h"
#include "ImGuiLayer.h"

#include "Straw/Application.h"

#include "imgui.h"

#include <examples/imgui_impl_opengl3.cpp>
#include <examples/imgui_impl_glfw.cpp>

//#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"
#include <examples/imgui_impl_glfw.h>

// Temporary
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Straw
{
	ImGuiLayer::ImGuiLayer()
		:Layer("ImGuiLayer")
	{
	}

	ImGuiLayer::~ImGuiLayer()
	{
	}

	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		// Temporary
		io.KeyMap[ImGuiKey_Tab] = ST_KEY_TAB;
		io.KeyMap[ImGuiKey_LeftArrow] = ST_KEY_LEFT;
		io.KeyMap[ImGuiKey_RightArrow] = ST_KEY_RIGHT;
		io.KeyMap[ImGuiKey_UpArrow] = ST_KEY_UP;
		io.KeyMap[ImGuiKey_DownArrow] = ST_KEY_DOWN;
		io.KeyMap[ImGuiKey_PageUp] = ST_KEY_PAGE_UP;
		io.KeyMap[ImGuiKey_PageDown] = ST_KEY_PAGE_DOWN;
		io.KeyMap[ImGuiKey_Home] = ST_KEY_HOME;
		io.KeyMap[ImGuiKey_End] = ST_KEY_END;
		io.KeyMap[ImGuiKey_Insert] = ST_KEY_INSERT;
		io.KeyMap[ImGuiKey_Delete] = ST_KEY_DELETE;
		io.KeyMap[ImGuiKey_Backspace] = ST_KEY_BACKSPACE;
		io.KeyMap[ImGuiKey_Space] = ST_KEY_SPACE;
		io.KeyMap[ImGuiKey_Enter] = ST_KEY_ENTER;
		io.KeyMap[ImGuiKey_Escape] = ST_KEY_ESCAPE;
		io.KeyMap[ImGuiKey_KeyPadEnter] = ST_KEY_KP_ENTER;
		io.KeyMap[ImGuiKey_A] = ST_KEY_A;
		io.KeyMap[ImGuiKey_C] = ST_KEY_C;
		io.KeyMap[ImGuiKey_V] = ST_KEY_V;
		io.KeyMap[ImGuiKey_X] = ST_KEY_X;
		io.KeyMap[ImGuiKey_Y] = ST_KEY_Y;
		io.KeyMap[ImGuiKey_Z] = ST_KEY_Z;

		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows

		ImGuiStyle& style = ImGui::GetStyle();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}

		Application& app = Application::Get();
		GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());

		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 410");

	}

	void ImGuiLayer::OnDetach()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	void ImGuiLayer::OnUpdate()
	{
		Application& app = Application::Get();
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
		m_Time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup_current_context);
		}
	}
}