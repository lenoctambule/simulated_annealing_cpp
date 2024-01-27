#include "TSProblem.hpp"
#include <iostream>

TSProblem::TSProblem(double **adj_matrix, unsigned int size) :
            _size(size),
            _adj_matrix(adj_matrix)
{
    this->_state = new unsigned int[this->_size];
    this->_state_buffer = new unsigned int[this->_size];
    for (unsigned int i = 0; i < size; i++)
    {
        this->_state_buffer[i] = i;
        this->_state[i] = i;
    }
    srand(time(0));
}

unsigned int  *TSProblem::getState() const
{
    return this->_state;
}

TSProblem::~TSProblem()
{
    delete[] _state;
    delete[] _state_buffer;
}

double   TSProblem::state_cost(unsigned int *state) const
{
    double   ret = 0;

    for (unsigned int i = 0; i < this->_size - 1; i++)
        ret += this->_adj_matrix[state[i]][state[i+1]];
    ret += this->_adj_matrix[0][state[this->_size - 1]];
    return ret;
}

double   TSProblem::current_cost() const
{
    return this->state_cost(this->_state);
}

double   TSProblem::candidate_cost() const
{
    return this->state_cost(this->_state_buffer);
}

void    TSProblem::apply_transform(unsigned int *state)
{
    state[_transform[0]] = state[_transform[0]] ^ state[_transform[1]];
    state[_transform[1]] = state[_transform[0]] ^ state[_transform[1]];
    state[_transform[0]] = state[_transform[0]] ^ state[_transform[1]];
}

double   TSProblem::generate_candidate(int l)
{
    (void) l;

    _transform[0] = rand() % (this->_size - 1) + 1;
    while ((_transform[1] = rand() % (this->_size - 1) + 1) == _transform[0])
        ;
    apply_transform(this->_state_buffer);
    return this->state_cost(this->_state_buffer);
}

void    TSProblem::validate_candidate()
{
    apply_transform(this->_state);
}

void    TSProblem::discard_candidate()
{
    apply_transform(this->_state_buffer);
}

void	TSProblem::debug_state() const
{
	std::cout << "Current state :";
	for (unsigned int i = 0; i < this->_size; i++)
		std::cout << " " << this->_state[i];
	std::cout << std::endl;
}