#ifndef DEF_SCHEDULEHANDLER
#define DEF_SCHEDULEHANDLER

#include <SFML/Graphics.hpp>

class ScheduleHandler {
  public:
    ScheduleHandler();
    void add(function<int(void)> f, int delay);
    void flush();
    ~ScheduleHandler();

  private:
    list<function<int(void)>>[] functions;
    int position;
};

#endif
