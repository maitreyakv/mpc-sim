/*
 * Copyright (C) 2020 Maitreya Venkataswamy - All Rights Reserved
 */

#ifndef AAVSIM_SIMULATION_H
#define AAVSIM_SIMULATION_H


#include "System.h"
#include "../navigation/PathPlanner.h"

/**
 * Implementation of a single simulation in the program
 *
 * This class represents a single simulation, which is used to organize the different elements of the simulation, as
 * well as provide a single object in which to initialize, execute, and export results from a simulation.
 */
class Simulation {

private:
    // System to be simulated
    System* m_system_ptr;

    // Time between MPC iterations
    double m_mpc_time_step;

    // Current state of the System in the Simulation
    arma::vec m_x;

    // Current time of the Simulation
    double m_t;

    // Target state of the Simulation
    arma::vec m_x_star;

    // Time horizon length of the control optimization process
    double m_horizon;

    // Pointer to PathPlanner used in simulation
    PathPlanner* m_path_planner_ptr;

public:
    /**
     * Constructor for a Simulation that uses member-list initialization
     *
     * @param system_ptr Pointer to the System being simulated
     * @param path_planner_ptr Pointer to PathPlanner used in simulation
     * @param mpc_time_step The time between MPC iterations
     * @param x_0 Vector with initial state of the System
     * @param x_star Vector with the target state of the System
     */
    Simulation(System* system_ptr, PathPlanner* path_planner_ptr, double mpc_time_step, arma::vec x_0,
                                                                                    arma::vec x_star, double horizon)
        : m_system_ptr(system_ptr),
          m_path_planner_ptr(path_planner_ptr),
          m_mpc_time_step(mpc_time_step),
          m_x(x_0),
          m_t(0.0),
          m_x_star(x_star),
          m_horizon(horizon)
    {}

    /**
     * Executes the simulation process by integrating the dynamics of the system while computing and using the optimal
     * control input
     *
     * @param time Total time to simulate the system for from the initial state
     * @return 0 if successful, nonzero otherwise
     */
    int simulate(double time);
};


#endif //AAVSIM_SIMULATION_H
