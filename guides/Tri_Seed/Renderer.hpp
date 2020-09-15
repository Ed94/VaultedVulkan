#pragma once



// Cross Window + Utils
#include "CommonUtils.hpp"

// GLM
#define GLM_FORCE_SSE42 1
#define GLM_FORCE_DEFAULT_ALIGNED_GENTYPES 1
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

// VT
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

	class Renderer
	{
	public:
		
		Renderer(Window& _window);
		
		~Renderer();
		
		// Render onto the render target.
		void Render();

		// Resize the window and internal data structures
		void Resize(uint32 _width, uint32 _height);

	protected:   // Functions

		// Initialize your Graphics API
		void InitializeAPI(Window& _window);

		// Destroy any Graphics API data structures used in this example
		void DestroyAPI();

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
		void InitFrameBuffer();

		void DestroyFrameBuffer();

		// Set up the RenderPass
		void CreateRenderPass();

		void CreateSynchronization();

		// Set up the swapchain
		void SetupSwapchain(uint32 _width, uint32 _height);

	protected:   // Variables

		std::chrono::time_point<std::chrono::steady_clock> start, end;   // 
	};
}
