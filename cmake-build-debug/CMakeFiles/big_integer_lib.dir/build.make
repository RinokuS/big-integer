# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "/Users/rinokus/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/202.6948.80/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/rinokus/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/202.6948.80/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rinokus/Documents/Projects/big-integer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rinokus/Documents/Projects/big-integer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/big_integer_lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/big_integer_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/big_integer_lib.dir/flags.make

CMakeFiles/big_integer_lib.dir/tests.cpp.o: CMakeFiles/big_integer_lib.dir/flags.make
CMakeFiles/big_integer_lib.dir/tests.cpp.o: ../tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rinokus/Documents/Projects/big-integer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/big_integer_lib.dir/tests.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/big_integer_lib.dir/tests.cpp.o -c /Users/rinokus/Documents/Projects/big-integer/tests.cpp

CMakeFiles/big_integer_lib.dir/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/big_integer_lib.dir/tests.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rinokus/Documents/Projects/big-integer/tests.cpp > CMakeFiles/big_integer_lib.dir/tests.cpp.i

CMakeFiles/big_integer_lib.dir/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/big_integer_lib.dir/tests.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rinokus/Documents/Projects/big-integer/tests.cpp -o CMakeFiles/big_integer_lib.dir/tests.cpp.s

CMakeFiles/big_integer_lib.dir/big_integer_lib/BigInteger.cpp.o: CMakeFiles/big_integer_lib.dir/flags.make
CMakeFiles/big_integer_lib.dir/big_integer_lib/BigInteger.cpp.o: ../big_integer_lib/BigInteger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rinokus/Documents/Projects/big-integer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/big_integer_lib.dir/big_integer_lib/BigInteger.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/big_integer_lib.dir/big_integer_lib/BigInteger.cpp.o -c /Users/rinokus/Documents/Projects/big-integer/big_integer_lib/BigInteger.cpp

CMakeFiles/big_integer_lib.dir/big_integer_lib/BigInteger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/big_integer_lib.dir/big_integer_lib/BigInteger.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rinokus/Documents/Projects/big-integer/big_integer_lib/BigInteger.cpp > CMakeFiles/big_integer_lib.dir/big_integer_lib/BigInteger.cpp.i

CMakeFiles/big_integer_lib.dir/big_integer_lib/BigInteger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/big_integer_lib.dir/big_integer_lib/BigInteger.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rinokus/Documents/Projects/big-integer/big_integer_lib/BigInteger.cpp -o CMakeFiles/big_integer_lib.dir/big_integer_lib/BigInteger.cpp.s

# Object files for target big_integer_lib
big_integer_lib_OBJECTS = \
"CMakeFiles/big_integer_lib.dir/tests.cpp.o" \
"CMakeFiles/big_integer_lib.dir/big_integer_lib/BigInteger.cpp.o"

# External object files for target big_integer_lib
big_integer_lib_EXTERNAL_OBJECTS =

big_integer_lib: CMakeFiles/big_integer_lib.dir/tests.cpp.o
big_integer_lib: CMakeFiles/big_integer_lib.dir/big_integer_lib/BigInteger.cpp.o
big_integer_lib: CMakeFiles/big_integer_lib.dir/build.make
big_integer_lib: CMakeFiles/big_integer_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rinokus/Documents/Projects/big-integer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable big_integer_lib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/big_integer_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/big_integer_lib.dir/build: big_integer_lib

.PHONY : CMakeFiles/big_integer_lib.dir/build

CMakeFiles/big_integer_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/big_integer_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/big_integer_lib.dir/clean

CMakeFiles/big_integer_lib.dir/depend:
	cd /Users/rinokus/Documents/Projects/big-integer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rinokus/Documents/Projects/big-integer /Users/rinokus/Documents/Projects/big-integer /Users/rinokus/Documents/Projects/big-integer/cmake-build-debug /Users/rinokus/Documents/Projects/big-integer/cmake-build-debug /Users/rinokus/Documents/Projects/big-integer/cmake-build-debug/CMakeFiles/big_integer_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/big_integer_lib.dir/depend
