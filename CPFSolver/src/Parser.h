/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                   CPF Solver    2018                        *
 *                   Margarida Ferreira                        *
 *                                                             *
 * File: Parser.h:                                             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef _PARSER_
#define _PARSER_

#include "Instance.h"
#include <iostream>
#include <fstream>
#include <string>

class Parser {
private:
    std::ifstream _instance_file_stream;
    std::string _instance_file;

    std::vector<std::shared_ptr<Agent>> _agents;

public:
    explicit Parser(const std::string &instance_file)
            : _instance_file(instance_file) {

        _instance_file_stream.open(instance_file);
        if (!_instance_file_stream.is_open()) {
            std::cerr << "Could not open the file " << _instance_file << std::endl;
            exit(-1);
        }
    }

    ~Parser() {
        _instance_file_stream.close();
    }

    Instance parse();

	void set_agent_start(unsigned int a_id, Vertex v_id);

	void set_agent_goal(unsigned int agent_finishing_here, Vertex v_id);
};

#endif
