# include "SimulatedAnnealing.hpp"

SimulatedAnnealing::SimulatedAnnealing(AProblem &pm) :
    _pm(pm),
    _max_no_improv(1000)
{
    this->compute_start_params();
}

SimulatedAnnealing::SimulatedAnnealing(SimulatedAnnealing const &a) :
    _pm(a._pm),
    _max_no_improv(a._max_no_improv),
    _init_tmp(a._init_tmp),
    _t(a._t)
{
}

SimulatedAnnealing::~SimulatedAnnealing()
{
}

SimulatedAnnealing  &SimulatedAnnealing::operator=(SimulatedAnnealing const &a)
{
    this->_init_tmp = a._init_tmp;
    this->_pm       = a._pm;
    this->_t        = a._t;
}

float               SimulatedAnnealing::temp_decay_schedule(unsigned int step)
{
    return (exp(-step * this->_t_decay_rate) * this->_init_tmp);
}

unsigned int        SimulatedAnnealing::superposition_decay_schedule(unsigned int step)
{
    /* TODO */
    return this->_l;
}

void                SimulatedAnnealing::simulate()
{
    unsigned int	no_improv   = 0;
    unsigned int    j           = 0;
    float           pre         = 0;
    float           post        = 0;

    while (this->_t > 0.01 && no_improv < this->_max_no_improv)
    {
        pre	        = _pm.current_cost();
        post        = _pm.generate_candidate();
        if (pre < post && this->roll(this->p(pre, post)))
        {
            this->_pm.discard_candidate();
            no_improv++;
        }
        else
        {
            this->_pm.validate_candidate();
            no_improv = 0;
        }
        j++;
        this->_t = this->temp_decay_schedule(j);
        this->_l = this->superposition_decay_schedule(j);
    }
}