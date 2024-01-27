# Simulated Annealing for C++

An implementation of simulated annealing for C++.

## Installation :

```txt
$> git clone git@github.com:lenoctambule/simulated_annealing_cpp.git
$> cd simulated_annealing_cpp
$> make
```

## Usage :

Create a class that inherits from AProblem and implement the following the methods :
- `generate_candidate` : generates a candidate neighbouring state of the system and returns the cost of the system at this state.
- `candidate_cost` :  returns the cost of the candidate.
- `current_cost` : which will return the cost of the system.
- `validate_candidate` : which will transition definitely the system to it's generated neighbouring state.
- `discard_candidate` : will cancel and not apply any transformations to the system.

## To-be-done:

- [ ] Find a problem-independent method to compute the temperature decay schedule.
- [ ] Implement another test