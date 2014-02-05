PREFIX=/usr/local
MAN_PREFIX=$(PREFIX)
BIN_PREFIX=$(PREFIX)/bin
DATA_PREFIX=$(PREFIX)/share/BasicGame/

XX = g++
SFML_LIB = -L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system \
    -lsfml-network -lsfml-audio -Wl,-rpath=/usr/local/lib
GLEW_LIB = -L/usr/lib64 -lGLEW -Wl,-rpath=/usr/lib64

SFML_INCLUDE = -I/usr/local/include

CXXFLAGS = -Wall -c -g -std=c++11 $(SFML_INCLUDE)
LDFLAGS = $(SFML_LIB):$(GLEW_LIB)

BIN_DIR = ./bin
SOURCES =  src/Main.cpp src/Aircraft.cpp src/Animation.cpp src/Application.cpp \
    src/BloomEffect.cpp src/Button.cpp src/Command.cpp src/CommandQueue.cpp \
    src/Component.cpp src/Container.cpp src/DataTables.cpp src/Entity.cpp \
    src/EmitterNode.cpp src/Entity.cpp src/GameOverState.cpp src/GameServer.cpp \
    src/GameState.cpp src/KeyBinding.cpp src/Label.cpp src/MenuState.cpp \
    src/MultiplayerGameState.cpp src/MusicPlayer.cpp src/NetworkNode.cpp \
    src/ParticleNode.cpp \
    src/PauseState.cpp src/Pickup.cpp src/Player.cpp src/PostEffect.cpp \
    src/Projectile.cpp src/SceneNode.cpp src/SettingsState.cpp src/SoundNode.cpp \
    src/SoundPlayer.cpp src/SpriteNode.cpp src/State.cpp src/StateStack.cpp src/TextNode.cpp \
    src/TitleState.cpp src/Utility.cpp src/World.cpp

TARGET_BIN = $(BIN_DIR)/BasicGame

all : make_dirs $(TARGET_BIN) 

$(TARGET_BIN) : $(SOURCES:.cpp=.o)
	$(CXX) $^ $(LDFLAGS) -o $@

.cpp.o: 
	$(CXX) $(CXXFLAGS) $< -o $@

# Testing iteration is make clean, make game-tests, ./bin/GameTests
AIRCRAFT_TESTS_SOURCES = src/tests/AircraftTests.cpp \
    src/Aircraft.cpp src/Entity.cpp src/SceneNode.cpp
aircraft-tests:  $(AIRCRAFT_TESTS_SOURCES:.cpp=.o)
	$(CXX) $^ $(LDFLAGS) -lgtest -pthread -o bin/AircraftTests

GAME_TESTS_SOURCES = src/tests/GameTests.cpp \
		src/Game.cpp src/Entity.cpp
game-tests : $(GAME_TESTS_SOURCES:.cpp=.o)
	$(CXX) $^ $(LDFLAGS) -lgtest -pthread -o bin/GameTests 
	
RESOURCE_TESTS_SOURCES = src/tests/ResourceTests.cpp

resource-tests: $(GAME_TESTS_SOURCES:.cpp=.o)
	$(CXX) $^ $(LDFLAGS) -lgtest -pthread -o bin/ResourceTests
	
install:
	install -d $(DATA_PREFIX)
	cp -R data/* $(DATA_PREFIX)
	chmod -R a+rX,g-w,o-w $(DATA_PREFIX)
	cp basicgame $(BIN_PREFIX)
	chmod a+rx,g-w,o-w $(BIN_PREFIX)/basicgame
	install -d $(MAN_PREFIX)/man/man6/
	cp  basicgame.6 $(MAN_PREFIX)/man/man6/
	chmod a+rx,g-w,o-w $(MAN_PREFIX)/man/man6/basicgame.6 

make_dirs :
	mkdir -p $(BIN_DIR)
	
check:
	valgrind --log-file=valgrind.output --leak-check=yes --tool=memcheck $(TARGET_BIN)

clean:
	rm -f bin/* && rm $(shell find . -name '*.o') 

