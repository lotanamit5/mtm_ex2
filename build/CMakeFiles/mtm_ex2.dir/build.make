# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_SOURCE_DIR = /home/nircoe/Desktop/mtm_ex2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nircoe/Desktop/mtm_ex2/build

# Include any dependencies generated for this target.
include CMakeFiles/mtm_ex2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mtm_ex2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mtm_ex2.dir/flags.make

CMakeFiles/mtm_ex2.dir/part1/ExamDetails.cpp.o: CMakeFiles/mtm_ex2.dir/flags.make
CMakeFiles/mtm_ex2.dir/part1/ExamDetails.cpp.o: ../part1/ExamDetails.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nircoe/Desktop/mtm_ex2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mtm_ex2.dir/part1/ExamDetails.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mtm_ex2.dir/part1/ExamDetails.cpp.o -c /home/nircoe/Desktop/mtm_ex2/part1/ExamDetails.cpp

CMakeFiles/mtm_ex2.dir/part1/ExamDetails.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mtm_ex2.dir/part1/ExamDetails.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nircoe/Desktop/mtm_ex2/part1/ExamDetails.cpp > CMakeFiles/mtm_ex2.dir/part1/ExamDetails.cpp.i

CMakeFiles/mtm_ex2.dir/part1/ExamDetails.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mtm_ex2.dir/part1/ExamDetails.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nircoe/Desktop/mtm_ex2/part1/ExamDetails.cpp -o CMakeFiles/mtm_ex2.dir/part1/ExamDetails.cpp.s

CMakeFiles/mtm_ex2.dir/part1/part1_tests.cpp.o: CMakeFiles/mtm_ex2.dir/flags.make
CMakeFiles/mtm_ex2.dir/part1/part1_tests.cpp.o: ../part1/part1_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nircoe/Desktop/mtm_ex2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mtm_ex2.dir/part1/part1_tests.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mtm_ex2.dir/part1/part1_tests.cpp.o -c /home/nircoe/Desktop/mtm_ex2/part1/part1_tests.cpp

CMakeFiles/mtm_ex2.dir/part1/part1_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mtm_ex2.dir/part1/part1_tests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nircoe/Desktop/mtm_ex2/part1/part1_tests.cpp > CMakeFiles/mtm_ex2.dir/part1/part1_tests.cpp.i

CMakeFiles/mtm_ex2.dir/part1/part1_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mtm_ex2.dir/part1/part1_tests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nircoe/Desktop/mtm_ex2/part1/part1_tests.cpp -o CMakeFiles/mtm_ex2.dir/part1/part1_tests.cpp.s

# Object files for target mtm_ex2
mtm_ex2_OBJECTS = \
"CMakeFiles/mtm_ex2.dir/part1/ExamDetails.cpp.o" \
"CMakeFiles/mtm_ex2.dir/part1/part1_tests.cpp.o"

# External object files for target mtm_ex2
mtm_ex2_EXTERNAL_OBJECTS =

mtm_ex2: CMakeFiles/mtm_ex2.dir/part1/ExamDetails.cpp.o
mtm_ex2: CMakeFiles/mtm_ex2.dir/part1/part1_tests.cpp.o
mtm_ex2: CMakeFiles/mtm_ex2.dir/build.make
mtm_ex2: CMakeFiles/mtm_ex2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nircoe/Desktop/mtm_ex2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable mtm_ex2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mtm_ex2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mtm_ex2.dir/build: mtm_ex2

.PHONY : CMakeFiles/mtm_ex2.dir/build

CMakeFiles/mtm_ex2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mtm_ex2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mtm_ex2.dir/clean

CMakeFiles/mtm_ex2.dir/depend:
	cd /home/nircoe/Desktop/mtm_ex2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nircoe/Desktop/mtm_ex2 /home/nircoe/Desktop/mtm_ex2 /home/nircoe/Desktop/mtm_ex2/build /home/nircoe/Desktop/mtm_ex2/build /home/nircoe/Desktop/mtm_ex2/build/CMakeFiles/mtm_ex2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mtm_ex2.dir/depend

