 cmake_minimum_required(VERSION 3.10) # Minimalna wymagana wersja CMake
project(sfml) # Nazwa projektu

# Ustawienie standardu C++ na C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Dołączenie katalogu z plikami nagłówkowymi
include_directories(include)

# Dodanie pliku wykonywalnego
add_executable(sfml src/main.cpp src/Game.cpp src/System.cpp src/Random.cpp src/Word.cpp src/Player.cpp src/Bullet.cpp src/Ship.cpp src/Explosion.cpp src/Images.cpp src/Coin.cpp)

target_link_libraries(sfml sfml-graphics sfml-window sfml-system)
