#include "cudaCal.h"
#include <cuda_runtime.h>
#include <iostream>

namespace cudaCal {

void calculateKernel(const int *a, const int *b, int *c, int size);

void calculateM(int *a, int *b, int *c, int size) {
    int deviceCount;
    cudaGetDeviceCount(&deviceCount);
    if (deviceCount == 0) {
        std::cerr << "No GPU device found, performing calculation on CPU." << std::endl;
        for (int i = 0; i < size; ++i) {
            c[i] = a[i] + b[i];
        }
    } else {
        std::cout << "GPU device found, performing calculation on GPU." << std::endl;
        calculateKernel(a, b, c, size);
    }
}

} // namespace cudaCal