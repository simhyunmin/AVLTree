# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/varia/Documents/seaweedtreepot_INHA_OSAP_002_T6/INHA_OSAP_002_T6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/varia/Documents/seaweedtreepot_INHA_OSAP_002_T6/INHA_OSAP_002_T6/build

# Include any dependencies generated for this target.
include CMakeFiles/totalTestRunner.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/totalTestRunner.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/totalTestRunner.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/totalTestRunner.dir/flags.make

CMakeFiles/totalTestRunner.dir/GoogleTest/total_test_runner.cc.o: CMakeFiles/totalTestRunner.dir/flags.make
CMakeFiles/totalTestRunner.dir/GoogleTest/total_test_runner.cc.o: ../GoogleTest/total_test_runner.cc
CMakeFiles/totalTestRunner.dir/GoogleTest/total_test_runner.cc.o: CMakeFiles/totalTestRunner.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/varia/Documents/seaweedtreepot_INHA_OSAP_002_T6/INHA_OSAP_002_T6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/totalTestRunner.dir/GoogleTest/total_test_runner.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/totalTestRunner.dir/GoogleTest/total_test_runner.cc.o -MF CMakeFiles/totalTestRunner.dir/GoogleTest/total_test_runner.cc.o.d -o CMakeFiles/totalTestRunner.dir/GoogleTest/total_test_runner.cc.o -c /mnt/c/Users/varia/Documents/seaweedtreepot_INHA_OSAP_002_T6/INHA_OSAP_002_T6/GoogleTest/total_test_runner.cc

CMakeFiles/totalTestRunner.dir/GoogleTest/total_test_runner.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/totalTestRunner.dir/GoogleTest/total_test_runner.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/varia/Documents/seaweedtreepot_INHA_OSAP_002_T6/INHA_OSAP_002_T6/GoogleTest/total_test_runner.cc > CMakeFiles/totalTestRunner.dir/GoogleTest/total_test_runner.cc.i

CMakeFiles/totalTestRunner.dir/GoogleTest/total_test_runner.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/totalTestRunner.dir/GoogleTest/total_test_runner.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/varia/Documents/seaweedtreepot_INHA_OSAP_002_T6/INHA_OSAP_002_T6/GoogleTest/total_test_runner.cc -o CMakeFiles/totalTestRunner.dir/GoogleTest/total_test_runner.cc.s

# Object files for target totalTestRunner
totalTestRunner_OBJECTS = \
"CMakeFiles/totalTestRunner.dir/GoogleTest/total_test_runner.cc.o"

# External object files for target totalTestRunner
totalTestRunner_EXTERNAL_OBJECTS =

totalTestRunner: CMakeFiles/totalTestRunner.dir/GoogleTest/total_test_runner.cc.o
totalTestRunner: CMakeFiles/totalTestRunner.dir/build.make
totalTestRunner: libcommon_library.a
totalTestRunner: /usr/lib/x86_64-linux-gnu/libgtest.a
totalTestRunner: CMakeFiles/totalTestRunner.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/varia/Documents/seaweedtreepot_INHA_OSAP_002_T6/INHA_OSAP_002_T6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable totalTestRunner"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/totalTestRunner.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/totalTestRunner.dir/build: totalTestRunner
.PHONY : CMakeFiles/totalTestRunner.dir/build

CMakeFiles/totalTestRunner.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/totalTestRunner.dir/cmake_clean.cmake
.PHONY : CMakeFiles/totalTestRunner.dir/clean

CMakeFiles/totalTestRunner.dir/depend:
	cd /mnt/c/Users/varia/Documents/seaweedtreepot_INHA_OSAP_002_T6/INHA_OSAP_002_T6/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/varia/Documents/seaweedtreepot_INHA_OSAP_002_T6/INHA_OSAP_002_T6 /mnt/c/Users/varia/Documents/seaweedtreepot_INHA_OSAP_002_T6/INHA_OSAP_002_T6 /mnt/c/Users/varia/Documents/seaweedtreepot_INHA_OSAP_002_T6/INHA_OSAP_002_T6/build /mnt/c/Users/varia/Documents/seaweedtreepot_INHA_OSAP_002_T6/INHA_OSAP_002_T6/build /mnt/c/Users/varia/Documents/seaweedtreepot_INHA_OSAP_002_T6/INHA_OSAP_002_T6/build/CMakeFiles/totalTestRunner.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/totalTestRunner.dir/depend

