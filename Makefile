CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

SRC = src/main.cpp \
      src/Character.cpp \
      src/Item.cpp \
      src/ItemFactory.cpp \
      src/ItemDatabase.cpp \
      src/Player.cpp \
      src/Weapon.cpp \
      src/Armor.cpp \
      src/Meterial.cpp \
      src/Monster.cpp \
      src/NormalMonsterList.cpp \
      src/BossMonsterList.cpp \
      src/MonsterAI.cpp \
      src/PlayerController.cpp \
      src/Random.cpp \
      src/Sys.cpp \
      src/BattleSystem.cpp \
      src/GameUI.cpp \
      src/WeaponList.cpp \
      src/ArmorList.cpp \
      src/MeterialList.cpp \
      src/Inventory.cpp \
      src/GameProcess.cpp \
      src/SaveSystem.cpp \
      src/Shop.cpp

OBJ = $(SRC:.cpp=.o)

TARGET = game

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	Remove-Item src\*.o
