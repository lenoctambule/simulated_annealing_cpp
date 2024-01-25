#ifndef __APROBLEM__
# define __APROBLEM__

class AProblem {
	public :
		AProblem();
		~AProblem();

		virtual float	generate_candidate()	= 0;
		virtual float	candidate_cost() 		= 0;
		virtual float	current_cost()			= 0;
		virtual void	validate_candidate()	= 0;
		virtual void	discard_candidate()		= 0;
		virtual	void	get_current_state()		= 0;
};

#endif