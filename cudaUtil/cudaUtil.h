#ifndef _CUDA_UTIL_H
#define _CUDA_UTIL_H

#include <cuda.h>
#include <cuda_runtime.h>

#include <string>
#include <cstring>
#include <vector>

namespace cuda {
	typedef struct {

		int id;
		int major;
		int minor;
		int mpCount;
		int cores;
		uint64_t mem;
		std::string name;

	}CudaDeviceInfo;

	class CudaException
	{
	public:
		cudaError_t error;
		std::string msg;

		CudaException(cudaError_t err)
		{
			this->error = err;
			this->msg = std::string(cudaGetErrorString(err));
		}
	};

	CudaDeviceInfo getDeviceInfo(int device);

	std::vector<CudaDeviceInfo> getDevices();

	int getDeviceCount();
}
#endif
