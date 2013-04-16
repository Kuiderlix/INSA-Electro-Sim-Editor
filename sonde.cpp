/* 
 * File:   sonde.cpp
 * Author: camille
 * 
 * Created on February 26, 2013, 9:37 PM
 */

#include "sonde.h"
#include <string>
#include <sstream>
#include "Ecriture.h"

sonde::sonde() {
}

sonde::sonde(const sonde& orig) {
}

sonde::~sonde() {
}

void sonde::ecrire(int nb){

    std::ostringstream monEcriture;
    monEcriture << "Sonde_numero_" << nb << "\n";
    monEcriture << "Ex_1>OUI_0>NON\n";
    monEcriture << ((int)this->ex) << std::endl;
    monEcriture << "Ey_1>OUI_0>NON\n";
    monEcriture << ((int)this->ey) << std::endl;
    monEcriture << "Ez_1>OUI_0>NON\n";
    monEcriture << ((int)this->ez) << std::endl;
    monEcriture << "Hx_1>OUI_0>NON\n";
    monEcriture << ((int)this->hx) << std::endl;
    monEcriture << "Hy_1>OUI_0>NON\n";
    monEcriture << ((int)this->hy) << std::endl;
    monEcriture << "Hz_1>OUI_0>NON\n";
    monEcriture << ((int)this->hz) << std::endl;
    std::string ecriture(monEcriture.str());
    Ecriture::Ecrire(ecriture);

    //Le point d'application
    Ecriture::Ecrire("Coordonnees_du_point_d_application\n");
    this->pointApplication.ecrire();

    std::ostringstream finEcriture;
    finEcriture << "Valeur_au_centre_de_la_cellule_de_YEE_OUI>1_NON>0:\n";
    finEcriture << ((int)this->valeurAuCentre) << std::endl;
    std::string ecritureFin(finEcriture.str());
    Ecriture::Ecrire(ecritureFin);

}
