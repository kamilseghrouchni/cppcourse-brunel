//
// Created by kamil seghrouchni on 13/10/2017.
//

#ifndef FPROJECT_CONTANTS_H
#define FPROJECT_CONTANTS_H

#include <cmath>

namespace s {


    /** Membrane potentiel threshold
     * when a membrane potentile  is above this value ,it fires a spike
     */

    constexpr auto POTENTIEL_TRESHOLD = 20 ;

    ///  value of each simulation step
    constexpr auto SIMTIME = 0.1;

    /// Maximum value for simulation time
    constexpr auto STOPTIME= 10000 ;

    /// Membrane initial potential
    constexpr auto INITIAL_POTENTIAL = 0;

    /// Resistance of neurone membrane (Gohms)
    constexpr auto RESISTANCE=20;

    /** Refractory time
     * amount of time steps where neurone is inactive after firing a spike
     */
    constexpr auto REFRACTORY_TIME= 20 ;

    ///amount of time steps that a signal needs to be transmitted
    constexpr int DELAY= 15;


    constexpr auto Excitatory_weight= 0.1;      /*!< value of an exitatory connection*/
    constexpr auto Inhibitory_weight= -0.5; /*!<value of an inhibitory connection*/
    //Frequency of spikes due the background noise

    constexpr auto TAW = 20 ;
    constexpr auto ETA= 2 ;


    constexpr auto Vext = ETA*(POTENTIEL_TRESHOLD/(TAW*Excitatory_weight));


    constexpr auto Numb_Connections= 1250;               /*!<Total amount of connections between neurons*/
    constexpr auto Excitatory_Connections = 1000;      /*!<10 % of the Excitatory Neurons */
    constexpr auto Inhibitory_Connections =250; /*!<10% of Inhibitory Neurons */

    //Total  amount of Excitatory Neurons
    constexpr auto Numb_Excitatory_Neurons=10000;


    constexpr auto Max_Value_Connection=12499;  /*!<Needed value for the network creation*/
    constexpr auto Max_Value_Excitatory=9999; /*!<Needed value for the network creation*/

    //Total amount of Neurons for the simulation
    constexpr auto Numb_Neurons=12500;




}


#endif //FPROJECT_CONTANTS_H
