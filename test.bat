cmake -S . -B build/ -G "MSYS Makefiles"
cd build/
make 
gerber2stl.exe ../test_files/test ../test_files/out
cd ..