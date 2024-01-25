#ifndef __ANNEALING__
# define __ANNEALING__

# include "AProblemModel.hpp"
# include <cmath>

class SimulatedAnnealing
{
    private :
        float               _t;
        float               _t_decay_rate;
        float               _init_tmp;
        unsigned int         _l;
        unsigned int         _init;
        AProblem            &_pm;
        const unsigned int  _max_no_improv;

        void                compute_start_params();
        float               temp_decay_schedule(unsigned int step);
        unsigned int        superposition_decay_schedule(unsigned int step);
        float               p(float post, float pre);
        bool               	roll(float p);

    public :
        SimulatedAnnealing(AProblem &pm);
        SimulatedAnnealing(SimulatedAnnealing const &a);
        ~SimulatedAnnealing();
        SimulatedAnnealing  &operator=(SimulatedAnnealing const &a);

        void                simulate();
};

#endif