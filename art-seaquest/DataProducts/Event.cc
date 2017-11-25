//
// Some statistics about an event. Not very complete ...
//

#include "Event.h"

#include <ostream>
#include <limits>

namespace seaquest {

Event::Event():
  _event_id(std::numeric_limits<int>::max()) {
}

#ifndef __GCCXML__

std::ostream& operator<<(std::ostream& ost,
                         const seaquest::Event& event){
  ost << " ( Event Summary: "
      << " EventID: " << event.get_event_id()
			<< " )";

  return ost;
}
}

#endif // __GCCXML__
