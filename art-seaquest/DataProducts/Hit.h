#ifndef SQ_DataProducts_Hit_h
#define SQ_DataProducts_Hit_h

//
// Some event summary statistics.  Very incomplete.
//

#include <iosfwd>

namespace seaquest {

  class Hit {

  public:

    enum HitQuality
    {
        InTime = 1<<0,
        HodoMask = 1<<1,
        TriggerMask = 1<<2
    };

    Hit();

#ifndef __GCCXML__
#endif  // __GCCXML__
    int          get_hit_id() const                        {return _hit_id;}
    void         set_hit_id(const int a)                   {_hit_id = a;}

    short        get_detector_id() const                   {return _detector_id;}
    void         set_detector_id(const short a)            {_detector_id = a;}

    short        get_element_id() const                    {return _element_id;}
    void         set_element_id(const short id)            {_element_id = id;}

    float        get_tdc_time() const                      {return _tdc_time;}
    void         set_tdc_time(const float a)               {_tdc_time=a;}

    float        get_drift_distance() const                {return _drift_distance;}
    void         set_drift_distance(const float a)         {_drift_distance=a;}

    float        get_pos() const                           {return _pos;}
    void         set_pos(const float a)                    {_pos=a;}

    bool         is_in_time() const                        {return (_flag&(seaquest::Hit::InTime)) != 0;}
    void         set_in_time(const bool a)                 {a? (_flag |= seaquest::Hit::InTime) : (_flag &= ~seaquest::Hit::InTime);}

    bool         is_hodo_mask() const                      {return (_flag&(seaquest::Hit::HodoMask)) != 0;}
    void         set_hodo_mask(const bool a)               {a? (_flag |= seaquest::Hit::HodoMask) : (_flag &= ~seaquest::Hit::HodoMask);}

    bool         is_trigger_mask() const                   {return (_flag&(seaquest::Hit::TriggerMask)) != 0;}
    void         set_trigger_mask(const bool a)            {a? (_flag |= seaquest::Hit::TriggerMask) : (_flag &= ~seaquest::Hit::TriggerMask);}

  private:
    int _hit_id;                   //< unique identifier within container
    short _detector_id;            //<
    short _element_id;             //< element id

    float _tdc_time;               //<
    float _drift_distance;         //<
    float _pos;                    //<

    unsigned short _flag;           //<
  };

#ifndef __GCCXML__
  std::ostream& operator<<(std::ostream& ost,
                           const seaquest::Hit& hit );
#endif  // __GCCXML__

}
#endif  /* SQ_DataProducts_Hit_h */
