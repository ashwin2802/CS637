#include <iostream>
#include <fstream>
#include <utils/traci/TraCIAPI.h>
#include <unistd.h>
#include <petri_net.hpp>
#include <rcg.hpp> 

TCG examplea() {
    TCG G;

    std::vector<std::pair<std::pair<int, int>, Edge>> v;
    Edge e;

    e.type = EdgeType::TYPE_1;
    v.push_back({{2, 2}, e});
    // e.type = EdgeType::TYPE_3;
    // v.push_back({{2, 1}, e});
    G.edges.insert({{2, 1}, v});
    v.clear();

    e.type = EdgeType::TYPE_1;
    v.push_back({{1, 3}, e});
    G.edges.insert({{1, 2}, v});
    v.clear();

    e.type = EdgeType::TYPE_3;
    v.push_back({{1, 2}, e});
    G.edges.insert({{2, 2}, v});
    v.clear();

    G.vertices.clear();
    Vertex k;
    k.first_i = true;

    k.first_j = true;
    k.start_time = 1;
    G.vertices.insert({{2, 1}, k});

    k.first_j = false;
    k.start_time = 1;
    G.vertices.insert({{2, 2}, k});

    k.first_j = true;
    k.start_time = 0;
    G.vertices.insert({{1, 2}, k});

    k.first_j = false;
    k.start_time = 0;
    G.vertices.insert({{1, 3}, k});

    G.m = 2;
    G.n = 4;
    G.e = 3;
    G.v = 4;

    return G;
}

TCG exampleb() {
    TCG G;

    std::vector<std::pair<std::pair<int, int>, Edge>> v;
    Edge e;

    e.type = EdgeType::TYPE_1;
    v.push_back({{1, 3}, e});
    e.type = EdgeType::TYPE_3;
    v.push_back({{2, 1}, e});
    G.edges.insert({{1, 1}, v});
    v.clear();

    e.type = EdgeType::TYPE_1;
    v.push_back({{2, 2}, e});
    G.edges.insert({{2, 1}, v});
    v.clear();

    e.type = EdgeType::TYPE_1;
    v.push_back({{2, 3}, e});
    G.edges.insert({{2, 2}, v});
    v.clear();

    e.type = EdgeType::TYPE_3;
    v.push_back({{1, 3}, e});
    G.edges.insert({{2, 3}, v});
    v.clear();

    G.vertices.clear();
    Vertex k;
    k.first_i = true;

    k.first_j = true;
    G.vertices.insert({{1, 1}, k});

    k.first_j = false;
    G.vertices.insert({{1, 2}, k});

    k.first_j = true;
    G.vertices.insert({{2, 1}, k});

    k.first_j = false;
    G.vertices.insert({{2, 2}, k});
    G.vertices.insert({{2, 3}, k});

    G.m = 2;

    return G;
}

TCG examplec() {
    TCG G;

    std::vector<std::pair<std::pair<int, int>, Edge>> v;
    Edge e;

    e.type = EdgeType::TYPE_1;
    v.push_back({{1, 3}, e});
    e.type = EdgeType::TYPE_3;
    v.push_back({{2, 1}, e});
    G.edges.insert({{1, 1}, v});
    v.clear();

    e.type = EdgeType::TYPE_1;
    v.push_back({{2, 2}, e});
    G.edges.insert({{2, 1}, v});
    v.clear();

    e.type = EdgeType::TYPE_1;
    v.push_back({{3, 3}, e});
    G.edges.insert({{3, 2}, v});
    v.clear();

    e.type = EdgeType::TYPE_3;
    v.push_back({{3, 2}, e});
    G.edges.insert({{2, 2}, v});
    v.clear();

    e.type = EdgeType::TYPE_3;
    v.push_back({{1, 3}, e});
    G.edges.insert({{3, 3}, v});
    v.clear();

    G.vertices.clear();
    Vertex k;
    k.first_i = true;

    k.first_j = true;
    G.vertices.insert({{1, 1}, k});

    k.first_j = false;
    G.vertices.insert({{1, 3}, k});

    k.first_j = true;
    G.vertices.insert({{2, 1}, k});

    k.first_j = false;
    G.vertices.insert({{2, 2}, k});

    k.first_j = true;
    G.vertices.insert({{3, 2}, k});

    k.first_j = false;
    G.vertices.insert({{3, 3}, k});

    G.m = 3;

    return G;
}

