===============================================
SFML 2.0 Book Excercises
=============================
===============================================

Just me going through the [SFML 2.0 Game Development book][1], nothing to see here.  Just me going
through chapter by chapter and applying what is read.

To get everything working under Ubuntu (I'm working under 13.04):
------------------------------------------------------------------
sudo apt-get install libxmu-dev libxi-dev libopenal-dev

**Download & compile the latest version of libGLEW (1.9?)**

git clone git://git.code.sf.net/p/glew/code glew

cd glew

make extensions

make

sudo make install

make clean

**Download & compile the latest version SFML (2.1)**

git clone https://github.com/LaurentGomila/SFML  

**To build sfml, you will need to have CMake installed**

sudo apt-get install cmake cmake-gui

**Use build tutorial here to create your make file w/Cmake**:  [http://www.sfml-dev.org/tutorials/2.0/compile-with-cmake.php][2]

cd sfml

make

sudo -s

make install

make clean


[1]: http://www.packtpub.com/sfml-game-development/book
[2]: http://www.sfml-dev.org/tutorials/2.0/compile-with-cmake.php