//
// Created by kamil seghrouchni on 09/10/2017.
//

#include "network.h"
#include <random>

network::network(bool val)
{
    setFlag(val);
    setNeuronalSysteme();
    setParameters();
    setConnections();
    simulation_clock=0;
}

network:: ~network()
{
//clears properly the pointers
    if (!NeuroneSysteme.empty())
    {
        for(size_t i(0 ); i<NeuroneSysteme.size(); ++i)
        {
            delete NeuroneSysteme[i];
            NeuroneSysteme[i]= nullptr;
        }
            NeuroneSysteme.clear();
    }


}


void network::update()
{

    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::poisson_distribution<> poisson(s::Vext*s::SIMTIME);

    if (simulation_clock==0)
    {
        std::cout<<"Running..."<<std::endl;

    }
    bool spike=false;


    while (simulation_clock<=s::STOPTIME)
    {


        for (size_t i(0); i < NeuroneSysteme.size(); ++i) {
            //Updates each Neuron
            spike = NeuroneSysteme[i]->Update(flag, poisson(gen));


            if (spike) {

                assert(NeuroneSysteme[i]->getPotentiel() == s::INITIAL_POTENTIAL);

                // the post-synaptic connection weight takes the correct value depending on Neuron type
                double J = NeuroneSysteme[i]->isInhibitory() ? s::Inhibitory_weight : s::Excitatory_weight;

                //look up for the neuron post-synaptic connections
                for (auto &target : NeuroneSysteme[i]->getTargets()) {

                    NeuroneSysteme[target]->receive(simulation_clock, J);
                }
            }
        }
        ++simulation_clock;
    }


}



Systemenerveux network ::getSystmeNerveux() const
{
    return NeuroneSysteme;
}



void network ::setNeuronalSysteme()
{
    NeuroneSysteme={};

    for (size_t i(0); i<s::Numb_Neurons;++i)
    {
        //Creation of 10000 Excitatory Neurons first
        if (i < s::Numb_Excitatory_Neurons)
            NeuroneSysteme.push_back(new neurone(false));
         //then 2500 Inhibitory ones
        else
            NeuroneSysteme.push_back(new neurone(true));
    }

    assert(NeuroneSysteme.size()==s::Numb_Neurons);
    assert(!NeuroneSysteme.empty());
}
void network::setParameters()
{
    for(size_t i (0) ; i<NeuroneSysteme.size();++i)
    {
      if (!flag)
      {
           double bal;
          std::cin>>bal;
          NeuroneSysteme[i]->setCourant(bal);
      }
        else
      {
          NeuroneSysteme[i]->setCourant(0);

      }



    }

}


void network:: setConnections() {
   static  std::random_device rd;  //Will be used to obtain a seed for the random number engine
    static std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    static std::uniform_int_distribution<> disExc(0,s::Max_Value_Excitatory);
    static std::uniform_int_distribution<> disInh(s::Numb_Excitatory_Neurons, s::Max_Value_Connection);

    std::cout<<"setting ..."<<std::endl;

    for (size_t i(0); i < NeuroneSysteme.size(); ++i)
    {



        for (size_t j(0); j < s::Numb_Connections; ++j)
        {
          // for each Neuron ...
            if (j < s::Excitatory_Connections)
             // random generation of 1000 Excitatory Neurons connections first
                NeuroneSysteme[disExc(gen)]->addTargets(i);

            else
              // then 250 Inhibitory  ones
                NeuroneSysteme[disInh(gen)]->addTargets(i);
        }



    }

}

void network::setFlag(bool f)
{
flag=f;
}