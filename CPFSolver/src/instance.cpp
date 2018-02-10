#include "instance.h"

#include <vector>
#include <iostream>

void Instance::add_agent(int a_id) {
	if((size_t)a_id >= _agents.size()) {
		for(int i = _agents.size(); i <= a_id; ++i) {
			Agent a(i);
			_agents.push_back(a);
			_vertex_starts_empty.push_back(true);
		}
	}
}

void Instance::set_start_empty(int a_id, bool b) {
	if((size_t)a_id >= _agents.size())
		return; //exception: unexistent agent
	_vertex_starts_empty[a_id] = b;
}

std::ostream& operator<<(std::ostream& os, const Instance& inst) {
	os << "---- CPF INSTANCE ----" << std::endl;
	os << "Environment: " << std::endl;
	os << "N vertices: "  << inst.n_vertices() << std::endl;
	os << "N edges: "     << inst.n_edges()    << std::endl;
	for (auto& e: inst._environment.edges()) {
		os << e << std::endl;
	}
	os << std::endl;
	os << "N agents: " << inst._agents.size() << std::endl;
	for (auto& a: inst._agents) {
		os << a << std::endl;
	}
	return os;
}

bool Instance::check() const {
	return true;
}