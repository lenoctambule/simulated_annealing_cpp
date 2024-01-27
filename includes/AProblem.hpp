#ifndef __APROBLEM__
# define __APROBLEM__

class AProblem {
    public :
        AProblem();
        ~AProblem();

        virtual double generate_candidate(int l) = 0;
        virtual double candidate_cost() const    = 0;
        virtual double current_cost() const      = 0;
        virtual void validate_candidate()        = 0;
        virtual void discard_candidate()         = 0;
};

#endif