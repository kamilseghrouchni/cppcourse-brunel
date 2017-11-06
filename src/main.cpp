#include <iostream>
#include "simulation.h"
#include <fstream>
#include <random>

using namespace std;

int main()
{




    simulation fsim(new network(true));
    fsim.Simulation();

    string const nomFichier2("Spike_times.txt");
    ofstream spikes(nomFichier2.c_str());





    if(spikes)
    {


        for(size_t i(0);i<fsim.getNet()->getSystmeNerveux().size();++i)
        {

            for (auto elt : fsim.getNet()->getSystmeNerveux()[i]->getTimes())
            {
                spikes<<elt<<'\t'<<i<<'\n';

            }




            /*
            std::random_device rd;  //Will be used to obtain a seed for the random number engine
            std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
            std::uniform_int_distribution<> dis(s::Min_Value_Connection,s::Max_Value_Connection);
            cout<<"writing spikes"<<endl;
            for (unsigned int i (0); i<50; ++i)
            {
                double id(dis(gen));

                for (auto elt : network.getSystmeNerveux()[id]->getTimes())
                {
                    spikes<<elt<<"    "<<id<<std::endl;

                }
      */


        }

    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier des spikes." << '\n';
    }

   spikes.close();
    return 0;
}