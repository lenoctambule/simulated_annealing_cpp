#ifndef __ANNEALING__
# define __ANNEALING__

# include "AProblem.hpp"
# include <cmath>

class SimulatedAnnealing
{
    private :
        double               _t;
        double               _t_decay_rate;
        double               _init_tmp;
        unsigned int         _l;
        unsigned int         _init_l;
        AProblem            &_pm;
        unsigned int		_max_no_improv;

        void                compute_start_params();
        double              temp_decay_schedule(unsigned int step);
        unsigned int        superposition_decay_schedule(unsigned int step);
        double              p(double post, double pre);
        bool               	roll(double p);

    public :
        SimulatedAnnealing(AProblem &pm);
        SimulatedAnnealing(SimulatedAnnealing const &a);
        ~SimulatedAnnealing();
        SimulatedAnnealing  &operator=(SimulatedAnnealing const &a);

        void                simulate();
};

#endif