TCG exampled() {
    TCG G;

    std::vector<std::pair<std::pair<int, int>, Edge>> v;
    Edge e;

    e.type = EdgeType::TYPE_1;
    v.push_back({{1, 2}, e});
    e.type = EdgeType::TYPE_3;
    v.push_back({{2, 1}, e});
    G.edges.insert({{1, 1}, v});
    v.clear();

    e.type = EdgeType::TYPE_1;
    v.push_back({{2, 2}, e});
    G.edges.insert({{2, 1}, v});
    v.clear();

    e.type = EdgeType::TYPE_3;
    v.push_back({{2, 2}, e});
    G.edges.insert({{1, 2}, v});
    v.clear();

    G.vertices.clear();   // e.type = EdgeType::TYPE_3;
    // v.push_back({{2, 1}, e});
    Vertex k;
    k.first_i = true;

    k.first_j = true;
    G.vertices.insert({{1, 1}, k});

    k.first_j = false;
    G.vertices.insert({{1, 2}, k});

    k.first_j = true;
    G.vertices.insert({{2, 1}, k});

    k.first_j = false;
    G.vertices.insert({{2, 2}, k});

    G.m = 2;

    return G;
}

TCG examplee() {
    TCG G;

    std::vector<std::pair<std::pair<int, int>, Edge>> v;
    Edge e;

    e.type = EdgeType::TYPE_1;
    v.push_back({{1, 3}, e});
    e.type = EdgeType::TYPE_3;
    v.push_back({{2, 1}, e});
    G.edges.insert({{1, 1}, v});
    v.clear();

    e.type = EdgeType::TYPE_1;
    v.push_back({{2, 2}, e});
    G.edges.insert({{2, 1}, v});
    v.clear();

    e.type = EdgeType::TYPE_1;
    v.push_back({{2, 3}, e});
    G.edges.insert({{2, 2}, v});
    v.clear();

    e.type = EdgeType::TYPE_3;
    v.push_back({{2, 3}, e});
    G.edges.insert({{1, 3}, v});
    v.clear();

    G.vertices.clear();
    Vertex k;
    k.first_i = true;

    k.first_j = true;
    G.vertices.insert({{1, 1}, k});

    k.first_j = false;
    G.vertices.insert({{1, 2}, k});

    k.first_j = true;
    G.vertices.insert({{2, 1}, k});

    k.first_j = false;
    G.vertices.insert({{2, 2}, k});
    G.vertices.insert({{2, 3}, k});

    G.m = 2;

    return G;
}

class Client : public TraCIAPI {
public:
    Client() {};
    ~Client() {};
};


