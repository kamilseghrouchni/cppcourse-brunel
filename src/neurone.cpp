//
// Created by kamil seghrouchni on 02/10/2017.
//

#include "neurone.h"
#include <iostream>
#include <random>


neurone:: neurone (bool in)
    : inhibitory(in)
{
    potentiel=s::INITIAL_POTENTIAL;
    taw=20;
    neuroneclock=0;
    RefractoryTime=s::REFRACTORY_TIME;
    Refractroy=false;

    for(auto& elt : buffer)
    {
        elt=0;
    }

    times = {};

}


neurone:: ~neurone(){
    times.clear();
}

bool neurone::Update(bool val ,double poiss) {

    bool spiked = false;
//checking membrane potentiel value
    if (potentiel > s::POTENTIEL_TRESHOLD) {
        spiked = true;
        Refractroy=true;
        times.push_back(neuroneclock);
        potentiel = s::INITIAL_POTENTIAL;
    }
//checking whether the neuron is refractory or working
    if (Refractroy) {
        assert(potentiel<=0.0);
        RefractoryTimeDecrementation();
    } else {
        UpdatePotentiel(val,poiss);

    }

    buffer[neuroneclock % buffer.size()] = 0.0;
    assert(buffer[neuroneclock % buffer.size()] == 0.0);

    neuroneclock++;

    return spiked;
}

bool neurone::isInhibitory() const {
    return inhibitory;
}


void neurone::RefractoryTimeDecrementation()
{

    if (RefractoryTime<=0)
    {
        RefractoryTime=s::REFRACTORY_TIME;
        Refractroy=false;
    } else {
        RefractoryTime--;
    }

}


void neurone::UpdatePotentiel(bool a,double poisson )
{



    potentiel = exp((-1.0) * (s::SIMTIME / taw)) * potentiel
                + Iext * s::RESISTANCE * (1.0 - exp((-1.0) * ( s::SIMTIME / taw)));

    //adding  the income from ring buffer
    potentiel += buffer[neuroneclock%(buffer.size())];


    if (a) {
        //adding the background noise
        potentiel += poisson*s::Excitatory_weight;
    }

}

void neurone::receive(long t , double J) {
    assert(J != 0);
    //adding a signal to the ring buffer
    buffer[(t + s::DELAY) % (buffer.size())] += J;
}




std::list<long> neurone::getTimes()
{
    return times;
}

void neurone:: setCourant (double h)
{
    Iext=h;
}



std::vector<int> neurone::getTargets()
{
    return targets;
}

void neurone::addTargets(int neur)
{
    targets.push_back(neur);
}

std::list<double> neurone::getPotentiels()
{
    return Potentiels;
}



double neurone:: getPotentiel()
{
    return potentiel;
}
