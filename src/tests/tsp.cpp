#include "AProblem.hpp"
#include "SimulatedAnnealing.hpp"
#include "TSProblem.hpp"

#include <iostream>

int    main()
{
    double    adj_mat[5][5] = {
            {0.        , 5.20791625, 0.89022274, 4.94117814, 5.17786569},
            {5.20791625, 0.        , 4.31769352, 0.26673811, 0.03005056},
            {0.89022274, 4.31769352, 0.        , 4.05095541, 4.28764295},
            {4.94117814, 0.26673811, 4.05095541, 0.        , 0.23668755},
            {5.17786569, 0.03005056, 4.28764295, 0.23668755, 0.        }
        };

    double **mat = new double*[5];
    for (int i = 0; i < 5; i++)
        mat[i] = new double[5];
    for(int i=0; i < 5; i++)
        for(int j=0; j < 5; j++)
            mat[i][j] = adj_mat[i][j];

    TSProblem tsp(mat, 5);
    SimulatedAnnealing annealing(tsp);
    annealing.simulate();
    tsp.debug_state();
    std::cout << "Cost : " << tsp.current_cost() << std::endl;

    for (int i = 0; i < 5; i++)
        delete[] mat[i];
    delete[] mat;
}