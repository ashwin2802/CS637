#pragma once

#include <map>
#include <unordered_map>
#include <vector>
#include <utility>
#include <random>

using namespace std;  // might remove later

enum class EdgeType { TYPE_1, TYPE_2, TYPE_3 };
enum class EdgeState { ON, OFF, UNDECIDED, DONTCARE };
enum class VertexState { WHITE, BLACK, GRAY };
enum class LaneType { NORTH, SOUTH, EAST, WEST };  // based on direction vehicle will move in if it does not turn