# SFML 2.0 Book Excercises

### Just me going through the [SFML 2.0 Game Development book][1], nothing to see here.  Just me going through chapter by chapter and applying what is read.

### To get everything working under a Debian based system (specifically Ubuntu 13.04):
    sudo apt-get install libxmu-dev libxi-dev libopenal-dev
    
    # Download & compile the latest version of libGLEW (1.9?)

    git clone git://git.code.sf.net/p/glew/code glew
    cd glew
    make extensions && make
    sudo make install
    make clean

    # Download & compile the latest version SFML (2.1)

    git clone https://github.com/LaurentGomila/SFML  

    # To build sfml, you will need to have CMake installed

    sudo apt-get install cmake cmake-gui

    # Use build tutorial here to create your make file [here][2].

    cd sfml && make
    sudo -s && make install && make clean

### Unit testing supports w/Google-Test 
    sudo apt-get install libgtest-dev
    cd /usr/src/gtest
    sudo cmake CMakeLists.txt
    sudo make
    sudo cp *.a /usr/lib  # copy or symlink libgtest.a and libgtest_main.a to your /usr/lib folder

    #download Google Mock (http://code.google.com/p/googlemock/downloads/list) and extract contents to /usr/src
    cd /usr/src/gmock*
    sudo cmake CMakeLists.txt
    sudo make
    sudo cp *.a /usr/lib    

[1]: http://www.packtpub.com/sfml-game-development/book
[2]: http://www.sfml-dev.org/tutorials/2.0/compile-with-cmake.php