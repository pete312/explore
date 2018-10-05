.PHONY: install clean
	#IM A TAB AND SO IS THE NEXT LINE
	

VERSION=0.1

NEW_CMAKE=./build/CMakeLists.txt
CMAKE_TOP=./CMakeLists.txt
BUILD_DIR=./build
CMAKE=cmake

install: $(NEW_CMAKE)
	make -C $(BUILD_DIR)

    
clean: 
	rm -rf ./build
	
$(NEW_CMAKE) : $(CMAKE_TOP)
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && $(CMAKE) ..



