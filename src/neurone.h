//
// Created by kamil seghrouchni on 02/10/2017.
//

#ifndef FPROJECT_NEURONE_H
#define FPROJECT_NEURONE_H


#include <vector>
#include <array>
#include <cmath>
#include <list>
#include <cassert>
#include "Contants.h"


class neurone {
/** \brief  class that represent a Neuron
 *
 *Handles the Neuron behaviour
 *
 * */
public :
/** \brief  Neuron Constructor
 *
 *Initialise the Neuron depending on it's type
 *
 * inhibitory is initialized with a given booleen object
 *
 * all the other parameters are initialized to their initial values
 *
 *\param object type bool
 *
 * */
    neurone(bool inhib = false);

/** \brief  Neuron Destructor
 *
 *make sur to clear the time vector
 * */
    ~neurone();

/** \brief  Updates the  neuron
 *increment the neuroneclock
 * updates the membrane potentiel
 *
 *
 * clears the buffer for each time steps
 *
 * checks if the membrane potentiel is above the threshold
 *
 * if it's the case the function returns true , otherwise it returns false all the time
 *
 * it makes sure to store the time spike and reset potentiel value in case of spike
 *
 *sets the Refractory state depending on the membrane potentiel value
 *
 * if a spike has occur , Refractory is set to True
 *
 * \param object type booleen  to know the flag value
 * */
    bool Update(bool,double );

/** \brief  Updates the Neuron's membrane potentiel
 *
 *
 * Updates the membrane potentiel occroding to a given formula
 *
 * add's up any transmitted signal from the ring buffer
 *
 * add'up the background noise taken in parameter
 *
 * \param object type bool and double
 * */
    void UpdatePotentiel(bool,double );

/** \brief  Decrementation of the Refractory Time
 *
 *decrement the refractory time at each simulation step
 *
 * */
    void RefractoryTimeDecrementation();

/** \brief  Receive the incoming signal from other Neuron(s)
 *
 * the post-synaptic neuron receives the time simulation time when a neurone has spiked
 *
 * the post-synaptic neuron  receives the connection weight
 *
 * the function add's it to the buffer with a delay (spike arrival time)
 *
 * \param object type long ,double
 * */
    void receive (long,double);



/** \brief  Returns the spikes time
 *
 * lists are more optimized than vectors
 *
 * simulation would run faster
 *
 *\return object list of long
 * */
    std::list<long> getTimes();

/** \brief  Returns the membrane  potentiel value at a certain time
 *
 * for unittests
 *
 * \return object double
 * */
    double getPotentiel();

/** \brief  Returns all the post-synaptic neuron connections
 *
 * returns all the neurons that receive a signal when the neuron spikes
 *
 * the post-synaptic neurons are represented by their position in the NeuronSystem Vector
 *
 *\return object vector of int
 * */
    std::vector<int> getTargets() ;

/** \brief  Returns the membrane potentiels for the whole simualtion
*
*
*
*
* list more optimized
*\return object list of doubles
* */std::list<double>getPotentiels();

    /** \brief  sets the current
 *
 *in case we want to run the simulation with out the background noise
 *
 *\param object type double
 * */
    void setCourant (double ) ;

/** \brief  add's post-synaptic connections
 *
 *the post-synaptic neuron is represented by its  position in the NeuronSystem Vector
 *
 *
 *\param object int
 * */
    void addTargets (int);

/** \brief  returns the Neuron Type
 *
 *if the Neuron is Inhibitory it will return true , else it will return false
 *
 *\return object booleen
 * */
    bool isInhibitory() const;




private:
    double potentiel;               /*!< membrane poteniel of the neuron*/
    double taw;
    long neuroneclock;
    double RefractoryTime;
    bool Refractroy;
    bool inhibitory;
    std::list<long> times;
    double Iext;
    std::array<double ,16> buffer;    /*!< ring buffer that returns values depending on the neuron clock*/
    std::vector<int>targets;
    std::list<double>Potentiels;






};


#endif //FPROJECT_NEURONE_H
