// -*- C++ -*-
#ifndef GEAR_CALORIMETERPARAMETERS_H
#define GEAR_CALORIMETERPARAMETERS_H 1

#include <vector>

#include "gear/GearParameters.h"

namespace gear {

class LayerLayout;

/** Proposal for an abstract interface that defines geometry properties of
 * a typical sampling calorimeter as needed for reconstruction. <br>
 * 
 * @author F. Gaede, DESY
 * @version $Id$
 */

class CalorimeterParameters : virtual public GearParameters {

public: 
    /// Destructor.
    virtual ~CalorimeterParameters() { /* nop */; }

    // Static constants (enums) for the type of the layout

    static const int BARREL = 1 ;
    static const int ENDCAP = 2 ;
    /** The layer layout in the calorimeter*/
    virtual const LayerLayout & getLayerLayout() const = 0;

    /** The type of the calorimeter layout: CalorimeterParameters.BARREL or
     *  CalorimeterParameters.ENDCAP.
     */
    virtual int getLayoutType() const = 0;

    /** Extent of the calorimeter in the r-z-plane  [ rmin, rmax, zmin, zmax ] in mm.
     */
    virtual const std::vector<double>  & getExtent() const = 0;

    /** The order of the rotational symmetry <br>
     *   8 for an octagonal barrel calorimeter<br>
     *   2 for an endcap calorimeter<br>
     *   1 for a standalone prototype<br>
     *   0 for an idealized cylindrical calorimeter.
     */
    virtual int getSymmetryOrder() const = 0;

    /** The azimuthal angle of the first module if symmetryOrder > 0.
     */
    virtual double getPhi0() const = 0;
}; // class
} // namespace gear
#endif /* ifndef GEAR_CALORIMETERPARAMETERS_H */
