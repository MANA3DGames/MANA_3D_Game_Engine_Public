#ifndef IMGUI_MANAGER_H
#define IMGUI_MANAGER_H

// ImGUI Includes
#include <ImGui\imgui.h>
#include <ImGui\imgui_impl_glfw.h>
#include "ImGui\imgui_impl_opengl3.h"
#include <stdio.h>


// About OpenGL function loaders: modern OpenGL doesn't have a standard header file and requires individual function pointers to be loaded manually.
// Helper libraries are often used for this purpose! Here we are supporting a few common ones: gl3w, glew, glad.
// You may use another loader/header of your choice (glext, glLoadGen, etc.), or chose to manually implement your own.
#if defined(IMGUI_IMPL_OPENGL_LOADER_GL3W)
#include <GL3W/gl3w.h>    // Initialize with gl3wInit()
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLEW)
#include <GL/glew.h>    // Initialize with glewInit()
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLAD)
#include <glad/glad.h>  // Initialize with gladLoadGL()
#else
#include IMGUI_IMPL_OPENGL_LOADER_CUSTOM
#endif

// [Win32] Our example includes a copy of glfw3.lib pre-compiled with VS2010 to maximize ease of testing and compatibility with old VS compilers.
// To link with VS2010-era libraries, VS2015+ requires linking with legacy_stdio_definitions.lib, which we do using this pragma.
// Your own project should not be affected, as you are likely to link with a newer binary of GLFW that is adequate for your version of Visual Studio.
#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment( lib, "legacy_stdio_definitions" )
#endif

namespace MANA3D
{
	class ImGuiManager
	{
		friend class MANA3DEngine;

	private:
		static void Init( GLFWwindow* window );

		static void StartFrame();

		static void Render();

		static void Shutdown();
	};
}

#endif // !IMGUI_MANAGER_H

