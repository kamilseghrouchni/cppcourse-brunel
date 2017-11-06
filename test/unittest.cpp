//
// Created by kamil seghrouchni on 16/10/2017.
//
#include <iostream>
#include "../src/simulation.h"
#include "googletest/include/gtest/gtest.h"
#include <random>
#include <cmath>


/** \brief simulation tests
*
* Tests the simulation
* */



/** \brief Test the membrane potentiel value with a current   input
*
*with an input of 1 for the current
*
*testing the membrane potentiel for tow time steps with an expected value
*
* */

TEST(neurone, PositiveInput)
{
    neurone* p=new neurone();
    p->setCourant(1);
    bool up;
    up=p->Update(false);
    up=p->Update(false);
    EXPECT_NEAR(20*(1.0-std::exp(-0.1/20)),p->getPotentiel(),0.1);
    p= nullptr;

}

/** \brief test firing with a specific current input
*
*with a current of 1
*
*we expect no spike for the whole simulation
*
* */

TEST(neurone, NoSpikesTest)
{
    neurone* p = new neurone();
    p->setCourant(1);
    double stopTime(s::STOPTIME) ;
    bool update;
    for (size_t i(0); i<stopTime; ++i)
    {
        update=p->Update(false);
    }

    EXPECT_EQ(p->getTimes().size(),0);

    p= nullptr;

}




/** \brief  testing membrane potentiel for a whole simulation
*
*Membrane potentiel evolution with input current of 1
*
*the Membrane potentiel value is expected to be near the threshold
* */


TEST(neurone, MembranePotentielTest )
{
    neurone* p = new neurone();
    p->setCourant(1);//current will be seted at 1 ;
    double stopTime(s::STOPTIME) ;
    bool update;
    for (size_t i(0); i<stopTime; ++i)
    {
       update=p->Update(false);
    }

    EXPECT_NEAR(20,p->getPotentiel(),0.1);
    p=nullptr;


}


/** \brief testing if the brunnel model is Respected
*
*randomly chosen neuron
*
*we check if he has 1250 connections
*
*1000 excitatory
*
*250 inhibitory
* */

TEST(simulation , Amount_Connections_For_Randomly_Chosen_Neuron )
{

    simulation sim(new network(true));
    sim.Simulation();
    double Connections(0) ;
    double ExiConnections(0);
    double InhiConnections(0);
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(0,s::Max_Value_Connection);
       double index(dis(gen));
    for (size_t j(0);j<sim.getNet()->getSystmeNerveux().size();++j )
        {
            for (auto elt : sim.getNet()->getSystmeNerveux()[j]->getTargets())
            {
                if (elt == index)
                {
                    ++Connections;

                    if (j<s::Numb_Excitatory_Neurons)
                        ++ExiConnections;
                    else
                        ++InhiConnections;

                }
            }

        }

       EXPECT_EQ(Connections,s::Numb_Connections);
       EXPECT_EQ(ExiConnections,s::Excitatory_Connections);
       EXPECT_EQ(InhiConnections,s::Inhibitory_Connections);
    }

/** \brief Testing Spikes per Neuron
*
*For 1 second of simulation we expect roughly 30 spikes per neuron
*
*average of spikes for the wole simulation compared to an expected value
*
* */

TEST(network,AmountSpikePerNeuron)

{

    simulation sim(new network(true));
    sim.Simulation();
    double average(0);

    for (size_t i(0) ; i<12500 ; ++i)
    {
     average+=sim.getNet()->getSystmeNerveux()[i]->getTimes().size();
    }
    average=average/(s::Numb_Neurons);

    EXPECT_NEAR(average,30 ,4)  ;



}

int main(int argc, char**argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}