/* 
 * File:   CageExcitation.h
 * Author: camille
 *
 * Created on February 24, 2013, 1:20 PM
 */

#ifndef CAGEEXCITATION_H
#define	CAGEEXCITATION_H

class CageExcitation {
public:
    CageExcitation();

    int getInside_outside() const {
        return inside_outside;
    }

    void setInside_outside(int inside_outside) {
        this->inside_outside = inside_outside;
    }

    float getMod_ampl_Exci() const {
        return mod_ampl_Exci;
    }

    void setMod_ampl_Exci(float mod_ampl_Exci) {
        this->mod_ampl_Exci = mod_ampl_Exci;
    }

    float getMod_ret_Exci() const {
        return mod_ret_Exci;
    }

    void setMod_ret_Exci(float mod_ret_Exci) {
        this->mod_ret_Exci = mod_ret_Exci;
    }

    int getMode_excitation() const {
        return mode_excitation;
    }

    void setMode_excitation(int mode_excitation) {
        this->mode_excitation = mode_excitation;
    }

    int getMx_inc_inf() const {
        return mx_inc_inf;
    }

    void setMx_inc_inf(int mx_inc_inf) {
        this->mx_inc_inf = mx_inc_inf;
    }

    int getMx_inc_sup() const {
        return mx_inc_sup;
    }

    void setMx_inc_sup(int mx_inc_sup) {
        this->mx_inc_sup = mx_inc_sup;
    }

    int getMy_inc_inf() const {
        return my_inc_inf;
    }

    void setMy_inc_inf(int my_inc_inf) {
        this->my_inc_inf = my_inc_inf;
    }

    int getMy_inc_sup() const {
        return my_inc_sup;
    }

    void setMy_inc_sup(int my_inc_sup) {
        this->my_inc_sup = my_inc_sup;
    }

    int getMz_inc_inf() const {
        return mz_inc_inf;
    }

    void setMz_inc_inf(int mz_inc_inf) {
        this->mz_inc_inf = mz_inc_inf;
    }

    int getMz_inc_sup() const {
        return mz_inc_sup;
    }

    void setMz_inc_sup(int mz_inc_sup) {
        this->mz_inc_sup = mz_inc_sup;
    }

    int getNb_faces_excitation() const {
        return nb_faces_excitation;
    }

    void setNb_faces_excitation(int nb_faces_excitation) {
        this->nb_faces_excitation = nb_faces_excitation;
    }

    int getNbx_inc_prel() const {
        return nbx_inc_prel;
    }

    void setNbx_inc_prel(int nbx_inc_prel) {
        this->nbx_inc_prel = nbx_inc_prel;
    }

    int getNby_inc_prel() const {
        return nby_inc_prel;
    }

    void setNby_inc_prel(int nby_inc_prel) {
        this->nby_inc_prel = nby_inc_prel;
    }

    int getNbz_inc_prel() const {
        return nbz_inc_prel;
    }

    void setNbz_inc_prel(int nbz_inc_prel) {
        this->nbz_inc_prel = nbz_inc_prel;
    }

    float getPhi0deg() const {
        return phi0deg;
    }

    void setPhi0deg(float phi0deg) {
        this->phi0deg = phi0deg;
    }

    float getPsi0deg() const {
        return psi0deg;
    }

    void setPsi0deg(float psi0deg) {
        this->psi0deg = psi0deg;
    }

    int getSens_propa() const {
        return sens_propa;
    }

    void setSens_propa(int sens_propa) {
        this->sens_propa = sens_propa;
    }

    float getTheta0deg() const {
        return theta0deg;
    }

    void setTheta0deg(float theta0deg) {
        this->theta0deg = theta0deg;
    }

    int getType_excitation() const {
        return type_excitation;
    }

    void setType_excitation(int type_excitation) {
        this->type_excitation = type_excitation;
    }

    int getX_inc0() const {
        return x_inc0;
    }

    void setX_inc0(int x_inc0) {
        this->x_inc0 = x_inc0;
    }

    int getY_inc0() const {
        return y_inc0;
    }

    void setY_inc0(int y_inc0) {
        this->y_inc0 = y_inc0;
    }

    int getZ_inc0() const {
        return z_inc0;
    }

    void setZ_inc0(int z_inc0) {
        this->z_inc0 = z_inc0;
    }

    int getZexc() const {
        return zexc;
    }

    void setZexc(int zexc) {
        this->zexc = zexc;
    }


private:
    int inside_outside;
    int nb_faces_excitation;
    int type_excitation;
    int my_inc_inf;
    int mx_inc_inf;
    int mz_inc_inf;
    int my_inc_sup;
    int mx_inc_sup;
    int mz_inc_sup;
    int y_inc0;
    int x_inc0;
    int z_inc0;
    float theta0deg;
    float phi0deg;
    float psi0deg;
    
    int mode_excitation;
    int zexc;
    int sens_propa;
    
    float mod_ampl_Exci;
    float mod_ret_Exci;
    
    int nbx_inc_prel;
    int nby_inc_prel;
    int nbz_inc_prel;
};

#endif	/* CAGEEXCITATION_H */

