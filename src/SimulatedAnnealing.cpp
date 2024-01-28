# include "SimulatedAnnealing.hpp"
#include <iostream>

SimulatedAnnealing::SimulatedAnnealing(AProblem &pm) :
    _pm(pm),
    _max_no_improv(1000)
{
    this->compute_start_params();
	srand(time(0));
}

SimulatedAnnealing::SimulatedAnnealing(SimulatedAnnealing const &a) : _pm(a._pm)
{
    *this = a;
}

SimulatedAnnealing::~SimulatedAnnealing()
{
}

SimulatedAnnealing  &SimulatedAnnealing::operator=(SimulatedAnnealing const &a)
{
	_t = a._t;
    _t_decay_rate = a._t_decay_rate;
    _init_tmp = a._init_tmp;
    _l = a._l;
    _init_l = a._init_l;
	_pm = a._pm;
    _max_no_improv = a._max_no_improv;

    return *this;
}

double               SimulatedAnnealing::temp_decay_schedule(unsigned int step)
{
    return (exp(step * this->_t_decay_rate * -1) * this->_init_tmp);
}

unsigned int        SimulatedAnnealing::superposition_decay_schedule(unsigned int step)
{
	(void) step;
    /* TODO */
    return this->_l;
}

void                SimulatedAnnealing::compute_start_params()
{
    double   pre = 0;
    double   post = 0;
    double   sum_deltas = 0;

    for (int i = 0; i < 100; i++)
    {
        pre = this->_pm.current_cost();
        post = this->_pm.generate_candidate(this->_l);
		this->_pm.discard_candidate();
        sum_deltas += (pre - post);
    }
    this->_init_tmp = (sum_deltas) / log(100);
	this->_t = this->_init_tmp;
	this->_t_decay_rate = 0.001;
}

double				SimulatedAnnealing::p(double pre, double post)
{
	return exp((pre - post) / this->_t);
}

bool				SimulatedAnnealing::roll(double p)
{
	double r = ((double) rand() / (RAND_MAX)) + 1;

	return r > p;
}

void                SimulatedAnnealing::simulate()
{
    unsigned int	no_improv   = 0;
    unsigned int    j           = 0;
    double          pre         = 0;
    double          post        = 0;

    while (this->_t > 0.01 && no_improv < this->_max_no_improv)
    {
        pre         = _pm.current_cost();
        post        = _pm.generate_candidate(this->_l);
        if (pre < post && this->roll(this->p(pre, post)))
        {
		    no_improv++;
			this->_pm.discard_candidate();
		}
        else
        {
            this->_pm.validate_candidate();
            no_improv = 0;
        }
		this->_t = this->temp_decay_schedule(j);
        this->_l = this->superposition_decay_schedule(j);
        j++;
    }
}