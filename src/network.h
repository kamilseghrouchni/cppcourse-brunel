
// Created by kamil seghrouchni on 09/10/2017.
//

#ifndef FPROJECT_NETWORK_H
#define FPROJECT_NETWORK_H
#include "neurone.h"
#include "Contants.h"
#include <list>
#include <assert.h>
#include <iostream>

typedef std::vector<neurone*> Systemenerveux;

class network {
/** \brief Class that creates the Neuron System
 *
 * Handles Neurons and their connections
 *
 *\param NeuroneSystem          vectors that contains pointers of all the Neurons simulation
 * */

public :

    /** \brief Network constructor
 *
 *creates a Neuronal System depending on the user's will
 *the background noise of each neuron is flagged with a booleen object
 *Sets the Parameters of the Neuron System
 *Sets the Connections between each Neuron
 *\param object type booleen
 * */

    network(bool);

/** \brief Network  destructor
 *
 * Handles the Neuron pointers  of the Neuron System proper  destruction
 *
 * */
    ~network() ;
/** \brief  Returns the NeuronSystem
 *
 *
 * \return     object type Vector of Neuron
 *
 * */
    Systemenerveux getSystmeNerveux () const  ;


/** \brief  Set connections between each neuron
 *
 * this function connects  randomly every neuron to 1000 Excitatory and 250  Inhibitory
 *
 * the uniform distribution allows us to do so
 *
 * the parameters of the distribution or respectively
 *
 * the range of Excitatory and Inhibitory Neurons
 *
 * \return     object type Vector of Neuron
 *
 * */
    void setConnections();

/** \brief Sets the Neuronal Systeme
 *
 *It creats 12500 pointers on new neurons
 *
 * 10000 Excitatory and Inhibitory
 *
 * and add them to a vector called Neuronsystem
 *
 * \return     object type Vector of Neuron
 *
 * */
    void setNeuronalSysteme();



    /** \brief  set the Parameters of each Neurons
 *
 *depending on the flag value , the function will either set the current  to O
 *
 *or to an input
 *
 *
 * */
    void setParameters() ;

/** \brief  sets the flag
    *
    *allows us to choose whether or not we want the background noise effect
    *
    * this function is mainly usefull for previous unittests
    *
    * it affect the class attribut to an given booleen object
    *
    *\param    object type booleen
    *
    * */
    void setFlag (bool);

/** \brief  Updates every neuron
 *
 * calls the update function of each neuron
 *
 * if the neuron has spiked , the function transmit the spike to all his targets
 *
 * spike transmition involves a neuron function called receive
 *
 * the function takes the time simulation for a transmition matter
 *
 * \param  object type long
 *
 *
 * */
    void update (long) ;



private :

Systemenerveux NeuroneSysteme;       /*!< contains all the neuron pointers */


    bool flag ;

};



#endif //FPROJECT_NETWORK_H
