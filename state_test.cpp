#include "state.h"

#include <cassert>
#include <iostream>
#include <vector>

namespace tools{
namespace test{
class Test{
public:
  void RunAllTest(){
    TestRadarFunction();
  }
  void TestRadarFunction(){
    std::vector<State*> states;
    std::vector<State*> states_init;
    std::vector<Event*> events;

    states_init.push_back(StateRadarSelected::Instance());
    states_init.push_back(StateRadarCentered::Instance());
    states_init.push_back(StateTrackLineSelected::Instance());
    states_init.push_back(StateTrackLineStarted::Instance());
    states_init.push_back(StateTrackCircleSelected::Instance());
    states_init.push_back(StateTrackCircleStarted::Instance());
    states_init.push_back(StateTrackCircleCentered::Instance());
    states_init.push_back(StateTrackCircleSided::Instance());
    states_init.push_back(StateTrackEclipseSelected::Instance());
    states_init.push_back(StateTrackEclipseStarted::Instance());
    states_init.push_back(StateTrackEclipseCentered::Instance());
    states_init.push_back(StateTrackEclipseEnded::Instance());
    states_init.push_back(StateTrackEclipseSided::Instance());
    states_init.push_back(StateContralStarted::Instance());
    states_init.push_back(StateContralSteped::Instance());
    states_init.push_back(StateContralPaused::Instance());

    //states_init.push_back(StateRadarSelected::Instance());
    states.push_back(StateRadarSelected::Instance());
    states.push_back(StateRadarSelected::Instance());
    states.push_back(StateRadarCentered::Instance());
    states.push_back(StateRadarSelected::Instance());
    states.push_back(StateRadarSelected::Instance());
    states.push_back(StateRadarSelected::Instance());
    states.push_back(StateTrackLineSelected::Instance());
    states.push_back(StateTrackCircleSelected::Instance());
    states.push_back(StateTrackEclipseSelected::Instance());
    states.push_back(StateRadarSelected::Instance());
    states.push_back(StateRadarSelected::Instance());
    states.push_back(StateRadarSelected::Instance());
    states.push_back(StateRadarSelected::Instance());
    states.push_back(StateRadarSelected::Instance());
    states.push_back(StateRadarSelected::Instance());

    //states_init.push_back(StateRadarCentered::Instance());
    states.push_back(StateRadarCentered::Instance());
    states.push_back(StateRadarCentered::Instance());
    states.push_back(StateRadarSelected::Instance());
    states.push_back(StateRadarCentered::Instance());
    states.push_back(StateRadarCentered::Instance());
    states.push_back(StateRadarCentered::Instance());
    states.push_back(StateTrackLineSelected::Instance());
    states.push_back(StateTrackCircleSelected::Instance());
    states.push_back(StateTrackEclipseSelected::Instance());
    states.push_back(StateRadarCentered::Instance());
    states.push_back(StateRadarCentered::Instance());
    states.push_back(StateRadarCentered::Instance());
    states.push_back(StateRadarCentered::Instance());
    states.push_back(StateRadarCentered::Instance());
    states.push_back(StateRadarCentered::Instance());

    //states_init.push_back(StateTrackLineSelected::Instance());
    states.push_back(StateTrackLineSelected::Instance());
    states.push_back(StateTrackLineSelected::Instance());
    states.push_back(StateTrackLineStarted::Instance());
    states.push_back(StateTrackLineSelected::Instance());
    states.push_back(StateTrackLineSelected::Instance());
    states.push_back(StateTrackLineSelected::Instance());
    states.push_back(StateTrackLineSelected::Instance());
    states.push_back(StateTrackCircleSelected::Instance());
    states.push_back(StateTrackEclipseSelected::Instance());
    states.push_back(StateTrackLineSelected::Instance());
    states.push_back(StateTrackLineSelected::Instance());
    states.push_back(StateTrackLineSelected::Instance());
    states.push_back(StateTrackLineSelected::Instance());
    states.push_back(StateTrackLineSelected::Instance());
    states.push_back(StateTrackLineSelected::Instance());

    //states_init.push_back(Statetracklinestarted::Instance());
    states.push_back(StateTrackLineStarted::Instance());
    states.push_back(StateTrackLineStarted::Instance());
    states.push_back(StateTrackLineSelected::Instance());
    states.push_back(StateTrackLineStarted::Instance());
    states.push_back(StateTrackLineStarted::Instance());
    states.push_back(StateTrackLineStarted::Instance());
    

    events.push_back(EventPressLeft::Instance());
    events.push_back(EventPressRight::Instance());
    events.push_back(EventReleaseLeft::Instance());
    events.push_back(EventReleaseRight::Instance());
    events.push_back(EventMouseDoubleClick::Instance());
    events.push_back(EventMouseMove::Instance());
    events.push_back(EventButtonLine::Instance());
    events.push_back(EventButtonCircle::Instance());
    events.push_back(EventButtonEclipse::Instance());
  
    events.push_back(EventWheel::Instance());
    events.push_back(EventButtonStart::Instance());
    events.push_back(EventButtonStep::Instance());
    events.push_back(EventButtonPause::Instance());
    events.push_back(EventButtonStop::Instance());
    events.push_back(EventButtonAnalysis::Instance());
    
    int count = events.size();
    for(int i=0; i!=16; ++i){
    events.push_back(EventPressLeft::Instance());
    events.push_back(EventPressRight::Instance());
    events.push_back(EventReleaseLeft::Instance());
    events.push_back(EventReleaseRight::Instance());
    events.push_back(EventMouseDoubleClick::Instance());
    events.push_back(EventMouseMove::Instance());
    events.push_back(EventButtonLine::Instance());
    events.push_back(EventButtonCircle::Instance());
    events.push_back(EventButtonEclipse::Instance());
  
    events.push_back(EventWheel::Instance());
    events.push_back(EventButtonStart::Instance());
    events.push_back(EventButtonStep::Instance());
    events.push_back(EventButtonPause::Instance());
    events.push_back(EventButtonStop::Instance());
    events.push_back(EventButtonAnalysis::Instance());
    }
    
    Internal(&states_init,
        &events, &states, count);
  }

  void Internal(std::vector<State*> *state_init, 
      std::vector<Event*>* events,
      std::vector<State*> *states,
      int count){
      ToolsState tools(0);
      for(int i=0; i!=states->size(); ++i){
        tools.set_state((*state_init)[i/count]);
        tools.Execute((*events)[i]);
        assert(tools.state() == (*states)[i]);
      }
  }
};

} //namespace test
} //namespace tools

int main(){
  tools::test::Test().RunAllTest();
  return 0;
}