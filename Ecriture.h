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
#include <sstream>
#include <QSettings>
#include <QCoreApplication>

class Ecriture {
public:

    std::string GetNomFichier() const {
        return Ecriture::nomFichier;
    }

    static void SetNomFichier(std::string extension) {

        std::ostringstream nom;
        nom << "DATA" << Ecriture::numstru << extension;
        std::string nomFichier = nom.str();

        if(nomFichier == Ecriture::nomFichier)return;
        
        Ecriture::nomFichier = nomFichier;
        if(Ecriture::opened)fclose(fp);


        QSettings settings("INSAProj", "EditSimuIETR");
        std::string path=settings.value("PathSimu",QCoreApplication::applicationDirPath()).toString().toStdString();

        std::string nf = path + "/" + Ecriture::nomFichier;
        
        if ((Ecriture::fp = fopen(nf.c_str(), "w+")) != NULL) {
            Ecriture::opened = true;
        }
    }
    
    static void Ecrire(std::string s){
        const char* c = s.c_str();
        fputs(c, Ecriture::fp);
    }

    static void setNumStru(int num){
        Ecriture::numstru = num;
    }

private:
    static FILE *fp;
    static std::string nomFichier;
    static bool opened;
    static int numstru;
};
#endif	/* ECRITURE_H */

