/* 
 * File:   SurfacePrelevement.h
 * Author: camille
 *
 * Created on February 24, 2013, 2:26 PM
 */

#ifndef SURFACEPRELEVEMENT_H
#define	SURFACEPRELEVEMENT_H

class SurfacePrelevement {
public:
    SurfacePrelevement();
    int getCompx_Prel() const {
        return compx_Prel;
    }

    void setCompx_Prel(int compx_Prel) {
        this->compx_Prel = compx_Prel;
    }

    int getCompy_Prel() const {
        return compy_Prel;
    }

    void setCompy_Prel(int compy_Prel) {
        this->compy_Prel = compy_Prel;
    }

    int getCompz_Prel() const {
        return compz_Prel;
    }

    void setCompz_Prel(int compz_Prel) {
        this->compz_Prel = compz_Prel;
    }

    int getMx_surf_inf() const {
        return mx_surf_inf;
    }

    void setMx_surf_inf(int mx_surfHuy_inf) {
        this->mx_surf_inf = mx_surfHuy_inf;
    }

    int getMx_surf_sup() const {
        return mx_surf_sup;
    }

    void setMx_surf_sup(int mx_surfHuy_sup) {
        this->mx_surf_sup = mx_surfHuy_sup;
    }

    int getMy_surf_inf() const {
        return my_surf_inf;
    }

    void setMy_surf_inf(int my_surfHuy_inf) {
        this->my_surf_inf = my_surfHuy_inf;
    }

    int getMy_surf_sup() const {
        return my_surf_sup;
    }

    void setMy_surf_sup(int my_surfHuy_sup) {
        this->my_surf_sup = my_surfHuy_sup;
    }

    int getMz_surf_inf() const {
        return mz_surf_inf;
    }

    void setMz_surf_inf(int mz_surfHuy_inf) {
        this->mz_surf_inf = mz_surfHuy_inf;
    }

    int getMz_surf_sup() const {
        return mz_surf_sup;
    }

    void setMz_surf_sup(int mz_surfHuy_sup) {
        this->mz_surf_sup = mz_surfHuy_sup;
    }

    int getNb_surfaces() const {
        return nb_surfaces;
    }

    void setNb_surfaces(int nb_surfaces) {
        this->nb_surfaces = nb_surfaces;
    }

    int getNbx_surfPrel() const {
        return nbx_surfPrel;
    }

    void setNbx_surfPrel(int nbx_surfPrel) {
        this->nbx_surfPrel = nbx_surfPrel;
    }

    int getNby_surfPrel() const {
        return nby_surfPrel;
    }

    void setNby_surfPrel(int nby_surfPrel) {
        this->nby_surfPrel = nby_surfPrel;
    }

    int getNbz_surfPrel() const {
        return nbz_surfPrel;
    }

    void setNbz_surfPrel(int nbz_surfPrel) {
        this->nbz_surfPrel = nbz_surfPrel;
    }

    int getSurf_prel_inside_outside() const {
        return surf_prel_inside_outside;
    }

    void setSurf_prel_inside_outside(int surf_prel_inside_outside) {
        this->surf_prel_inside_outside = surf_prel_inside_outside;
    }

    int getTyp_surf_prelev() const {
        return typ_surf_prelev;
    }

    void setTyp_surf_prelev(int typ_surf_prelev) {
        this->typ_surf_prelev = typ_surf_prelev;
    }

private:
    //Général
    int typ_surf_prelev;
    //Pour les deux
    int nb_surfaces;
    int mx_surf_inf;
    int my_surf_inf;
    int mz_surf_inf;
    int mx_surf_sup;
    int my_surf_sup;
    int mz_surf_sup;
    int compx_Prel;
    int compy_Prel;
    int compz_Prel;
    int nbx_surfPrel;
    int nby_surfPrel;
    int nbz_surfPrel;
    //DG
    int surf_prel_inside_outside;
};

#endif	/* SURFACEPRELEVEMENT_H */

