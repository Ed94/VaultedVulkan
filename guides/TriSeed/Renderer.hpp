#pragma once



// Cross Window + Utils
#include "Utils.hpp"

// GLM
#define GLM_FORCE_SSE42 1
#define GLM_FORCE_DEFAULT_ALIGNED_GENTYPES 1
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

// VV
#include "VaultedThermals.hpp"



namespace Backend
{
	using namespace xwin;

	using namespace VT;
	using namespace VT::V3;
	using namespace VT::SPIR_V;

	struct UniformBufferObject
	{
		alignas(16) glm::mat4 ModelSpace;
		alignas(16) glm::mat4 Viewport  ;
		alignas(16) glm::mat4 Projection;
	};

	struct Vertex
	{
		using AttributeDescription = Pipeline::VertexInputState::AttributeDescription;
		using BindingDescription   = Pipeline::VertexInputState::BindingDescription  ;

		using VertexAttributes = std::array<AttributeDescription, 2>;

		struct PositionT
		{
			float32 X, Y, Z;
		} 
			
		Position;

		struct ColorT
		{
			float32 R, G, B;
		}

		Color;


		static /*constexpr*/ VertexAttributes GetAttributeDescriptions()
		{
			VertexAttributes result;

			// Position Attributes

			AttributeDescription& posAttrib = result.at(0);

			posAttrib.Binding  = 0;
			posAttrib.Location = 0;
			posAttrib.Format   = EFormat::R32_G32_B32_SFloat;
			posAttrib.Offset   = OffsetOf(Vertex::Position);

			// Color Attributes

			AttributeDescription& colorAttrib = result.at(1);

			colorAttrib.Binding  = 0;
			colorAttrib.Location = 1;
			colorAttrib.Format   = EFormat::R32_G32_B32_SFloat;
			colorAttrib.Offset   = OffsetOf(Vertex::Color);

			return result;
		}

		static /*constexpr*/ BindingDescription GetBindingDescription()
		{
			BindingDescription result;

			result.Binding   = 0;
			result.Stride    = sizeof(Vertex);
			result.InputRate = EVertexInputRate::Vertex;

			return result;
		}
	};

	struct Triangle
	{
		/*constexpr*/ const std::vector<Vertex> Verticies = 
		{
			// Vert1
			{
				{ 0.0f, -0.5f, 0.0f }, 
				{ 1.0f,  0.0f, 0.0f }
			},
			// Vert 2
			{
				{ 0.5f, 0.5f, 0.0f }, 
				{ 0.0f, 1.0f, 0.0f }
			},

			// Vert 3
			{
				{ -0.5f, 0.5f, 0.0f }, 
				{  0.0f, 0.0f, 1.0f }
			}
		};

		/*constexpr*/ const std::vector<uint32> Indicies = { 0, 1, 2 };
	};

	class VKGPU
	{
	public:
		/* 
		The vulkan backend is designed to setup the device with surface rendering support right on creation,
		so it needs an existing window to make sure that there is an available gpu that can present to it.
		*/
		VKGPU(Window& _window);
		
		~VKGPU();
		
		// Render onto the render target.
		void Render();

		// Resize the window and internal data structures
		void Recalibrate(uint32 _width, uint32 _height);

	protected:   
	// Functions

		// Initialize your Graphics API (Application/Device Handshake)
		void StartCommunication();

		// Destroy the Application instance and debug messenger
		void CeaseCommunication();

		// Engage the vulkan gpu that supports presenting to the provided window.
		void EngageSuitableDevice(Window& _window);

		// Initialize any resources such as VBOs, IBOs, used in this example
		void InitializeResources();

		// Destroy any resources used in this example
		void DestroyResources();

		// Create graphics API specific data structures to send commands to the GPU
		void CreateCommands();

		// Set up commands used when rendering frame by this app
		void SetupCommands();

		// Destroy all commands
		void DestroyCommands();

		// Set up the FrameBuffer
		void InitializeFrameBuffer();

		void DestroyFrameBuffer();

		// Set up the RenderPass
		void CreateRenderPass();

		void CreateSynchronization();

		// Set up the swapchain
		void SetupSwapchain(uint32 _width, uint32 _height);

	// Variables

		// Timing

		std::chrono::time_point<std::chrono::steady_clock> start, end;   // 

		std::chrono::duration<double> elapsedTime;
		
		// GPU Commmunication

		AppInstance    appVk ;
		LogicalDevice  device;

		struct PhysicalGPU
        {
            PhysicalGPU(PhysicalDevice& _physicalDevice, std::vector<LayerAndExtensionProperties>& _properties):
                PhysicalDevice(_physicalDevice), LayersAndExtensions(_properties)
            {}

            V3::PhysicalDevice                       PhysicalDevice       ;
            std::vector<LayerAndExtensionProperties> LayersAndExtensions  ;
            std::vector<QueueFamilyProperties>       QueueFamilyProperties;
        };

		std::vector<PhysicalGPU> gpus;   // Listing of all physical gpus

		DebugUtils::Messenger messenger;

		Queue  queue;
		float  queuePriority;
		uint32 queueFamily;

		// Renderer

		Surface   surface  ;
		Swapchain swapchain;

		Extent2D surfaceSize;
		Rect2D   renderArea ;		

		Viewport viewport;

		RenderPass renderPass;

		PipelineCache  pipelineCache;
		PipelineLayout pipelineLayout;

		GraphicsPipeline graphicsPipeline;

		std::vector<Fence> waitFences;

		Semaphore swapAquisitionStatus, presentSubmitStatus;

		// Commands

		CommandPool                commandPool   ;
		std::vector<CommandBuffer> commandBuffers;
		uint32                     currentBuffer ;

		// Resources

		EFormat     surfaceColorFormat;
		EColorSpace surfaceColorSpace ;
		EFormat     surfaceDepthFormat;
		Image       depthImage        ;
		Memory      depthImageMemory  ;

		DescriptorPool descriptorPool;

		std::vector<DescriptorSetLayout> descriptorSetLayouts;
		std::vector<DescriptorSet      > descriptorSets;

		ShaderModule vertModule;
		ShaderModule fragModule;

		Buffer vertBuffer;
		Buffer fragBuffer;
	};
}