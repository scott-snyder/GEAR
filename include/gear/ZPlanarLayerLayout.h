#ifndef GEAR_ZPlanarLayerLayout_H
#define GEAR_ZPlanarLayerLayout_H 1

namespace gear {

/** Abstract description of layers in a Vertex detector. <br>
 *  This assumes a symmetric layout of ladders, arranged in layers equidistant 
 *  to IP.  <br>
 *  The sensitive area is assumed to be inside the ladders but can be positioned independently.
 * 
 * @author R. Lippe, DESY
 * @version $Id: 
 */
class ZPlanarLayerLayout {

public: 
    /// Destructor.
    virtual ~ZPlanarLayerLayout() { /* nop */; }

    /** The total number of layers.
     */
    virtual int getNLayers() const = 0;

    /** The number of ladders in the layer layerIndex - layer indexing starts at 0
     *  for the layer closest to IP.
     */
    virtual int getNLadders(int layerIndex) const = 0;

    /** Azimuthal angle of the (outward pointing) normal of the first ladder.
     *  Phi0==0 corresponds to the first ladder's normal coinciding (if offset==0) with the x-axis.
     *  The layerIndex starts at 0 for the layer closest to IP.
     */
    virtual double getPhi0(int layerIndex) const = 0;

   /** The radiation length in the support structure ladders of layer layerIndex - layer indexing starts at 0
     *  for the layer closest to IP.
     */
    virtual double getLadderRadLength(int layerIndex) const = 0;

    /** The radiation length in sensitive volumes in layer layerIndex - layer indexing starts at 0
     *  for the layer closest to IP.
     */
    virtual double getSensitiveRadLength(int layerIndex) const = 0;

    /** The distance of ladders in layer layerIndex from the IP - layer indexing starts at 0
     *  for the layer closest to IP.
     */
    virtual double getLadderDistance(int layerIndex) const = 0;

    /** The thickness in mm of the ladders in layerIndex - layer indexing starting at 0
     *  for the layer closest to IP.
     */
    virtual double getLadderThickness(int layerIndex) const = 0;

    /** The offset of the ladder in mm defines the shift of the ladder in the direction of increasing phi
     *  perpendicular to the ladder's normal. For example if the first ladder is at phi0==0 then the offset 
     *  defines an upward shift of the ladder (parallel to the y-axis).  
     *  Layer indexing starts at 0 for the layer closest to IP.
     *  @see getPhi0
     *  @see getSensitiveOffset
     */
    virtual double getLadderOffset(int layerIndex) const = 0;

    /** The width of the ladder in layer in mm for ladders in layer layerIndex -
     *  layer indexing starting at 0 from the layer closest to IP.
     */
    virtual double getLadderWidth(int layerIndex) const = 0;

    /** The (half) length of the ladder in z direction in mm for ladders in layer layerIndex -
     *  layer indexing starting at 0 from the layer closest to IP. Note: for historic reasons
     *  this is typically used to describe the half of the ladder in positive z, so it is the 
     *  half length really.
     */
    virtual double getLadderLength(int layerIndex) const = 0;

    /** The distance of sensitive area in ladders in layer layerIndex from the IP.
     */
    virtual double getSensitiveDistance(int layerIndex) const = 0;

    /** The thickness in mm of the sensitive area in ladders in layer layerIndex.
     */
    virtual double getSensitiveThickness(int layerIndex) const = 0;

    /** Same as getLadderOffset() except for the sensitive part of the ladder.
     * @see getLadderOffset
     */
    virtual double getSensitiveOffset(int layerIndex) const = 0;

    /** The width of the sensitive area in ladders in layer layerIndex in mm.
     */
    virtual double getSensitiveWidth(int layerIndex) const = 0;

    /** The length of the sensitive area in ladders in z direction in mm for ladders in layer layerIndex.
     */
    virtual double getSensitiveLength(int layerIndex) const = 0;
}; // class
} // namespace gear
#endif /* ifndef GEAR_ZPlanarLayerLayout_H */
