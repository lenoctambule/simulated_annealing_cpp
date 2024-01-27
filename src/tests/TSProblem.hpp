#ifndef _TSP_
# define _TSP
# include <AProblem.hpp>
# include <cstddef>

class TSProblem : public AProblem
{
    private :
        unsigned int    _size;
        size_t          _transform[2];
        double           **_adj_matrix;
        unsigned int    *_state;
        unsigned int    *_state_buffer;

        double           state_cost(unsigned int *state) const;
        void            apply_transform(unsigned int *state);

    public :
        TSProblem(double **adj_matrix, unsigned int size);
        virtual ~TSProblem();

        unsigned int    *getState() const;

        virtual double generate_candidate(int l);
        virtual double candidate_cost() const;
        virtual double current_cost() const;
        virtual void validate_candidate();
        virtual void discard_candidate();

        void            debug_state() const;
};

#endif