//
// Created by kamil seghrouchni on 02/10/2017.
//

#ifndef FPROJECT_SIMULATION_H
#define FPROJECT_SIMULATION_H
#include<vector>
#include<array>
#include"neurone.h"
#include"network.h"
#include "Contants.h"
typedef std::vector<neurone*> Neurones ;

class simulation {

    /** \brief Class that creates the simulation
 *
 * Runs the simulation
 * */

public :


/** \brief Simulation constructor
 *
 * Initialize the simualtion clock to zero
 *
 * Initialize  the Network pointer with a given object
 * \param      object type pointer on network
 * */
    simulation(network*) ;


/** \brief Simulation destructor
 *
 * Handles the Network pointer proper  destruction
 *
 * \param     object type pointer on network
 *
 * */
    ~simulation();


    /** \brief Runs the simulation
 *
 * Calls the update function of the network for each time steps
 * increment the simulation clock
 * simulation stops when the simulation clock value is equal to the stoptime
 *
 * */
    void Simulation();

    /** \brief Returns the updated network
 *
 * \return     object type pointer on network
 *
 * */
    network* getNet();



private :

long simulation_clock; /*!< time of our simulation*/
network* Net;       /*!< Network simulated */

};


#endif //FPROJECT_SIMULATION_H
