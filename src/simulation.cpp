//
// Created by kamil seghrouchni on 02/10/2017.
//

#include "simulation.h"

simulation::simulation (network* net ):Net(net)
{
simulation_clock=0;

}

simulation:: ~simulation()
{
    delete Net;
    Net=nullptr;

}


void simulation::Simulation()
{

    if (simulation_clock==0)
    {
        std::cout<<"Running..."<<std::endl;

    }

    while (simulation_clock<=s::STOPTIME)
    {
            Net->update(simulation_clock);
            simulation_clock++;

    }

}

network* simulation:: getNet()
{
    return Net;
}

