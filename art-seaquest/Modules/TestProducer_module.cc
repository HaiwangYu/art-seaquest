//
// Create the Event TestProducer data product.
//

#include "art-seaquest/DataProducts/Event.h"
#include "art-seaquest/DataProducts/Hit.h"
#include "art-seaquest/DataProducts/HitCollection.h"

#include "art/Framework/Core/EDProducer.h"
#include "art/Framework/Core/ModuleMacros.h"
#include "art/Framework/Principal/Event.h"

#include "CLHEP/Random/RanluxEngine.h"
#include "CLHEP/Random/RandFlat.h"

#include <iostream>
#include <vector>
#include <memory>

namespace seaquest {

  class TestProducer : public art::EDProducer {

  public:

    explicit TestProducer(fhicl::ParameterSet const& pset);

    void produce( art::Event& event) override;

  private:

    art::InputTag fitsTag_;

  };

}

seaquest::TestProducer::TestProducer(fhicl::ParameterSet const& pset ):
  fitsTag_(pset.get<std::string>("fitsTag")){
  produces<seaquest::Event>();
  produces<seaquest::HitCollection>();
}

void seaquest::TestProducer::produce( art::Event& event){

	std::cout << "==============================================" << std::endl;
	std::cout << event.id() << std::endl;

	//< Add dummy seaquest::event
  auto event_header = std::make_unique<seaquest::Event>();
  std::cout << *event_header << std::endl;
  event.put( std::move(event_header) );

  CLHEP::RandFlat rand_flat(CLHEP::RanluxEngine());
  //< Add dummy seaquest::HitCollection
  auto hit_collection = std::make_unique<seaquest::HitCollection>();
  for(int i=0; i<1052; ++i){
  	auto hit = std::make_unique<seaquest::Hit>();
  	hit->set_hit_id(i);
  	hit->set_detector_id(static_cast<short>(1000*rand_flat.fire()));
  	hit->set_element_id(static_cast<short>(1000*rand_flat.fire()));
  	hit->set_tdc_time(static_cast<float>(1000*rand_flat.fire()));
  	hit->set_drift_distance(static_cast<float>(1000*rand_flat.fire()));
  	hit->set_in_time(static_cast<bool>(rand_flat.fire()>0.5));
  	hit->set_hodo_mask(static_cast<bool>(rand_flat.fire()>0.5));
  	hit->set_trigger_mask(static_cast<bool>(rand_flat.fire()>0.5));
    std::cout << *hit << std::endl;
  	hit_collection->push_back(*hit);
  }
  event.put( std::move(hit_collection) );

}

DEFINE_ART_MODULE(seaquest::TestProducer)
