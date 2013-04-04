/* 
 * File:   Ecriture.h
 * Author: camille
 *
 * Created on March 5, 2013, 8:37 PM
 */

#ifndef ECRITURE_H
#define	ECRITURE_H

#include <string>
#include <stdio.h>

class Ecriture {
public:
    Ecriture();
    Ecriture(const Ecriture& orig);
    virtual ~Ecriture();
    
    std::string GetNomFichier() const {
        return Ecriture::nomFichier;
    }

    static void SetNomFichier(std::string nomFichier) {
        if(nomFichier == Ecriture::nomFichier)return;
        
        Ecriture::nomFichier = nomFichier;
        if(Ecriture::opened)fclose(fp);
        
        const char* nf = Ecriture::nomFichier.c_str();
        
        if ((Ecriture::fp = fopen(nf, "w+")) != NULL) {
            Ecriture::opened = true;
        }
    }
    
    static void Ecrire(std::string s){
        const char* c = s.c_str();
        fputs(c, Ecriture::fp);
    }
    
private:
    static FILE *fp;
    static std::string nomFichier;
    static bool opened;
};
#endif	/* ECRITURE_H */

