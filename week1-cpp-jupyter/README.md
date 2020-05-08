# Getting Started
[Create an environment from](https://docs.conda.io/projects/conda/en/latest/user-guide/tasks/manage-environments.html#creating-an-environment-from-an-environment-yml-file) [cling.yml](./cling.yml) file.
```bash
conda env create -f cling.yml
conda activate cling
```
## Xeus-Cling
- [Xeus-Cling: Run C++ code in Jupyter Notebook](https://www.learnopencv.com/xeus-cling-run-c-code-in-jupyter-notebook/)
- [Setting up Jupyter Notebook (Xeus Cling) for Libtorch and OpenCV Libraries](https://krshrimali.github.io/Setting-Up-Xeus-Cling-Libtorch-OpenCV/)

# Modifications to includeLibraries.h
1. Python3.5m include path - update the path from 
```cpp
#pragma cling add_include_path("/usr/include/python3.5m")
```
to the new path 
```cpp
#pragma cling add_include_path("/home/gaurav/anaconda3/envs/cling/include/python3.5m")
```
2. Update python3.5m loading path
```bash
conda activate cling
which python
```
Update the path from
```cpp
#pragma cling load("python3.5m")
```
to the new loading path
```cpp
#pragma cling load("/home/gaurav/anaconda3/envs/cling/bin/python3.5m")
```
3. Add numpy header files path
```bash
conda activate cling
python
>>> import numpy
>>> numpy.get_inlcude()
```
Add new line to the includeLibraries.h
```cpp
#pragma cling add_include_path("/home/gaurav/anaconda3/envs/cling/lib/python3.5/site-packages/numpy/core/include")

```
4. Update the version of the OpenCV .so files.
Navigate to `/usr/local/lib` and check the version of the opencv library files. Change the version number accordingly at all the locations -
`....libopencv_aruco.so.4.1.0` to `....libopencv_aruco.so.4.2.0`