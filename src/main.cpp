#include <iostream>
#include "network.h"
#include <fstream>

using namespace std;

int main()
{




    network Net(true);
    Net.update();
    string const nomFichier2("Spike_times.txt");
    ofstream spikes(nomFichier2.c_str());





    if(spikes)
    {


        for(size_t i(0);i<Net.getSystmeNerveux().size();++i)
        {

            for (auto elt :Net.getSystmeNerveux()[i]->getTimes())
            {
                spikes<<elt<<'\t'<<i<<'\n';

            }

        }

    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier des spikes." << '\n';
    }

   spikes.close();
    return 0;
}