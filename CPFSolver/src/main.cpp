#include <iostream>
#include <cstdlib>
#include "Instance.h"
#include "Graph.h"
#include "Parser.h"
#include "CPFSolver.h"

int main(int argc, const char **argv) {
    std::string filename = "../instances/grid_4x4_a6_o0.1_s616.cpf";
    int max_makespan = 10;
    int verbose = 0;

    if(argc == 1) {
        std::cout << "solving for default file: grid_4x4_a6_o0.1_s616.cpf" << std::endl;
        verbose = 2;
    }
    else if(argc == 2) {
        filename = argv[1];
        max_makespan = 32;
    }
    else if(argc == 3) {
        filename = argv[1];
        max_makespan = atoi(argv[2]);
    }
    else {
        for(int i = 3; i < argc; ++i) {
            std::string arg(argv[i]);
            if(arg == "-v") {
                verbose = atoi(argv[i+1]);
            }
        }
    }

    //Graph env1;
//
    //env1.add_edge(0, 1);
    //env1.add_edge(0, 2);
    //env1.add_edge(1, 3);
    //env1.add_edge(2, 3);
//
    //Agent a1(0, 0, 3);
    //Agent a2(1, 3, 0);
//
    //std::vector<Agent> agents1;
    //agents1.push_back(a1);
    //agents1.push_back(a2);
//
    //Instance inst1(env1, agents1);

//  Graph env2;
//  /* 0 1 2 *
//   * 3 4 5 *
//   * 6 7 8 */
//
//  env2.add_edge(0, 1);
//  env2.add_edge(1, 2);
//  env2.add_edge(3, 4);
//  env2.add_edge(4, 5);
//  env2.add_edge(6, 7);
//  env2.add_edge(7, 8);
//
//  env2.add_edge(0, 3);
//  env2.add_edge(3, 6);
//  env2.add_edge(1, 4);
//  env2.add_edge(4, 7);
//  env2.add_edge(2, 5);
//  env2.add_edge(5, 8);
//
//  Agent a3(0, 0, 5);
//  Agent a4(1, 2, 3);
//  Agent a5(2, 6, 2);

//  std::vector<Agent> agents2;
//  agents2.push_back(a3);
//  agents2.push_back(a4);
//  agents2.push_back(a5);
//
//  Instance inst2(env2, agents2);
//
    Parser parser(filename);

    Instance inst = parser.parse();
    
    if(verbose > 0)
        std::cout << inst << std::endl;

    std::cout << "Solving instance:" << std::endl;
    CPFSolver s1(inst, "simplified", "UNSAT-SAT", max_makespan, verbose);
    s1.solve();

}