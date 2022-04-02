#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <fstream>
#include <vector>
#include <exception>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vulkan/vulkan.h>
#include "vulkanexamplebase.h"

#define ENABLE_VALIDATION false
#define USE_STAGING true

class Triangle : public VulkanExampleBase
{
public:

	Triangle() : VulkanExampleBase(ENABLE_VALIDATION)
	{
		title = "Vulkan Example - Basic indexed triangle";
		settings.overlay = false;
		camera.type = Camera::CameraType::lookat;
		camera.setPosition(glm::vec3(0.0f, 0.0f, -2.5f));
		camera.setRotation(glm::vec3(0.0f));
		camera.setPerspective(60.0f, (float)width / (float)height, 1.0f, 256.0f);
	}

	~Triangle()
	{

	}

	void render()
	{

	}
};

// Windows entry point
Triangle* triangle;
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (triangle != NULL)
	{
		triangle->handleMessages(hWnd, uMsg, wParam, lParam);
	}
	return (DefWindowProc(hWnd, uMsg, wParam, lParam));
}
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
	for (size_t i = 0; i < __argc; i++) { Triangle::args.push_back(__argv[i]); };
	triangle = new Triangle();
	triangle->initVulkan();
	triangle->setupWindow(hInstance, WndProc);
	triangle->prepare();
	triangle->renderLoop();
	delete(triangle);
	return 0;
}
