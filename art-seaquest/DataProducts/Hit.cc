//
// Some statistics about an event. Not very complete ...
//

#include "Hit.h"

#include <ostream>
#include <limits>

namespace seaquest {

seaquest::Hit::Hit() :
		_hit_id(std::numeric_limits<int>::max()),
		_detector_id(std::numeric_limits<short>::max()),
		_element_id(std::numeric_limits<short>::max()),
		_tdc_time(std::numeric_limits<float>::quiet_NaN()),
		_drift_distance(std::numeric_limits<float>::quiet_NaN()),
		_flag(0) {
}

#ifndef __GCCXML__

std::ostream& operator<<(std::ostream& ost, const seaquest::Hit& hit) {
	ost
	<< " ( Hit Summary: "
	<< " HitID: " << hit.get_hit_id()
	<< " DetectorID: " << hit.get_detector_id()
	<< " TdcTime: " << hit.get_tdc_time()
	<< " DriftDistance: " << hit.get_drift_distance()
	<< " )";
	return ost;
}
}

#endif // __GCCXML__
