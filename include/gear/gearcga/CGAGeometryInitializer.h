#ifndef GEAR_CGAGEOMETRYINITIALIZER_H
#define GEAR_CGAGEOMETRYINITIALIZER_H 1

#include <string>
#include <vector>

#include "gear/GEAR.h"

namespace gear {

/** CGA Geometry Initializer class
 * @author G. Musat, Ecole Polytechnique
 * @version $Id$
 */
class CGAGeometryInitializer {

public: 
    /// Destructor.
    virtual ~CGAGeometryInitializer() { /* nop */; }

    static CGAGeometryInitializer * GetCGAGeometryInitializer(
	std::string steeringFile, std::string model,
        std::string setup, std::string host, std::string user,
        std::string password);

private:

    CGAGeometryInitializer(std::string steeringFile, std::string model,
	std::string setup, std::string host, std::string user,
	std::string password);

    static CGAGeometryInitializer * theInitializer;
}; // class
} // namespace gear
#endif /* ifndef GEAR_CGAGEOMETRYINITIALIZER_H */
