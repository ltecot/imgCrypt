# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.7.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.7.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lucastecot/Development/imgCrypt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lucastecot/Development/imgCrypt

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.7.2/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.7.2/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/lucastecot/Development/imgCrypt/CMakeFiles /Users/lucastecot/Development/imgCrypt/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/lucastecot/Development/imgCrypt/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named imgCrypt

# Build rule for target.
imgCrypt: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 imgCrypt
.PHONY : imgCrypt

# fast build rule for target.
imgCrypt/fast:
	$(MAKE) -f CMakeFiles/imgCrypt.dir/build.make CMakeFiles/imgCrypt.dir/build
.PHONY : imgCrypt/fast

imgCrypt.o: imgCrypt.cpp.o

.PHONY : imgCrypt.o

# target to build an object file
imgCrypt.cpp.o:
	$(MAKE) -f CMakeFiles/imgCrypt.dir/build.make CMakeFiles/imgCrypt.dir/imgCrypt.cpp.o
.PHONY : imgCrypt.cpp.o

imgCrypt.i: imgCrypt.cpp.i

.PHONY : imgCrypt.i

# target to preprocess a source file
imgCrypt.cpp.i:
	$(MAKE) -f CMakeFiles/imgCrypt.dir/build.make CMakeFiles/imgCrypt.dir/imgCrypt.cpp.i
.PHONY : imgCrypt.cpp.i

imgCrypt.s: imgCrypt.cpp.s

.PHONY : imgCrypt.s

# target to generate assembly for a file
imgCrypt.cpp.s:
	$(MAKE) -f CMakeFiles/imgCrypt.dir/build.make CMakeFiles/imgCrypt.dir/imgCrypt.cpp.s
.PHONY : imgCrypt.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... imgCrypt"
	@echo "... imgCrypt.o"
	@echo "... imgCrypt.i"
	@echo "... imgCrypt.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

