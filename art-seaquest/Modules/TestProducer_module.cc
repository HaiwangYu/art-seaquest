//
// Create the Event TestProducer data product.
//

#include "art-seaquest/DataProducts/Event.h"
#include "art-seaquest/DataProducts/Hit.h"
#include "art-seaquest/DataProducts/HitCollection.h"

#include "art/Framework/Core/EDProducer.h"
#include "art/Framework/Core/ModuleMacros.h"
#include "art/Framework/Principal/Event.h"

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

  //< Add dummy seaquest::HitCollection
  auto hit_collection = std::make_unique<seaquest::HitCollection>();
  for(int i=0; i<1052; ++i){
  	auto hit = std::make_unique<seaquest::Hit>();
  	hit->set_hit_id(i);
    std::cout << *hit << std::endl;
  	hit_collection->push_back(*hit);
  }
  event.put( std::move(hit_collection) );

}

DEFINE_ART_MODULE(seaquest::TestProducer)
