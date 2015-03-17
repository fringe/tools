#ifndef TOOLS_WEBKIT_WEBKIT_H_ 
#define TOOLS_WEBKIT_WEBKIT_H_ 

#include "webkit/javascript.h"

namespace tools {

class Webkit {
 public:
  static Webkit* Instance();

  Webkit& execute(JavaScript& js);
  inline void set_page(void(*page)(const char*)) { page_ = page; }
  
 private:
  Webkit(){}
  Webkit(const Webkit&);
  Webkit& operator=(const Webkit&);

  static Webkit* webkit_;
  void (*page_)(const char*);
};
/*
struct JSRadar{
  long long id;
  int type;
  double center_x;
  double center_y;
  double radius;
};

class JSDeleteRadar:public JavaScript{
public:
    JSDeleteRadar(long long id):id_(id){}
    virtual std::string execute();
private:
    long long id_;
};

class JSClearRadar:public JavaScript{
public:
    virtual std::string execute();
private:
};

class JSCreateRadarState : public JavaScript{
public:
  JSCreateRadarState(long long radar_id,
    long long object_id)
    :radar_id_(radar_id), object_id_(object_id){}
  virtual std::string execute();
private:
    long long radar_id_;
    long long object_id_;
};

class JSUpdateRadarState:public JavaScript{
public:
    JSUpdateRadarState(long long radar_id,
                       long long object_id)
        :radar_id_(radar_id), object_id_(object_id){}
    virtual std::string execute();
private:
    long long radar_id_;
    long long object_id_;
};

class JSDeleteRadarState:public JavaScript{
public:
    JSDeleteRadarState(long long radar_id,
                       long long object_id)
        :radar_id_(radar_id), object_id_(object_id){}
    virtual std::string execute();
private:
    long long radar_id_;
    long long object_id_;
};

class JSClearRadarState:public JavaScript{
public:
    JSClearRadarState(long long radar_id):radar_id_(radar_id){}
    virtual std::string execute();
private:
    long long radar_id_;
};

class JSUpdateLine:public JavaScript{
public:
  JSUpdateLine(JSLine* line) : line_ (line){}
  virtual std::string execute();
private:
  JSLine* line_;
};

class JSDeleteLine : public JavaScript{
public:
  JSDeleteLine(long long id) : id_(id){}
  virtual std::string execute();
private:
  long long id_;
};

class JSClearLine : public JavaScript{
public:
  virtual std::string execute();
};

struct JSCircle{
  long long id;
  double start_x;
  double start_y;
  double radius_x;
  double radius_y;
  double angle;
};


class JSCreateCircle:public JavaScript{
public:
  JSCreateCircle(JSCircle* circle) : circle_(circle){}
  virtual std::string execute();
private:
  JSCircle* circle_;
};

class JSUpdateCircle:public JavaScript{
public:
  JSUpdateCircle(JSCircle* circle) : circle_(circle){}
  virtual std::string execute();
private:
  JSCircle* circle_;
};

class JSDeleteCircle : public JavaScript{
public:
  JSDeleteCircle(long long id) : id_(id){}
  virtual std::string execute();
private:
  long long id_;
};

class JSClearCircle : public JavaScript{
public:
  virtual std::string execute();
};

struct Eclipse{
  long long id;
  double start_x;
  double start_y;
  double radius_x;
  double radius_y;
  double end_x;
  double end_y;
  double angle;
};

class JSCreateEclipse:public JavaScript{
public:
  JSCreateEclipse(Eclipse* eclipse) : eclipse_(eclipse){}
  virtual std::string execute();
private:
  Eclipse* eclipse_;
};

class JSUpdateEclipse:public JavaScript{
public:
  JSUpdateEclipse(Eclipse* eclipse) : eclipse_(eclipse){}
  virtual std::string execute();
private:
  Eclipse* eclipse_;
};

class JSDeleteEclipse : public JavaScript{
public:
  JSDeleteEclipse(long long id) : id_(id){}
  virtual std::string execute();
private:
  long long id_;
};

class JSClearEclipse : public JavaScript{
public:
  virtual std::string execute();
};

class JSSetZoom : public JavaScript{
public:
  JSSetZoom(int zoom):zoom_(zoom){}
  virtual std::string execute();
private:
  int zoom_;
};

class JSSetCenter : public JavaScript{
public:
  JSSetCenter(double longitude, double latitude)
    :longitude_(longitude), latitude_(latitude){}
  virtual std::string execute();
private:
  double longitude_;
  double latitude_;
};
*/
} //namespace tools

#endif // TOOLS_WEBKIT_WEBKIT_H
