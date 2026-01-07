CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

SRC = src/main.cpp \
      src/Character.cpp \
      src/Item.cpp \
      src/ItemFactory.cpp \
      src/Player.cpp \
      src/Weapon.cpp \
      src/Armor.cpp \
      src/Monster.cpp \
      src/MonsterList.cpp \
      src/MonsterAI.cpp \
      src/PlayerController.cpp \
      src/Random.cpp \
      src/Sys.cpp \
      src/BattleSystem.cpp \
      src/WeaponList.cpp \
      src/ArmorList.cpp \
      src/Inventory.cpp \
      src/MainMenu.cpp \
      src/SaveSystem.cpp

OBJ = $(SRC:.cpp=.o)

TARGET = game

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	Remove-Item src\*.o
