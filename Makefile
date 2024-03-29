# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/tomasz/Desktop/keyShooter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tomasz/Desktop/keyShooter

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/tomasz/Desktop/keyShooter/CMakeFiles /home/tomasz/Desktop/keyShooter//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/tomasz/Desktop/keyShooter/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named sfml

# Build rule for target.
sfml: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 sfml
.PHONY : sfml

# fast build rule for target.
sfml/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/build
.PHONY : sfml/fast

src/Bullet.o: src/Bullet.cpp.o
.PHONY : src/Bullet.o

# target to build an object file
src/Bullet.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/Bullet.cpp.o
.PHONY : src/Bullet.cpp.o

src/Bullet.i: src/Bullet.cpp.i
.PHONY : src/Bullet.i

# target to preprocess a source file
src/Bullet.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/Bullet.cpp.i
.PHONY : src/Bullet.cpp.i

src/Bullet.s: src/Bullet.cpp.s
.PHONY : src/Bullet.s

# target to generate assembly for a file
src/Bullet.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/Bullet.cpp.s
.PHONY : src/Bullet.cpp.s

src/Coin.o: src/Coin.cpp.o
.PHONY : src/Coin.o

# target to build an object file
src/Coin.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/Coin.cpp.o
.PHONY : src/Coin.cpp.o

src/Coin.i: src/Coin.cpp.i
.PHONY : src/Coin.i

# target to preprocess a source file
src/Coin.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/Coin.cpp.i
.PHONY : src/Coin.cpp.i

src/Coin.s: src/Coin.cpp.s
.PHONY : src/Coin.s

# target to generate assembly for a file
src/Coin.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/Coin.cpp.s
.PHONY : src/Coin.cpp.s

src/Explosion.o: src/Explosion.cpp.o
.PHONY : src/Explosion.o

# target to build an object file
src/Explosion.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/Explosion.cpp.o
.PHONY : src/Explosion.cpp.o

src/Explosion.i: src/Explosion.cpp.i
.PHONY : src/Explosion.i

# target to preprocess a source file
src/Explosion.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/Explosion.cpp.i
.PHONY : src/Explosion.cpp.i

src/Explosion.s: src/Explosion.cpp.s
.PHONY : src/Explosion.s

# target to generate assembly for a file
src/Explosion.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/Explosion.cpp.s
.PHONY : src/Explosion.cpp.s

src/Game.o: src/Game.cpp.o
.PHONY : src/Game.o

# target to build an object file
src/Game.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/Game.cpp.o
.PHONY : src/Game.cpp.o

src/Game.i: src/Game.cpp.i
.PHONY : src/Game.i

# target to preprocess a source file
src/Game.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/Game.cpp.i
.PHONY : src/Game.cpp.i

src/Game.s: src/Game.cpp.s
.PHONY : src/Game.s

# target to generate assembly for a file
src/Game.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/Game.cpp.s
.PHONY : src/Game.cpp.s

src/Images.o: src/Images.cpp.o
.PHONY : src/Images.o

# target to build an object file
src/Images.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/Images.cpp.o
.PHONY : src/Images.cpp.o

src/Images.i: src/Images.cpp.i
.PHONY : src/Images.i

# target to preprocess a source file
src/Images.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/Images.cpp.i
.PHONY : src/Images.cpp.i

src/Images.s: src/Images.cpp.s
.PHONY : src/Images.s

# target to generate assembly for a file
src/Images.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/Images.cpp.s
.PHONY : src/Images.cpp.s

src/Player.o: src/Player.cpp.o
.PHONY : src/Player.o

# target to build an object file
src/Player.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/Player.cpp.o
.PHONY : src/Player.cpp.o

src/Player.i: src/Player.cpp.i
.PHONY : src/Player.i

# target to preprocess a source file
src/Player.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/Player.cpp.i
.PHONY : src/Player.cpp.i

src/Player.s: src/Player.cpp.s
.PHONY : src/Player.s

# target to generate assembly for a file
src/Player.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/Player.cpp.s
.PHONY : src/Player.cpp.s

src/Random.o: src/Random.cpp.o
.PHONY : src/Random.o

# target to build an object file
src/Random.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/Random.cpp.o
.PHONY : src/Random.cpp.o

src/Random.i: src/Random.cpp.i
.PHONY : src/Random.i

# target to preprocess a source file
src/Random.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/Random.cpp.i
.PHONY : src/Random.cpp.i

src/Random.s: src/Random.cpp.s
.PHONY : src/Random.s

# target to generate assembly for a file
src/Random.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/Random.cpp.s
.PHONY : src/Random.cpp.s

src/Ship.o: src/Ship.cpp.o
.PHONY : src/Ship.o

# target to build an object file
src/Ship.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/Ship.cpp.o
.PHONY : src/Ship.cpp.o

src/Ship.i: src/Ship.cpp.i
.PHONY : src/Ship.i

# target to preprocess a source file
src/Ship.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/Ship.cpp.i
.PHONY : src/Ship.cpp.i

src/Ship.s: src/Ship.cpp.s
.PHONY : src/Ship.s

# target to generate assembly for a file
src/Ship.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/Ship.cpp.s
.PHONY : src/Ship.cpp.s

src/System.o: src/System.cpp.o
.PHONY : src/System.o

# target to build an object file
src/System.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/System.cpp.o
.PHONY : src/System.cpp.o

src/System.i: src/System.cpp.i
.PHONY : src/System.i

# target to preprocess a source file
src/System.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/System.cpp.i
.PHONY : src/System.cpp.i

src/System.s: src/System.cpp.s
.PHONY : src/System.s

# target to generate assembly for a file
src/System.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/System.cpp.s
.PHONY : src/System.cpp.s

src/Word.o: src/Word.cpp.o
.PHONY : src/Word.o

# target to build an object file
src/Word.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/Word.cpp.o
.PHONY : src/Word.cpp.o

src/Word.i: src/Word.cpp.i
.PHONY : src/Word.i

# target to preprocess a source file
src/Word.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/Word.cpp.i
.PHONY : src/Word.cpp.i

src/Word.s: src/Word.cpp.s
.PHONY : src/Word.s

# target to generate assembly for a file
src/Word.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/Word.cpp.s
.PHONY : src/Word.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/sfml.dir/build.make CMakeFiles/sfml.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... sfml"
	@echo "... src/Bullet.o"
	@echo "... src/Bullet.i"
	@echo "... src/Bullet.s"
	@echo "... src/Coin.o"
	@echo "... src/Coin.i"
	@echo "... src/Coin.s"
	@echo "... src/Explosion.o"
	@echo "... src/Explosion.i"
	@echo "... src/Explosion.s"
	@echo "... src/Game.o"
	@echo "... src/Game.i"
	@echo "... src/Game.s"
	@echo "... src/Images.o"
	@echo "... src/Images.i"
	@echo "... src/Images.s"
	@echo "... src/Player.o"
	@echo "... src/Player.i"
	@echo "... src/Player.s"
	@echo "... src/Random.o"
	@echo "... src/Random.i"
	@echo "... src/Random.s"
	@echo "... src/Ship.o"
	@echo "... src/Ship.i"
	@echo "... src/Ship.s"
	@echo "... src/System.o"
	@echo "... src/System.i"
	@echo "... src/System.s"
	@echo "... src/Word.o"
	@echo "... src/Word.i"
	@echo "... src/Word.s"
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

