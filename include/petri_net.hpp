#pragma once

#include <common.hpp>
// #include <queue>
#include <list>
#include <rcg.hpp>
#include <unordered_set>

// i,i',j,number of vehicles
typedef std::pair<std::pair<int, int>, std::pair<int, int>> token;

struct hasher {
    size_t operator()(const token& t) const {
        // return t.second.first + t.second.second * t.second.second * (t.first.first + t.second.second * t.first.second);
        return t.first.second + t.second.second * t.first.first;
    }
};

struct comparator {
    bool operator()(const token& t1, const token& t2) const{
        return t1.first.first == t2.first.first && t1.first.second == t2.first.second && t1.second.first == t2.second.first;
    }
};
// size_t hash_function(token t);
typedef std::pair<std::unordered_set<token, hasher, comparator>, std::unordered_set<token, hasher, comparator>> transition; 

class PetriNet {
  public:
    PetriNet() {
    }
    PetriNet(TCG& graph);
    ~PetriNet() {
    }
    void simulate();
    void print();
    void print_transition(transition& t);
    void print_token(token& t);

//   private:
    std::list<transition> transitions;
    std::unordered_set<token, hasher, comparator> active_tokens;

  private:
    void type_one_transitions(TCG& graph);
    void type_two_and_three(TCG& graph);  
    // void construct_transitions();
};