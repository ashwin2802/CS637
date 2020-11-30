# CS637
Course Project repository.

## Build Instructions

Requires a working version of CMake. (Min version: 2.8.3)

To compile, run the following commands on a terminal, in the repository directory:

```
rm -rf build
mkdir build && cd build
cmake ..
make
```

Executables are stored in the `bin` directory post build.

## Instructions for using the experimental code to visualize the TCG

For this, you are going to need SUMO simulator, both the repository(for using its dev library) and the debian package

To install SUMO, 

```
sudo apt-get install sumo sumo-doc sumo-tools 
```

Also, clone the repository on your computer and set SUMO_HOME to that directory
```
git clone --recursive https://github.com/eclipse/sumo
sudo apt-get install cmake python g++ libxerces-c-dev libfox-1.6-dev libgdal-dev libproj-dev libgl2ps-dev swig
cd <SUMO_DIR> # please insert the correct directory name here
echo "export SUMO_HOME=$PWD" >> ~/.bashrc
```

To run the experimental test file, follow these instructions
```
cd <THIS_REPO> # please cd to the root of this repo
./bin/test
```
This will then ask you open SUMO-GUI and then press any key to continue.
In a new terminal, open SUMO GUI with the requisite file using this command
```
cd <THIS_REPO> # please cd to the root of this repo
sumo-gui -c SUMO/Intersection/intersection_refined.sumocfg --remote-port 1337 --start
```

Come back to the previous terminal, and press any key and hit enter to continue. You can then see the simulation running in the SUMO-GUI
The simulation is actually running 10x slower, for better visualization and debugging.
