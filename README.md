# Gerber to STL File Converter
The purpose of this project is to convert Gerber files for PCB etching to STL files to be used for 3D printing. <br>
This can be used for PCB prototyping, or to print live circuits. <br>
---
### Usage
To clone, build, and run the program, run the following commands:
```
git clone https://github.com/austinconnor/gerber2stl.git
cd gerber2stl
mkdir build
test.bat
```
You can look in `test.bat` to see the specific build command.<br>
<br>
Alternatively, to run the code on your own Gerber files, in the base directory, run:
```
build.bat
cd build
gerber2stl <input_directory> <output_directory>
```

The input directory should contain Gerber files, and for each Gerber file, an STL file will be generated and sent to the output directory.

---
### Requirements
For CMake, be sure to use the Generator of your choice. I use `MSYS Makefiles` in my `.bat` files. <br>