std::fstream& go_to_line(std::fstream& file, unsigned int num){
    file.seekg(std::ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
}

void generate_routes(TCG& G, std::vector<std::pair<double, bool>>& vehicle_info, std::list<double>& entering_times) {
    std::ifstream route_file_template("SUMO/Intersection/intersection_refined.rou.xml", std::ios_base::app);
    std::ofstream route_file("SUMO/Intersection/intersection_refined_copy.rou.xml");
    route_file << route_file_template.rdbuf();
    route_file_template.close();

    for (int i=1; i<=G.m; i++) {
        std::string to_write = "<vehicle id=\"vehicle_" + std::to_string(i) + "\" depart=\"";

        for (int j=1; j<=G.n; j++) {
            if (G.vertices[std::pair<int, int>(i,j)].first_j == true) {
                to_write = to_write + std::to_string(G.vertices[std::pair<int, int>(i,j)].start_time*10) + "\" route=\"" + std::to_string(j);

                int curr_j = j;
                int num_cz = 1;

                while (1) {
                    if (G.edges[std::pair<int, int>(i,curr_j)].size() == 0 || G.edges[std::pair<int, int>(i,curr_j)][0].second.type != EdgeType::TYPE_1) {
                        to_write = to_write + std::to_string(curr_j) +"\" type=\"default_type\" />\n";
                        break;
                    }
                    curr_j = G.edges[std::pair<int, int>(i,curr_j)][0].first.second;
                    num_cz++;
                }

                entering_times.push_back(G.vertices[std::pair<int, int>(i,j)].start_time);

                switch (num_cz)
                {
                case 1:
                    vehicle_info.push_back({2.1,false});
                    break;
                case 2:
                    vehicle_info.push_back({2.3,false});
                    break;                    
                
                default:
                    vehicle_info.push_back({2.2,false});
                    break;
                }
                
                std::cout << to_write << std::endl;

                route_file << to_write;
                break;
            }
        }

    }

    route_file << "</routes>";
    route_file.close();
    
}

int main(int argc, char* argv[]) {
    Client client;
    TCG G = examplea();
    PetriNet P(G);
    std::vector<std::pair<double, bool>> vehicle_info;
    std::list<std::pair<transition, int>> ongoing_transitions;
    std::list<double> start_times;

    generate_routes(G, vehicle_info, start_times);

    std::cout << "Please open the requisite file in sumo gui and press enter";
    std::string dump;

    std::cin >> dump;

    client.connect("localhost", 1337);

    std::vector<token> type_one_buffer;
    std::list<std::vector<token>> type_two_three_buffer;

    //Just putting empty vectors
    type_two_three_buffer.push_back(type_one_buffer);
    type_two_three_buffer.push_back(type_one_buffer);
    

    while (!P.transitions.empty()){
        if (client.simulation.getCurrentTime() == start_times.front()*10000) {
            // std::cout << std::to_string(G.m - start_times.size() + 1) <<std::endl;
            client.vehicle.setSpeed("vehicle_" + std::to_string(G.m - start_times.size() + 1), 0);
            P.active_tokens.insert({{{G.m - start_times.size() + 1, G.m - start_times.size() + 1},{0, G.m}}});
            start_times.pop_front();
        }

        for (auto token : type_one_buffer) {
            P.active_tokens.insert(token);
        }
        type_one_buffer.clear();

        for (auto token : type_two_three_buffer.front()) {
            P.active_tokens.insert(token);
        }

        type_two_three_buffer.pop_front();
        std::vector<token> type_two_three_insert;
        
        for (auto check_t=ongoing_transitions.begin(); check_t != ongoing_transitions.end();) {
            if (check_t->second*10000 == client.simulation.getCurrentTime()) {
                auto it = P.transitions.begin();
                for (;(*it) != check_t->first; it++);
                for (auto token_it : it->first) {
                    P.active_tokens.erase(token_it);
                }

                for (auto token_it : it->second) {
                    if (token_it.first.first == token_it.first.second) {
                        type_one_buffer.push_back(token_it);
                    } else {
                        type_two_three_insert.push_back(token_it);
                    }
                }  

                P.transitions.erase(it);
                auto copy = check_t;
                
                int vehicle_number;

                for (auto vehicle : check_t->first.first) {
                    if (vehicle.first.first == vehicle.first.second) {
                        vehicle_number = vehicle.first.first;
                        break;
                    }
                }

                vehicle_info[vehicle_number-1].second = false;

                std::cout << vehicle_number << std::endl;
                client.vehicle.setSpeed("vehicle_" + std::to_string(vehicle_number), 0);

                check_t++;
                ongoing_transitions.erase(copy);

            } else {
                check_t++;
            }
        }

        type_two_three_buffer.push_back(type_two_three_insert);

        auto it = P.transitions.begin();
        while (it != P.transitions.end()) {
            bool all_tokens_present = true;
            for (auto token_it : it->first) {
                if (P.active_tokens.find(token_it) == P.active_tokens.end()) {
                    all_tokens_present = false;
                    break;
                }
            }

            if (all_tokens_present) {
                ongoing_transitions.push_back({*it, client.simulation.getCurrentTime()+10000});
                auto copy = it;
                it++;
                P.transitions.erase(copy);

                int vehicle_number;

                for (auto vehicle : it->first) {
                    if (vehicle.first.first == vehicle.first.second) {
                        vehicle_number = vehicle.first.first;
                        break;
                    }
                }

                vehicle_info[vehicle_number-1].second = true;
                std::cout << vehicle_number << std::endl;
                client.vehicle.setSpeed("vehicle_" + std::to_string(vehicle_number), vehicle_info[vehicle_number-1].first);

            } else {
                it++;
            }
        }

        client.simulationStep();
        for (auto it : P.active_tokens) {
            P.print_token(it);
            std::cout << std::endl;
        }
        usleep(1000000);
    }

    // client.connect("localhost", 1337);
    // client.vehicle.setSpeed("vehicle_0", 2.2);
    // client.vehicle.setSpeed("vehicle_0", 2.3);
    // client.vehicle.setSpeed("vehicle_1", 2.3);
    // client.vehicle.setSpeed("vehicle_0", 2.1);
    // client.vehicle.setType("vehicle_0", "type_1");
    // client.vehicle.setType("vehicle_1", "type_1");
    // client.vehicletype.setWidth("default_type", 0.5);
    // client.simulationStep(0.5);
    // while (client.simulation.getCurrentTime() < 50000) {
        // std::cout << client.simulation.getCurrentTime() << std::endl;
        // client.simulationStep();
        // if (client.simulation.getCurrentTime() == 10000) {
        //     client.vehicle.setSpeed("vehicle_0", 0);
        // } else if (client.simulation.getCurrentTime() == 20000) {
        //     client.vehicle.setSpeed("vehicle_0", 1);
        // } 

        // client.vehicle.tr
        // usleep(100000);
        // sleep(1);
    // }
    // client.simulationStep(5);
    // std::cout << "time in s: " << client.simulation.getTime() << "\n";
    // client.close();
    // generate_routes();
    return 0;
}