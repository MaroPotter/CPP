# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\marek\CLionProjects\LabToRm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\marek\CLionProjects\LabToRm\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LabToRm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LabToRm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LabToRm.dir/flags.make

CMakeFiles/LabToRm.dir/main.cpp.obj: CMakeFiles/LabToRm.dir/flags.make
CMakeFiles/LabToRm.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\marek\CLionProjects\LabToRm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LabToRm.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\LabToRm.dir\main.cpp.obj -c C:\Users\marek\CLionProjects\LabToRm\main.cpp

CMakeFiles/LabToRm.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LabToRm.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\marek\CLionProjects\LabToRm\main.cpp > CMakeFiles\LabToRm.dir\main.cpp.i

CMakeFiles/LabToRm.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LabToRm.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\marek\CLionProjects\LabToRm\main.cpp -o CMakeFiles\LabToRm.dir\main.cpp.s

# Object files for target LabToRm
LabToRm_OBJECTS = \
"CMakeFiles/LabToRm.dir/main.cpp.obj"

# External object files for target LabToRm
LabToRm_EXTERNAL_OBJECTS =

LabToRm.exe: CMakeFiles/LabToRm.dir/main.cpp.obj
LabToRm.exe: CMakeFiles/LabToRm.dir/build.make
LabToRm.exe: CMakeFiles/LabToRm.dir/linklibs.rsp
LabToRm.exe: CMakeFiles/LabToRm.dir/objects1.rsp
LabToRm.exe: CMakeFiles/LabToRm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\marek\CLionProjects\LabToRm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LabToRm.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\LabToRm.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LabToRm.dir/build: LabToRm.exe

.PHONY : CMakeFiles/LabToRm.dir/build

CMakeFiles/LabToRm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\LabToRm.dir\cmake_clean.cmake
.PHONY : CMakeFiles/LabToRm.dir/clean

CMakeFiles/LabToRm.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\marek\CLionProjects\LabToRm C:\Users\marek\CLionProjects\LabToRm C:\Users\marek\CLionProjects\LabToRm\cmake-build-debug C:\Users\marek\CLionProjects\LabToRm\cmake-build-debug C:\Users\marek\CLionProjects\LabToRm\cmake-build-debug\CMakeFiles\LabToRm.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LabToRm.dir/depend
