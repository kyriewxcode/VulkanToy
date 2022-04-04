#include "vulkanexamplebase.h"
#include "VulkanglTFModel.h"

#define ENABLE_VALIDATION false

class VulkanExample : public VulkanExampleBase
{
public:

	VulkanExample() : VulkanExampleBase(ENABLE_VALIDATION)
	{
		title = "Vulkan Example - Basic indexed triangle";
		settings.overlay = false;
		camera.type = Camera::CameraType::lookat;
		camera.setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
		camera.setRotation(glm::vec3(0.0f));
		camera.setPerspective(60.0f, (float)width / (float)height, 1.0f, 256.0f);
	}

	~VulkanExample()
	{


	}

	void draw()
	{
		VulkanExampleBase::prepareFrame();

		VulkanExampleBase::submitFrame();
	}

	void prepare()
	{
		VulkanExampleBase::prepare();
		prepared = true;
	}

	void render()
	{
		if (!prepared)
			return;
	}

	virtual void OnUpdateUIOverlay(vks::UIOverlay* overlay)
	{
		if (!deviceFeatures.fillModeNonSolid) {
			if (overlay->header("Info")) {
				overlay->text("Non solid fill modes not supported!");
			}
		}
	}
};

VULKAN_EXAMPLE_MAIN()