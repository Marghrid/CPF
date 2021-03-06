/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                   CPF Solver    2018                        *
 *                   Margarida Ferreira                        *
 *                                                             *
 * File: UNSAT_SATSearch.h:                                    *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef __UNSAT_SAT_SEARCH__
#define __UNSAT_SAT_SEARCH__

#include "Search.h"

class UNSAT_SATSearch : public Search {
private:
    int _count;

public:
    UNSAT_SATSearch(int min_makespan, int max_makespan) : Search(min_makespan, max_makespan), _count(min_makespan) {}

    bool get_initial_solved() override { return false; }

    int get_initial_makespan() override { return _min_makespan; }

    int get_next_makespan(bool solved) override { return ++_count; }

    int get_successful_makespan() override { return _count - 1; }

    bool break_test(bool solved) override {
        //Returns true if search should stop:
        return solved || _count == _max_makespan + 1;
    }

    bool success() override { return _count != _max_makespan + 1; }

    const std::string name() const override { return "UNSAT-SAT"; }

};

#endif