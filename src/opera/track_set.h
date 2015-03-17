#ifndef TOOLS_TRACK_SET_H_
#define TOOLS_TRACK_SET_H_

#include <vector>
#include <cassert>

#include "track.h"

namespace tools{

class TrackSet2D{
public:
  typedef std::vector<Track2D*> TrackSet;
  typedef std::vector<Point2D*> TrackSetPosition;
  struct TrackSetState{
    std::vector<Track2D::TrackState> track_set_state;
  };
  class Iterator{
  public:
    Iterator(TrackSet2D* track_set);
    ~Iterator();
    bool Valid() const;
    void Next();
    void Value(TrackSetState& track_set_state);
    void Reset();
  private:
    typedef std::vector<Track2D::Iterator> TrackSetIterator;
    int count_invalid_track_;
    TrackSet2D* track_set_;
    TrackSet* rep_track_set_;
    TrackSetIterator* track_set_iter_;

    void PositionChange(const TrackSetPosition& pos, TrackSetState& track_set_state);
  };

  TrackSet2D(TrackSet* track_set,
      TrackSetPosition* track_set_init_pos, 
      float interval)
    :rep_track_set_(track_set), 
    interval_(interval),
    track_set_init_pos_(track_set_init_pos){
      assert(track_set->size() == track_set_init_pos->size());
    }
  long long GetSumTick() const;
  double GetSumLength() const;
private:
  TrackSet* rep_track_set_;
  TrackSetPosition* track_set_init_pos_;
  float interval_;

  const Point2D& GetInitPosition(unsigned long long id) const;

  friend class Iterator;
};

} //namespace tools

#endif //TOOLS_TRACK_SET_H_