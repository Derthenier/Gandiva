#pragma once
#ifndef _GANDIVA_VERSION_1_RENDERER_HPP_
#define _GANDIVA_VERSION_1_RENDERER_HPP_

#ifdef GANDIVA_EXPORTS
#ifndef GANDIVA_DLL_API
#define GANDIVA_DLL_API  __declspec(dllexport)
#endif
#else
#ifndef GANDIVA_DLL_API
#define GANDIVA_DLL_API __declspec(dllimport)
#endif
#endif

#include <d3d12.h>
#include <dxgi1_4.h>
#include <d3d12sdklayers.h>
#include <wrl.h>

using Microsoft::WRL::ComPtr;


namespace Gandiva
{
	namespace Graphics
	{
		class GANDIVA_DLL_API Renderer
		{
		public:
			Renderer();
			virtual ~Renderer();

			void initialize(HWND window, unsigned int width, unsigned int height, bool useWARPDevice);
			void cleanup();

		private:
			void WaitForPreviousFrame();

		private:
			boolean m_released;
			ComPtr<IDXGISwapChain3> m_swapChain;
			ComPtr<ID3D12Device> m_device;
			ComPtr<ID3D12Resource> m_renderTargets[2];
			ComPtr<ID3D12CommandAllocator> m_commandAllocator;
			ComPtr<ID3D12CommandAllocator> m_bundleAllocator;
			ComPtr<ID3D12CommandQueue> m_commandQueue;
			ComPtr<ID3D12RootSignature> m_rootSignature;
			ComPtr<ID3D12DescriptorHeap> m_rtvHeap;
			ComPtr<ID3D12PipelineState> m_pipelineState;
			ComPtr<ID3D12GraphicsCommandList> m_commandList;
			ComPtr<ID3D12GraphicsCommandList> m_bundle;
			UINT m_rtvDescriptorSize;

			ComPtr<ID3D12Resource> m_vertexBuffer;
			D3D12_VERTEX_BUFFER_VIEW m_vertexBufferView;

			// Synchronization objects.
			UINT m_frameIndex;
			HANDLE m_fenceEvent;
			ComPtr<ID3D12Fence> m_fence;
			UINT64 m_fenceValue;
		};
	}
}

#endif // _GANDIVA_VERSION_1_RENDERER_HPP_