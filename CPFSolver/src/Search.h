#ifndef __SEARCH__
#define __SEARCH__

class Search {
protected:
	int _max_makespan;
public:
	Search(int max_makespan) { _max_makespan = max_makespan; }
	virtual~Search() {}

	virtual bool get_initial_solved() = 0;
	virtual int  get_initial_makespan() = 0;
	virtual int  get_next_makespan() = 0;
	virtual int  get_previous_makespan() = 0;
	virtual bool break_test(int makespan, bool solved) = 0;

	virtual bool success() = 0;
};

#endif