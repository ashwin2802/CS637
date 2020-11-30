#pragma once

#include <iostream>
#include <map>
#include <random>
#include <utility>
#include <vector>
#include <algorithm>
#include <utils/traci/TraCIAPI.h>

enum class EdgeType { TYPE_1, TYPE_2, TYPE_3 };
enum class EdgeState { ON, OFF, UNDECIDED, DONTCARE };
enum class VertexState { WHITE, BLACK, GRAY };
enum class LaneType { NORTH, SOUTH, EAST, WEST };  // based on direction vehicle will move in if it does not turn