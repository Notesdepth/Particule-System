# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/Création/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/Création/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/notesdepth/Documents/Programmes/Projets/C/Particules System"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/notesdepth/Documents/Programmes/Projets/C/Particules System"

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/Applications/Création/CLion.app/Contents/bin/cmake/mac/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/Applications/Création/CLion.app/Contents/bin/cmake/mac/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start "/Users/notesdepth/Documents/Programmes/Projets/C/Particules System/CMakeFiles" "/Users/notesdepth/Documents/Programmes/Projets/C/Particules System/CMakeFiles/progress.marks"
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start "/Users/notesdepth/Documents/Programmes/Projets/C/Particules System/CMakeFiles" 0
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
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Particules_System

# Build rule for target.
Particules_System: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Particules_System
.PHONY : Particules_System

# fast build rule for target.
Particules_System/fast:
	$(MAKE) -f CMakeFiles/Particules_System.dir/build.make CMakeFiles/Particules_System.dir/build
.PHONY : Particules_System/fast

src/Window.o: src/Window.cpp.o

.PHONY : src/Window.o

# target to build an object file
src/Window.cpp.o:
	$(MAKE) -f CMakeFiles/Particules_System.dir/build.make CMakeFiles/Particules_System.dir/src/Window.cpp.o
.PHONY : src/Window.cpp.o

src/Window.i: src/Window.cpp.i

.PHONY : src/Window.i

# target to preprocess a source file
src/Window.cpp.i:
	$(MAKE) -f CMakeFiles/Particules_System.dir/build.make CMakeFiles/Particules_System.dir/src/Window.cpp.i
.PHONY : src/Window.cpp.i

src/Window.s: src/Window.cpp.s

.PHONY : src/Window.s

# target to generate assembly for a file
src/Window.cpp.s:
	$(MAKE) -f CMakeFiles/Particules_System.dir/build.make CMakeFiles/Particules_System.dir/src/Window.cpp.s
.PHONY : src/Window.cpp.s

src/calcCL.o: src/calcCL.cpp.o

.PHONY : src/calcCL.o

# target to build an object file
src/calcCL.cpp.o:
	$(MAKE) -f CMakeFiles/Particules_System.dir/build.make CMakeFiles/Particules_System.dir/src/calcCL.cpp.o
.PHONY : src/calcCL.cpp.o

src/calcCL.i: src/calcCL.cpp.i

.PHONY : src/calcCL.i

# target to preprocess a source file
src/calcCL.cpp.i:
	$(MAKE) -f CMakeFiles/Particules_System.dir/build.make CMakeFiles/Particules_System.dir/src/calcCL.cpp.i
.PHONY : src/calcCL.cpp.i

src/calcCL.s: src/calcCL.cpp.s

.PHONY : src/calcCL.s

# target to generate assembly for a file
src/calcCL.cpp.s:
	$(MAKE) -f CMakeFiles/Particules_System.dir/build.make CMakeFiles/Particules_System.dir/src/calcCL.cpp.s
.PHONY : src/calcCL.cpp.s

src/loop.o: src/loop.cpp.o

.PHONY : src/loop.o

# target to build an object file
src/loop.cpp.o:
	$(MAKE) -f CMakeFiles/Particules_System.dir/build.make CMakeFiles/Particules_System.dir/src/loop.cpp.o
.PHONY : src/loop.cpp.o

src/loop.i: src/loop.cpp.i

.PHONY : src/loop.i

# target to preprocess a source file
src/loop.cpp.i:
	$(MAKE) -f CMakeFiles/Particules_System.dir/build.make CMakeFiles/Particules_System.dir/src/loop.cpp.i
.PHONY : src/loop.cpp.i

src/loop.s: src/loop.cpp.s

.PHONY : src/loop.s

# target to generate assembly for a file
src/loop.cpp.s:
	$(MAKE) -f CMakeFiles/Particules_System.dir/build.make CMakeFiles/Particules_System.dir/src/loop.cpp.s
.PHONY : src/loop.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/Particules_System.dir/build.make CMakeFiles/Particules_System.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/Particules_System.dir/build.make CMakeFiles/Particules_System.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/Particules_System.dir/build.make CMakeFiles/Particules_System.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... Particules_System"
	@echo "... src/Window.o"
	@echo "... src/Window.i"
	@echo "... src/Window.s"
	@echo "... src/calcCL.o"
	@echo "... src/calcCL.i"
	@echo "... src/calcCL.s"
	@echo "... src/loop.o"
	@echo "... src/loop.i"
	@echo "... src/loop.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
