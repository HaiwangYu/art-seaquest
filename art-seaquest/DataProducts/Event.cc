//
// Some statistics about an event. Not very complete ...
//

#include "Event.h"

#include <ostream>
#include <limits>

namespace seaquest {

Event::Event():
		_run_id(std::numeric_limits<int>::max()),
		_spill_id(std::numeric_limits<int>::max()),
		_event_id(std::numeric_limits<int>::max()),
		_coda_event_id(std::numeric_limits<int>::max()),
		_trigger(0),
		_data_quality(std::numeric_limits<int>::max()),
		_vme_time(std::numeric_limits<int>::max())
		{
			for(int i=0;i<5;++i) _raw_matrix[i] = 0;
			for(int i=0;i<5;++i) _after_inh_matrix[i] = 0;
		}

#ifndef __GCCXML__

std::ostream& operator<<(std::ostream& ost,
                         const seaquest::Event& event){
  ost << std::endl << " ----------- seaquest::Event: -----------" << std::endl;
  ost
  << " runID: " << event.get_run_id()
  << " spillID: " << event.get_spill_id()
  << " eventID: " << event.get_event_id()
  << " codaEventID: " << event.get_coda_event_id()
  << std::endl;
  for(int i = seaquest::Event::NIM1; i<=seaquest::Event::NIM5; ++i) {
	  ost <<"NIM"<<i<<": " << event.get_trigger(static_cast<seaquest::Event::TriggerMask>(i)) << "; ";
  }
  ost << std::endl;
  for(int i = seaquest::Event::MATRIX1; i<=seaquest::Event::MATRIX5; ++i){
	  ost <<"MATRIX"<<i<<": " << event.get_trigger(static_cast<seaquest::Event::TriggerMask>(i)) << "; ";
  }
  ost << std::endl;
  return ost;
}
}

#endif // __GCCXML__
