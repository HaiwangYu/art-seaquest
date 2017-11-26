#ifndef SQ_DataProducts_Event_h
#define SQ_DataProducts_Event_h

//
// Some event summary statistics.  Very incomplete.
//

#include <iosfwd>
#include <iostream>
#include <limits>

namespace seaquest {

  class Event {

  public:

  	enum TriggerMask {
  		NIM1 = 0,
  		NIM2 = 1,
  		NIM3 = 2,
  		NIM4 = 3,
  		NIM5 = 4,
  		MATRIX1 = 5,
  		MATRIX2 = 6,
  		MATRIX3 = 7,
  		MATRIX4 = 8,
  		MATRIX5 = 9
  	};

    Event();

#ifndef __GCCXML__
#endif  // __GCCXML__


  	void identify(std::ostream& os = std::cout) const;

  	int get_run_id() const {return _run_id;}
  	void set_run_id(const int a) {_run_id = a;}

  	int get_spill_id() const {return _spill_id;}
  	void set_spill_id(const int a) {_spill_id = a;}

  	int get_event_id() const {return _event_id;}
  	void set_event_id(const int a) {_event_id = a;}

  	int get_coda_event_id() const {return _coda_event_id;}
  	void set_coda_event_id(const int a) {_coda_event_id = a;}


  	int get_data_quality() const {return _data_quality;}
  	void set_data_quality(const int a) {_data_quality = a;}

  	int get_vme_time() const {return _vme_time;}
  	void set_vme_time(const int a) {_vme_time = a;}

  	bool get_trigger(const seaquest::Event::TriggerMask i) const {return (_trigger&(1<<i)) > 0 ;}
  	void set_trigger(const seaquest::Event::TriggerMask i, const bool a) {a ? (_trigger |= (1<<i)) : (_trigger &= ~(1<<i)) ;}

  	int get_raw_matrix(const unsigned short i) const {
  		if(i<5) return _raw_matrix[i];
  		return std::numeric_limits<int>::max();
  	}
  	void set_raw_matrix(const unsigned short i, const bool a) {
  		if(i<5) _raw_matrix[i] = a;
  		else std::cout<<"SQEvent_v1::set_raw_matrix: i>=5";
  	}

  	int get_after_inh_matrix(const unsigned short i) const {
  		if(i<5) return _after_inh_matrix[i];
  		return std::numeric_limits<int>::max();
  	}
  	void set_after_inh_matrix(const unsigned short i, const bool a) {
  		if(i<5) _after_inh_matrix[i] = a;
  		else std::cout<<"SQEvent_v1::set_after_inh_matrix: i>=5";
  	}


  private:
  	int _run_id;
  	int _spill_id;
  	int _event_id;
  	int _coda_event_id;

  	unsigned short _trigger; //< NIM[1-5], MATRIX[1-5]

  	int _raw_matrix[5];

  	int _after_inh_matrix[5];

  	int _data_quality;

  	int _vme_time;
  };

#ifndef __GCCXML__
  std::ostream& operator<<(std::ostream& ost, const seaquest::Event& event );
#endif  // __GCCXML__

}
#endif  /* SQ_DataProducts_Event_h */
