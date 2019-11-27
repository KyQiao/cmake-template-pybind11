# cmake-template-pybind11
 Self-use template for Pybind11, modified from official [cmake-example](https://github.com/pybind/cmake_example) repo, fixed some bugs.


## Prerequisites

**On Unix (Linux, OS X)**

* A compiler with C++11 support
* CMake >= 2.8.12

**On Windows**

* Visual Studio 2015 (required for all Python versions, see notes below)
* CMake >= 3.1

`Anaconda` environment for windows is recommended.


## Installation

### tips for windows

Before you use the template, make sure:

- You have CMake which can be found in PATH
- You have VS 15 or later installed or at least you have full c++ toolchain. If you're not familiar with this, install the VS 19 will be a good choice(only c/c++ package is enough).
- VC++ runtime 2015 is required. This is automatically satisfied in modern windows. If you need to distribute complied package to other windows,like for some older version, they need the runtime library. Download from windows [here](https://www.microsoft.com/en-us/download/details.aspx?id=48145 ) or you just `conda` install it.
- You have pip and your Python package environment which can be found in PATH. This is why I recommend `Anaconda`, which give you `anaconda prompt` to initialize all the Python environment.
- Make sure your CMake can find your MSVC compiler. Check the PATH carefully.



Clone this repository. Note the `--recursive` option which is needed for the pybind11 submodule:

```bash
git clone --recursive https://github.com/KyQiao/cmake-template-pybind11.git
```

Making wheel distribution file for installation:

```bash
python setup.py bdist_wheel
```

With the `setup.py` file included in this example, this command will invoke CMake and build the pybind11 module as specified in `CMakeLists.txt`. Final wheel file locates in the `dist` folder, using:

```bash
pip install -U my_wheel_name.whl
```

to install corresponding package. `-U` will automatically update the target package which is quite useful in testing.


## Building the documentation

Documentation for the example project is generated using Sphinx. Sphinx has the
ability to automatically inspect the signatures and documentation strings in
the extension module to generate beautiful documentation in a variety formats.
The following command generates HTML-based reference documentation; for other
formats please refer to the Sphinx manual:

 - `cd cmake_example/docs`
 - `make html`

## Structure of package

Two packaging tools are used: `setuptools` from Python and `CMake`. `CMake` takes care of the c++ file, i.e. `pyd` file. `setuptools` will package them together, in which you can add some Python file and build up a mixed package. 

Basically, `setup.py` will invoke the `CMake` and add everything it builds to the package folder, so that modify  `CMakeList.txt` is enough for managing most file. Python file structure can be managed directly from package folder. 

**Do clean the build** when you change the structure,  some former build file will also be added to new distribution.

