# Getting started
[Creating an environment](https://docs.conda.io/projects/conda/en/latest/user-guide/tasks/manage-environments.html#creating-an-environment-from-an-environment-yml-file) from [opencv-course.yml](./opencv-course.yml) file.

## For installing OpenCV
```bash
pip3 install --upgrade pip
pip install wheel numpy scipy matplotlib scikit-image scikit-learn ipython dlib
pip install opencv-contrib-python
```
Check if it has been installed correctly or not
```bash
conda activate opencv-course
python
>>> import cv2
>>> print(cv2.__version__)
```