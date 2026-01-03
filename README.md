### dependencies
cmake

gcc or g++ at least 17 (don't want 17?  change line 4 of root level CMakeLists.txt)

raylib 5.5 (don't want 5.5?  change line 12 of CMakeLists.txt)

### build and run
```bash
mkdir build
cd build
cmake ..
make
cd raylib-fun  # this folder is created because of lines 17-19 in the root level CMakeLists.txt
./raylib-fun   # executable name will be PROJECT_NAME, which will be project(raylib-fun), from root level CMakeLists.txt
```
